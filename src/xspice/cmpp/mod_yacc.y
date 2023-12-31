%{

/*============================================================================
FILE  mod_yacc.y

MEMBER OF process cmpp

Copyright 1991
Georgia Tech Research Corporation
Atlanta, Georgia 30332
All Rights Reserved

PROJECT A-8503

AUTHORS

    9/12/91  Steve Tynor

MODIFICATIONS

    <date> <person name> <nature of modifications>
  20050420 Steven Borley Renamed strcmpi() to local_strcmpi() to avoid
                         clash with strcmpi() in a windows header file.

SUMMARY

    This file contains a BNF specification of the translation of
    cfunc.mod files to cfunc.c files, together with various support
    functions.

INTERFACES

    mod_yyparse() -    Function 'yyparse()' is generated automatically
                       by UNIX 'yacc' utility.  All yy* global names
                       are converted to mod_yy* by #define.

REFERENCED FILES

    mod_lex.l

============================================================================*/


#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "mod_yacc_y.h"

extern int mod_yylex(void);

#define	yymaxdepth mod_yymaxdepth
#define	yyparse	mod_yyparse
#define	yylex	mod_yylex
#define	yyerror	mod_yyerror
#define	yylval	mod_yylval
#define	yychar	mod_yychar
#define	yydebug	mod_yydebug
#define	yypact	mod_yypact
#define	yyr1	mod_yyr1
#define	yyr2	mod_yyr2
#define	yydef	mod_yydef
#define	yychk	mod_yychk
#define	yypgo	mod_yypgo
#define	yyact	mod_yyact
#define	yyexca	mod_yyexca
#define yyerrflag mod_yyerrflag
#define yynerrs	mod_yynerrs
#define	yyps	mod_yyps
#define	yypv	mod_yypv
#define	yys	mod_yys
#define	yy_yys	mod_yyyys
#define	yystate	mod_yystate
#define	yytmp	mod_yytmp
#define	yyv	mod_yyv
#define	yy_yyv	mod_yyyyv
#define	yyval	mod_yyval
#define	yylloc	mod_yylloc
#define yyreds	mod_yyreds
#define yytoks	mod_yytoks
#define yylhs	mod_yyyylhs
#define yylen	mod_yyyylen
#define yydefred mod_yyyydefred
#define yydgoto	mod_yyyydgoto
#define yysindex mod_yyyysindex
#define yyrindex mod_yyyyrindex
#define yygindex mod_yyyygindex
#define yytable	 mod_yyyytable
#define yycheck	 mod_yyyycheck
#define yyname   mod_yyyyname
#define yyrule   mod_yyyyrule

Ifs_Table_t *mod_ifs_table;

extern char *mod_yytext;
extern FILE* mod_yyout;

#include <string.h>
#include <ctype.h>

int mod_num_errors;

#define BUFFER_SIZE 3000
static char buffer [BUFFER_SIZE];
static int buf_len;
   
typedef enum {CONN, PARAM, STATIC_VAR} Id_Kind_t;

/*--------------------------------------------------------------------------*/
static char *subscript (Sub_Id_t sub_id)
{
   if (sub_id.has_subscript) {
      return sub_id.subscript;
   } else {
      return "0";
   }
}

/*--------------------------------------------------------------------------*/
static int
local_strcmpi(char *s, char *t)
     /* string compare -  case insensitive */
{
   for (; *s && t && tolower_c(*s) == tolower_c(*t); s++, t++)
      ;
   if (*s && !*t) {
      return 1;
   }
   if (!*s && *t) {
      return -1;
   }
   if (! (*s || *t)) {
      return 0;
   }
   return tolower((unsigned char) *s) - tolower((unsigned char) *t);
}

/*---------------------------------------------------------------------------*/
static void put_type (FILE *fp, Data_Type_t type)
{
   char ch = ' ';
   
   switch (type) {
   case CMPP_INTEGER:
      ch = 'i';
      break;
   case CMPP_REAL:
      ch = 'r';
      break;
   case CMPP_COMPLEX:
      ch = 'c';
      break;
   case CMPP_BOOLEAN:
      ch = 'b';
      break;
   case CMPP_STRING:
      ch = 's';
      break;
   case CMPP_POINTER:
      ch = 'p';
      break;
   }
   fprintf (fp, ".%cvalue", ch);
}

/*---------------------------------------------------------------------------*/
static void put_conn_type (FILE *fp, Port_Type_t type)
{
   char ch;
   
   switch (type) {
   case USER_DEFINED:
      ch = 'p';
      break;
   case DIGITAL:
      ch = 'p';
      break;
   default:
      ch = 'r';
      break;
   }
   fprintf (fp, ".%cvalue", ch);
}

/*---------------------------------------------------------------------------*/
static void check_dir (int conn_number, Dir_t dir, char *context)
{
   Dir_t conn_dir;
   
   if (conn_number >= 0) {
      /*
       * If negative, this is an invalid port ID and we've already issued
       * an error.
       */
      conn_dir = mod_ifs_table->conn[conn_number].direction;
      if ((conn_dir != dir) && (conn_dir != CMPP_INOUT)) {
	 char error_str[200];
	 
	 sprintf (error_str,
		  "Direction of port `%s' in %s() is not %s or INOUT",
		  mod_ifs_table->conn[conn_number].name, context,
		  (dir == CMPP_IN) ? "IN" : "OUT");
	 yyerror (error_str);
	 mod_num_errors++;
      }
   }
}

/*---------------------------------------------------------------------------*/
static void check_subscript (bool formal, bool actual,
			     bool missing_actual_ok,
			     char *context, char *id)
{
   char error_str[200];

   if ((formal && !actual) && !missing_actual_ok) {
      sprintf (error_str,
	       "%s `%s' is an array - subscript required",
	       context, id);
      yyerror (error_str);
      mod_num_errors++;
      return;
   } else if (!formal && actual) {
      sprintf (error_str,
	       "%s `%s' is not an array - subscript prohibited",
	       context, id);
      yyerror (error_str);
      mod_num_errors++;
      return;
   }
}

/*---------------------------------------------------------------------------*/
static int check_id (Sub_Id_t sub_id, Id_Kind_t kind, bool do_subscript)
{
   int i;
   char error_str[200];
   
   switch (kind) {
   case CONN:
      for (i = 0; i < mod_ifs_table->num_conn; i++) {
	 if (0 == local_strcmpi (sub_id.id, mod_ifs_table->conn[i].name)) {
	    if (do_subscript) {
	       check_subscript (mod_ifs_table->conn[i].is_array,
				sub_id.has_subscript, false, "Port",
				sub_id.id);
	    }
	    return i;
	 }
      }
      break;
   case PARAM:
      for (i = 0; i < mod_ifs_table->num_param; i++) {
      	 if (0 == local_strcmpi (sub_id.id, mod_ifs_table->param[i].name)) {
	    if (do_subscript) {
	       check_subscript (mod_ifs_table->param[i].is_array,
				sub_id.has_subscript, false, "Parameter",
				sub_id.id);
	    }
	    return i;
	 }
      }
      break;
   case STATIC_VAR:
      for (i = 0; i < mod_ifs_table->num_inst_var; i++) {
      	 if (0 == local_strcmpi (sub_id.id, mod_ifs_table->inst_var[i].name)) {
	    if (do_subscript) {
	       check_subscript (mod_ifs_table->inst_var[i].is_array,
				sub_id.has_subscript, true,
				"Static Variable",
				sub_id.id);
	    }
	    return i;
	 }
      }
      break;
   }
   
   sprintf (error_str, "No %s named '%s'",
	    ((kind==CONN)
	     ? "port"
	     : ((kind==PARAM)
		? "parameter"
		:"static variable")),
	    sub_id.id);
   yyerror (error_str);
   mod_num_errors++;
   return -1;
}

/*---------------------------------------------------------------------------*/
static int valid_id (Sub_Id_t sub_id, Id_Kind_t kind)
{
    return check_id (sub_id, kind, false);
}

/*---------------------------------------------------------------------------*/
static int valid_subid (Sub_Id_t sub_id, Id_Kind_t kind)
{
    return check_id (sub_id, kind, true);
}

/*---------------------------------------------------------------------------*/
static void init_buffer (void)
{
   buf_len = 0;
   buffer[0] = '\0';
}

/*---------------------------------------------------------------------------*/
static void append (char *str)
{
   int len = (int) strlen (str);
   if (len + buf_len > BUFFER_SIZE) {
      yyerror ("Buffer overflow - try reducing the complexity of CM-macro array subscripts");
      exit (1);
   }
   (void)strcat (buffer,str);
}

%}

%union {
   char *str;
   Sub_Id_t sub_id;
}

%type <str>	buffered_c_code
%type <sub_id>	subscriptable_id id

%token TOK_ARGS
%token TOK_INIT
%token TOK_CALLBACK
%token TOK_ANALYSIS
%token TOK_NEW_TIMEPOINT
%token TOK_TIME
%token TOK_RAD_FREQ
%token TOK_TEMPERATURE
%token TOK_T 
%token TOK_PARAM 
%token TOK_PARAM_SIZE 
%token TOK_PARAM_NULL 
%token TOK_PORT_SIZE 
%token TOK_PORT_NULL 
%token TOK_PARTIAL 
%token TOK_AC_GAIN
%token TOK_CHANGED
%token TOK_OUTPUT_DELAY 
%token TOK_STATIC_VAR 
%token TOK_STATIC_VAR_SIZE
%token TOK_STATIC_VAR_INST
%token TOK_INPUT
%token TOK_INPUT_STRENGTH
%token TOK_INPUT_STATE
%token TOK_INPUT_TYPE
%token TOK_OUTPUT
%token TOK_OUTPUT_CHANGED
%token TOK_OUTPUT_STRENGTH
%token TOK_OUTPUT_STATE
%token TOK_OUTPUT_TYPE
%token TOK_COMMA
%token TOK_LPAREN
%token TOK_RPAREN
%token TOK_LBRACKET
%token TOK_RBRACKET
%token TOK_MISC_C
%token TOK_IDENTIFIER
%token TOK_LOAD
%token TOK_TOTAL_LOAD
%token TOK_MESSAGE
%token TOK_CALL_TYPE

%start mod_file

%%

mod_file		: /* empty */
			| mod_file c_code 
			; 

c_code			: /* empty */
   			| c_code c_char
   			| c_code macro
			| TOK_RPAREN  {yyerror ("Unmatched )"); YYERROR;}
			| TOK_RBRACKET {yyerror ("Unmatched ]"); YYERROR;}
			;

buffered_c_code		: {init_buffer();} buffered_c_code2
			  {$$ = strdup (buffer);}
			;

buffered_c_code2	: /* empty */
			| buffered_c_code2 buffered_c_char
			;

buffered_c_char		: TOK_IDENTIFIER {append (mod_yytext);}
			| TOK_MISC_C {append (mod_yytext);}
			| TOK_COMMA {append (mod_yytext);}
			| TOK_LBRACKET 
				{append("[");}
			  buffered_c_code2 TOK_RBRACKET
				{append("]");}
			| TOK_LPAREN
				{append("(");}
			  buffered_c_code2 TOK_RPAREN
				{append(")");}
			;

c_char			: TOK_IDENTIFIER {fputs (mod_yytext, mod_yyout);}
			| TOK_MISC_C {fputs (mod_yytext, mod_yyout);}
			| TOK_COMMA {fputs (mod_yytext, mod_yyout);}
			| TOK_LBRACKET TOK_RBRACKET {fputs ("[]", mod_yyout);}
			| TOK_LBRACKET 
				{putc ('[', mod_yyout);}
			  c_code TOK_RBRACKET
				{putc (']', mod_yyout);}
			| TOK_LPAREN TOK_RPAREN {fputs ("()", mod_yyout);}
			| TOK_LPAREN
				{putc ('(', mod_yyout);}
			  c_code TOK_RPAREN
				{putc (')', mod_yyout);}
			;

macro			: TOK_INIT
			   {fprintf (mod_yyout, "mif_private->circuit.init");}
			| TOK_CALLBACK
			   {fprintf (mod_yyout, "*(mif_private->callback)");}
			| TOK_ARGS
			   {fprintf (mod_yyout, "Mif_Private_t *mif_private");}
			| TOK_ANALYSIS
			   {fprintf (mod_yyout, "mif_private->circuit.anal_type");}
			| TOK_NEW_TIMEPOINT
			   {fprintf (mod_yyout, "mif_private->circuit.anal_init");}
			| TOK_CALL_TYPE
			   {fprintf (mod_yyout, "mif_private->circuit.call_type");}
			| TOK_TIME
			   {fprintf (mod_yyout, "mif_private->circuit.time");}
			| TOK_RAD_FREQ
			   {fprintf (mod_yyout, "mif_private->circuit.frequency");}
			| TOK_TEMPERATURE
			   {fprintf (mod_yyout, "mif_private->circuit.temperature");}
			| TOK_T TOK_LPAREN buffered_c_code TOK_RPAREN
			   {fprintf (mod_yyout, "mif_private->circuit.t[%s]", $3);}
			| TOK_PARAM TOK_LPAREN subscriptable_id TOK_RPAREN
			   {int i = valid_subid ($3, PARAM);
			    fprintf (mod_yyout, "mif_private->param[%d]->element[%s]",
				     i, subscript ($3));
			    put_type (mod_yyout, mod_ifs_table->param[i].type);
			   }    
			| TOK_PARAM_SIZE TOK_LPAREN id TOK_RPAREN
			   {int i = valid_id ($3, PARAM);
			    fprintf (mod_yyout, "mif_private->param[%d]->size", i);}
			| TOK_PARAM_NULL TOK_LPAREN id TOK_RPAREN
			   {int i = valid_id ($3, PARAM);
			    fprintf (mod_yyout, "mif_private->param[%d]->is_null", i);}
			| TOK_PORT_SIZE TOK_LPAREN id TOK_RPAREN
			   {int i = valid_id ($3, CONN);
			    fprintf (mod_yyout, "mif_private->conn[%d]->size", i);}
			| TOK_PORT_NULL TOK_LPAREN id TOK_RPAREN
			   {int i = valid_id ($3, CONN);
			    fprintf (mod_yyout, "mif_private->conn[%d]->is_null", i);}
			| TOK_PARTIAL TOK_LPAREN subscriptable_id TOK_COMMA
			  subscriptable_id TOK_RPAREN
			   {int i = valid_subid ($3, CONN);
			    int j = valid_subid ($5, CONN);
			    check_dir (i, CMPP_OUT, "PARTIAL");
			    check_dir (j, CMPP_IN, "PARTIAL");
			    fprintf (mod_yyout, "mif_private->conn[%d]->port[%s]->partial[%d].port[%s]",
				     i, subscript($3), j, subscript($5));}
			| TOK_AC_GAIN TOK_LPAREN subscriptable_id TOK_COMMA
			  subscriptable_id TOK_RPAREN
			   {int i = valid_subid ($3, CONN);
			    int j = valid_subid ($5, CONN);
			    check_dir (i, CMPP_OUT, "AC_GAIN");
			    check_dir (j, CMPP_IN, "AC_GAIN");
			    fprintf (mod_yyout, 
				     "mif_private->conn[%d]->port[%s]->ac_gain[%d].port[%s]",
				     i, subscript($3), j, subscript($5));}
			| TOK_STATIC_VAR TOK_LPAREN subscriptable_id TOK_RPAREN
			   {int i = valid_subid ($3, STATIC_VAR);
			    fprintf (mod_yyout, 
				    "mif_private->inst_var[%d]->element[%s]",
				     i, subscript($3));
			    if (mod_ifs_table->inst_var[i].is_array
				&& !($3.has_subscript)) {
			       /* null - eg. for malloc lvalue */
			    } else {
			       put_type (mod_yyout, 
					mod_ifs_table->inst_var[i].type);
			    } }
			| TOK_STATIC_VAR_SIZE TOK_LPAREN id TOK_RPAREN
			   {int i = valid_subid ($3, STATIC_VAR);
			    fprintf (mod_yyout, "mif_private->inst_var[%d]->size",
				    i);}
			| TOK_STATIC_VAR_INST TOK_LPAREN id TOK_RPAREN
			   {int i = valid_subid ($3, STATIC_VAR);
			    fprintf (mod_yyout, "mif_private->inst_var[%d]",
				    i);}
			| TOK_OUTPUT_DELAY TOK_LPAREN subscriptable_id TOK_RPAREN
			   {int i = valid_subid ($3, CONN);
			    check_dir (i, CMPP_OUT, "OUTPUT_DELAY");
			    fprintf (mod_yyout, 
				     "mif_private->conn[%d]->port[%s]->delay", i,
				     subscript($3));}
			| TOK_CHANGED TOK_LPAREN subscriptable_id TOK_RPAREN
			   {int i = valid_subid ($3, CONN);
			    check_dir (i, CMPP_OUT, "CHANGED");
			    fprintf (mod_yyout, 
				     "mif_private->conn[%d]->port[%s]->changed", i,
				     subscript($3));}
			| TOK_INPUT TOK_LPAREN subscriptable_id TOK_RPAREN
			   {int i = valid_subid ($3, CONN);
 			    check_dir (i, CMPP_IN, "INPUT");
			    fprintf (mod_yyout, 
				     "mif_private->conn[%d]->port[%s]->input",
				     i, subscript($3));
			    put_conn_type (mod_yyout, 
			       mod_ifs_table->conn[i].allowed_port_type[0]);}
			| TOK_INPUT_TYPE TOK_LPAREN subscriptable_id TOK_RPAREN
			   {int i = valid_subid ($3, CONN);
 			    check_dir (i, CMPP_IN, "INPUT_TYPE");
			    fprintf (mod_yyout, 
				     "mif_private->conn[%d]->port[%s]->type_str",
				     i, subscript($3)); }
			| TOK_OUTPUT_TYPE TOK_LPAREN subscriptable_id TOK_RPAREN
			   {int i = valid_subid ($3, CONN);
 			    check_dir (i, CMPP_OUT, "OUTPUT_TYPE");
			    fprintf (mod_yyout, 
				     "mif_private->conn[%d]->port[%s]->type_str",
				     i, subscript($3)); }
			| TOK_INPUT_STRENGTH TOK_LPAREN subscriptable_id TOK_RPAREN
			   {int i = valid_subid ($3, CONN);
 			    check_dir (i, CMPP_IN, "INPUT_STRENGTH");
			    fprintf (mod_yyout, 
				     "((Digital_t*)(mif_private->conn[%d]->port[%s]->input",
				     i, subscript($3));
			    put_conn_type (mod_yyout, 
			       mod_ifs_table->conn[i].allowed_port_type[0]);
			    fprintf (mod_yyout, "))->strength");}
			| TOK_INPUT_STATE TOK_LPAREN subscriptable_id TOK_RPAREN
			   {int i = valid_subid ($3, CONN);
 			    check_dir (i, CMPP_IN, "INPUT_STATE");
			    fprintf (mod_yyout, 
				     "((Digital_t*)(mif_private->conn[%d]->port[%s]->input",
				     i, subscript($3));
			    put_conn_type (mod_yyout, 
			       mod_ifs_table->conn[i].allowed_port_type[0]);
			    fprintf (mod_yyout, "))->state");}
			| TOK_OUTPUT TOK_LPAREN subscriptable_id TOK_RPAREN
			   {int i = valid_subid ($3, CONN);
 			    check_dir (i, CMPP_OUT, "OUTPUT");
			    fprintf (mod_yyout, 
				     "mif_private->conn[%d]->port[%s]->output",
				     i, subscript($3));
			    put_conn_type (mod_yyout, 
			       mod_ifs_table->conn[i].allowed_port_type[0]);}
			| TOK_OUTPUT_STRENGTH TOK_LPAREN subscriptable_id TOK_RPAREN
			   {int i = valid_subid ($3, CONN);
 			    check_dir (i, CMPP_OUT, "OUTPUT_STRENGTH");
			    fprintf (mod_yyout, 
				     "((Digital_t*)(mif_private->conn[%d]->port[%s]->output",
				     i, subscript($3));
			    put_conn_type (mod_yyout, 
			       mod_ifs_table->conn[i].allowed_port_type[0]);
			    fprintf (mod_yyout, "))->strength");}
			| TOK_OUTPUT_STATE TOK_LPAREN subscriptable_id TOK_RPAREN
			   {int i = valid_subid ($3, CONN);
 			    check_dir (i, CMPP_OUT, "OUTPUT_STATE");
			    fprintf (mod_yyout, 
				     "((Digital_t*)(mif_private->conn[%d]->port[%s]->output",
				     i, subscript($3));
			    put_conn_type (mod_yyout, 
			       mod_ifs_table->conn[i].allowed_port_type[0]);
			    fprintf (mod_yyout, "))->state");}
			| TOK_OUTPUT_CHANGED TOK_LPAREN subscriptable_id TOK_RPAREN
			   {int i = valid_subid ($3, CONN);
			    fprintf (mod_yyout, 
				     "mif_private->conn[%d]->port[%s]->changed", i,
				     subscript($3));}
			| TOK_LOAD TOK_LPAREN subscriptable_id TOK_RPAREN
			   {int i = valid_subid ($3, CONN);
			    fprintf (mod_yyout, 
				     "mif_private->conn[%d]->port[%s]->load", i,
				     subscript($3));}
			| TOK_TOTAL_LOAD TOK_LPAREN subscriptable_id TOK_RPAREN
			   {int i = valid_subid ($3, CONN);
			    fprintf (mod_yyout, 
				     "mif_private->conn[%d]->port[%s]->total_load", i,
				     subscript($3));}
			| TOK_MESSAGE TOK_LPAREN subscriptable_id TOK_RPAREN
			   {int i = valid_subid ($3, CONN);
			    fprintf (mod_yyout, 
				     "mif_private->conn[%d]->port[%s]->msg", i,
				     subscript($3));}
			;

subscriptable_id	: id
			| id TOK_LBRACKET buffered_c_code TOK_RBRACKET
			  {$$ = $1;
			   $$.has_subscript = true;
			   $$.subscript = $3;}
			;

id			: TOK_IDENTIFIER
			     {$$.has_subscript = false;
			      $$.id = strdup (mod_yytext);}
			;

%%
