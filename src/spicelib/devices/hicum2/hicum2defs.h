/**********
Copyright 1990 Regents of the University of California.  All rights reserved.
Author: 1985 Thomas L. Quarles
Model Author: 1990 Michael Schröter TU Dresden
Spice3 Implementation: 2019 Dietmar Warning
**********/

#ifndef HICUM
#define HICUM

#include "ngspice/cktdefs.h"
#include "ngspice/ifsim.h"
#include "ngspice/gendefs.h"
#include "ngspice/complex.h"
#include "ngspice/noisedef.h"

/* structures to describe Bipolar Junction Transistors */

/* indices to array of HICUM noise sources */

enum {
    HICUMRCNOIZ = 0,
    HICUMRBNOIZ,
    HICUMRBINOIZ,
    HICUMRENOIZ,
    HICUMRSNOIZ,
    HICUMICNOIZ,
    HICUMIBCNOIZ,
    HICUMIBEPNOIZ,
    HICUMIBCXNOIZ,
    HICUMITSNOIZ,
    HICUMFLBENOIZ,
    HICUMFLRENOIZ,
    HICUMTOTNOIZ,
    /* finally, the number of noise sources */
    HICUMNSRCS
};

typedef struct sDualDouble {
    double rpart;
    double dpart;
} dual_double;

/* data needed to describe a single instance */

typedef struct sHICUMinstance {

    struct GENinstance gen;

#define HICUMmodPtr(inst) ((struct sHICUMmodel *)((inst)->gen.GENmodPtr))
#define HICUMnextInstance(inst) ((struct sHICUMinstance *)((inst)->gen.GENnextInstance))
#define HICUMname gen.GENname
#define HICUMstate gen.GENstate

    const int HICUMcollNode; /* number of collector node of hicum */
    const int HICUMbaseNode; /* number of base node of hicum */
    const int HICUMemitNode; /* number of emitter node of hicum */
    const int HICUMsubsNode; /* number of substrate node of hicum */
    const int HICUMtempNode; /* number of the temperature node of the hicum */
    int HICUMcollCINode; /* number of internal collector node of hicum */
    int HICUMbaseBINode; /* number of internal base node of hicum */
    int HICUMemitEINode; /* number of internal emitter node of hicum */
    int HICUMbaseBPNode; /* number of internal base node of hicum */
    int HICUMsubsSINode; /* number of internal substrate node */
    int HICUMxfNode;     /* number of internal excess phase node qdei */
    int HICUMxf1Node;    /* number of internal excess phase node itf */
    int HICUMxf2Node;    /* number of internal excess phase node itf */

    double HICUMarea;     /* area factor for the hicum */
    //initial conditions
    double HICUMicVBi;    /* initial condition potential Bi */
    double HICUMicVBp;    /* initial condition potential Bp */
    double HICUMicVB;     /* initial condition potential B  */
    double HICUMicVCi;    /* initial condition potential Ci */
    double HICUMicVt;     /* initial condition potential T */
    double HICUMicVEi;    /* initial condition potential Ei */
    double HICUMicVC;     /* initial condition potential C  */
    double HICUMicVE;     /* initial condition potential E  */

    double HICUMtemp;     /* instance temperature */
    double HICUMdtemp;    /* instance delta temperature */
    double HICUMdtemp_sh; /* instance delta temperature because of self-heating */
    double HICUMm;        /* multiply factor for the hicum */

    double HICUMvt0;
    dual_double HICUMvt;
    dual_double HICUMdT;
    dual_double HICUMibeis_t;
    dual_double HICUMireis_t;
    dual_double HICUMibeps_t;
    dual_double HICUMireps_t;
    dual_double HICUMibcis_t;
    dual_double HICUMibcxs_t;
    dual_double HICUMitss_t;
    dual_double HICUMiscs_t;
    dual_double HICUMqp0_t;
    dual_double HICUMvlim_t;
    dual_double HICUMtef0_t;
    dual_double HICUMc10_t;
    dual_double HICUMrci0_t;
    dual_double HICUMvces_t;
    dual_double HICUMt0_t;
    dual_double HICUMthcs_t;
    dual_double HICUMfavl_t;
    dual_double HICUMqavl_t;
    dual_double HICUMkavl_t;
    dual_double HICUMrbi0_t;
    dual_double HICUMibets_t;
    dual_double HICUMabet_t;
    dual_double HICUMcjcx01_t;
    dual_double HICUMcjcx02_t;
    dual_double HICUMrcx_t;
    dual_double HICUMrbx_t;
    dual_double HICUMre_t;
    dual_double HICUMtsf_t;
    dual_double HICUMcscp0_t;
    dual_double HICUMvdsp_t;
    dual_double HICUMvptsp_t;
    dual_double HICUMahjei_t;
    dual_double HICUMhjei0_t;
    dual_double HICUMhf0_t;
    dual_double HICUMhfc_t;
    dual_double HICUMhfe_t;
    dual_double HICUMrth_t;

    dual_double HICUMvdei_t;
    dual_double HICUMajei_t;
    dual_double HICUMcjci0_t;
    dual_double HICUMvdci_t;
    dual_double HICUMvptci_t;
    dual_double HICUMvdep_t;
    dual_double HICUMajep_t;
    dual_double HICUMcjep0_t;
    dual_double HICUMcjei0_t;
    dual_double HICUMvdcx_t;
    dual_double HICUMvptcx_t;
    dual_double HICUMcjs0_t;
    dual_double HICUMvds_t;
    dual_double HICUMvpts_t;

    double HICUMrbi;
    double HICUMiavl;
    double HICUMpterm;

    double HICUMtf;
    double HICUMick;

    double HICUMcbepar;
    double HICUMcbcpar;

    double *HICUMcollCollPtr;  /* pointer to sparse matrix at
                             * (collector,collector) */
    double *HICUMbaseBasePtr; /* pointer to sparse matrix at
                             * (base,base) */
    double *HICUMemitEmitPtr; /* pointer to sparse matrix at
                             * (emitter,emitter) */
    double *HICUMsubsSubsPtr;   /* pointer to sparse matrix at
                             * (substrate,substrate) */
    double *HICUMcollCICollCIPtr; /* pointer to sparse matrix at
                             * (collector prime,collector prime) */
    double *HICUMbaseBIBaseBIPtr; /* pointer to sparse matrix at
                             * (collector prime,collector prime) */
    double *HICUMbaseBPBaseBPPtr; /* pointer to sparse matrix at
                             * (collector prime,collector prime) */
    double *HICUMemitEIEmitEIPtr;   /* pointer to sparse matrix at
                             * (emitter prime,emitter prime) */
    double *HICUMsubsSISubsSIPtr;    /* pointer to sparse matrix at
                             * (substrate prime, substrate prime) */

    double *HICUMbaseEmitPtr; /* pointer to sparse matrix at
                             * (base,emit) */
    double *HICUMemitBasePtr; /* pointer to sparse matrix at
                             * (emit,base) */
    double *HICUMcollCollCIPtr;    /* pointer to sparse matrix at
                             * (collector,collector prime) */
    double *HICUMbaseBaseBPPtr;    /* pointer to sparse matrix at
                             * (base,base prime) */
    double *HICUMemitEmitEIPtr;    /* pointer to sparse matrix at
                             * (emitter,emitter prime) */
    double *HICUMsubsSubsSIPtr;    /* pointer to sparse matrix at
                             * (substrate, Substrate connection) */
    double *HICUMcollCIBaseBIPtr; /* pointer to sparse matrix at
                             * (collector prime,base) */
    double *HICUMcollCIEmitEIPtr;    /* pointer to sparse matrix at
                             * (collector prime,emitter prime) */
    double *HICUMbaseBPBaseBIPtr;   /* pointer to sparse matrix at
                             * (base prime,emitter prime) */
    double *HICUMbaseBPEmitEIPtr;   /* pointer to sparse matrix at
                             * (base prime,emitter prime) */
    double *HICUMbaseBPSubsSIPtr;   /* pointer to sparse matrix at
                             * (base prime,emitter prime) */
    double *HICUMbaseBIEmitEIPtr;   /* pointer to sparse matrix at
                             * (base prime,emitter prime) */

    double *HICUMcollCICollPtr;  /* pointer to sparse matrix at
                             * (collector prime,collector) */
    double *HICUMbaseBPBasePtr;    /* pointer to sparse matrix at
                             * (base prime,base ) */
    double *HICUMemitEIEmitPtr;    /* pointer to sparse matrix at
                             * (emitter prime,emitter) */
    double *HICUMsubsSISubsPtr;    /* pointer to sparse matrix at
                             * (Substrate connection, substrate) */
    double *HICUMbaseBPCollCIPtr; /* pointer to sparse matrix at
                             * (base,collector prime) */
    double *HICUMcollCIBaseBPPtr; /* pointer to sparse matrix at
                             * (collector prime,base) */

    double *HICUMbaseBICollCIPtr; /* pointer to sparse matrix at
                             * (base,collector prime) */
    double *HICUMemitEICollCIPtr;    /* pointer to sparse matrix at
                             * (emitter prime,collector prime) */
    double *HICUMsubsSICollCIPtr;   /* pointer to sparse matrix at
                             * (substrate,collector prime) */
    double *HICUMcollCISubsSIPtr;   /* pointer to sparse matrix at
                             * (collector prime,substrate) */
    double *HICUMbaseBIBaseBPPtr;   /* pointer to sparse matrix at
                             * (base prime,emitter prime) */
    double *HICUMemitEIBaseBPPtr;   /* pointer to sparse matrix at
                             * (emitter prime,base prime) */
    double *HICUMsubsSIBaseBPPtr;   /* pointer to sparse matrix at
                             * (substrate,base) */
    double *HICUMsubsSIBaseBIPtr;   /* pointer to sparse matrix at
                             * (substrate,base) */
    double *HICUMemitEIBaseBIPtr;   /* pointer to sparse matrix at
                             * (emitter prime,base prime) */

    double *HICUMcollCIBasePtr;
    double *HICUMbaseCollCIPtr;

    double *HICUMbaseBPEmitPtr;
    double *HICUMemitBaseBPPtr;

    double *HICUMsubsCollPtr;
    double *HICUMcollSubsPtr;

    /* excess phase */
    double *HICUMxfXfPtr;
    double *HICUMxf1Xf1Ptr;
    double *HICUMxf2Xf2Ptr;

    /* self heating */
    double *HICUMcollTempPtr;
    double *HICUMbaseTempPtr;
    double *HICUMemitTempPtr;

    double *HICUMcollCItempPtr;
    double *HICUMbaseBItempPtr;
    double *HICUMbaseBPtempPtr;
    double *HICUMemitEItempPtr;
    double *HICUMsubsSItempPtr;

    double *HICUMtempCollPtr;
    double *HICUMtempBasePtr;
    double *HICUMtempEmitPtr;

    double *HICUMtempCollCIPtr;
    double *HICUMtempBaseBIPtr;
    double *HICUMtempBaseBPPtr;
    double *HICUMtempEmitEIPtr;
    double *HICUMtempSubsSIPtr;
    double *HICUMtempTempPtr;

    unsigned HICUMareaGiven   :1;  /* flag to indicate area was specified */
    unsigned HICUMoff         :1;  /* 'off' flag for hicum */
    unsigned HICUMicVBGiven   :1;  /* flag to indicate VB init. cond. given */
    unsigned HICUMicVEGiven   :1;  /* flag to indicate VE init. cond. given */
    unsigned HICUMicVCGiven   :1;  /* flag to indicate VC init. cond. given */
    unsigned HICUMicVBiGiven  :1;  /* flag to indicate VBi init. cond. given */
    unsigned HICUMicVBpGiven  :1;  /* flag to indicate VBp init. cond. given */
    unsigned HICUMicVEiGiven  :1;  /* flag to indicate VEi init. cond. given */
    unsigned HICUMicVCiGiven  :1;  /* flag to indicate VCi init. cond. given */
    unsigned HICUMicVtGiven   :1;  /* flag to indicate VCi init. cond. given */
    unsigned HICUMtempGiven   :1;  /* temperature given for hicum instance*/
    unsigned HICUMdtempGiven  :1;  /* delta temperature given for hicum instance*/
    unsigned HICUMmGiven      :1;  /* flag to indicate multiplier was specified */

    double HICUMcaprbi;
    double HICUMcapdeix;
    double HICUMcapjei;
    double HICUMcapdci;
    double HICUMcapjci;
    double HICUMcapjep;
    double HICUMcapjcx_t_i;
    double HICUMcapjcx_t_ii;
    double HICUMcapdsu;
    double HICUMcapjs;
    double HICUMcapscp;
    double HICUMcapsu;
    double HICUMcapcth;

    double HICUMcapxf;

    double HICUMtVcrit;
    double HICUMbetadc;

#ifndef NONOISE
      double HICUMnVar[NSTATVARS][HICUMNSRCS];
#else /*NONOISE*/
      double **HICUMnVar;
#endif /*NONOISE*/
/* the above to avoid allocating memory when it is not needed */

} HICUMinstance;

/* entries in the state vector for hicum: */

#define HICUMvbiei       HICUMstate
#define HICUMvbici       HICUMstate+1
#define HICUMvbpei       HICUMstate+2
#define HICUMvbpbi       HICUMstate+3
#define HICUMvbpci       HICUMstate+4
#define HICUMvsici       HICUMstate+5

#define HICUMibiei       HICUMstate+6
#define HICUMibiei_Vbiei HICUMstate+7
#define HICUMibiei_Vbici HICUMstate+8

#define HICUMibpei       HICUMstate+9
#define HICUMibpei_Vbpei HICUMstate+10

#define HICUMiciei       HICUMstate+11
#define HICUMiciei_Vbiei HICUMstate+12
#define HICUMiciei_Vbici HICUMstate+13

#define HICUMibici       HICUMstate+14
#define HICUMibici_Vbici HICUMstate+15

#define HICUMibpbi       HICUMstate+16
#define HICUMibpbi_Vbpbi HICUMstate+17
#define HICUMibpbi_Vbiei HICUMstate+18
#define HICUMibpbi_Vbici HICUMstate+19

#define HICUMibpci       HICUMstate+20
#define HICUMibpci_Vbpci HICUMstate+21

#define HICUMisici       HICUMstate+22
#define HICUMisici_Vsici HICUMstate+23

#define HICUMibpsi       HICUMstate+24
#define HICUMibpsi_Vbpci HICUMstate+25
#define HICUMibpsi_Vsici HICUMstate+26

#define HICUMisis_Vsis   HICUMstate+27

#define HICUMieie        HICUMstate+28  // needed for re-flicker noise

#define HICUMqrbi        HICUMstate+29
#define HICUMcqrbi       HICUMstate+30

#define HICUMqjei        HICUMstate+31
#define HICUMcqjei       HICUMstate+32

#define HICUMqdeix       HICUMstate+33
#define HICUMcqdeix      HICUMstate+34

#define HICUMqjci        HICUMstate+35
#define HICUMcqjci       HICUMstate+36

#define HICUMqdci        HICUMstate+37
#define HICUMcqdci       HICUMstate+38

#define HICUMqjep        HICUMstate+39
#define HICUMcqjep       HICUMstate+40

#define HICUMqjcx0_i     HICUMstate+41
#define HICUMcqcx0_t_i   HICUMstate+42

#define HICUMqjcx0_ii    HICUMstate+43
#define HICUMcqcx0_t_ii  HICUMstate+44

#define HICUMqdsu        HICUMstate+45
#define HICUMcqdsu       HICUMstate+46

#define HICUMqjs         HICUMstate+47
#define HICUMcqjs        HICUMstate+48

#define HICUMqscp        HICUMstate+49
#define HICUMcqscp       HICUMstate+50

#define HICUMqbepar1     HICUMstate+51
#define HICUMcqbepar1    HICUMstate+52
#define HICUMgqbepar1    HICUMstate+53

#define HICUMqbepar2     HICUMstate+54
#define HICUMcqbepar2    HICUMstate+55
#define HICUMgqbepar2    HICUMstate+56

#define HICUMqbcpar1     HICUMstate+57
#define HICUMcqbcpar1    HICUMstate+58
#define HICUMgqbcpar1    HICUMstate+59

#define HICUMqbcpar2     HICUMstate+60
#define HICUMcqbcpar2    HICUMstate+61
#define HICUMgqbcpar2    HICUMstate+62

#define HICUMqsu         HICUMstate+63
#define HICUMcqsu        HICUMstate+64
#define HICUMgqsu        HICUMstate+65

#define HICUMqcth        HICUMstate+66 /* thermal capacitor charge */
#define HICUMcqcth       HICUMstate+67 /* thermal capacitor current */

#define HICUMvrth        HICUMstate+68
#define HICUMicth_dT     HICUMstate+69

#define HICUMvxf         HICUMstate+70
#define HICUMqxf         HICUMstate+71
#define HICUMcqxf        HICUMstate+72
#define HICUMgqxf        HICUMstate+73
#define HICUMixf_Vbiei   HICUMstate+74
#define HICUMixf_Vbici   HICUMstate+75

#define HICUMvxf1        HICUMstate+76
#define HICUMqxf1        HICUMstate+77
#define HICUMcqxf1       HICUMstate+78
#define HICUMgqxf1       HICUMstate+79
#define HICUMixf1_Vbiei  HICUMstate+80
#define HICUMixf1_Vbici  HICUMstate+81
#define HICUMixf1_Vfx2   HICUMstate+82

#define HICUMvxf2        HICUMstate+83
#define HICUMqxf2        HICUMstate+84
#define HICUMcqxf2       HICUMstate+85
#define HICUMgqxf2       HICUMstate+86
#define HICUMixf2_Vbiei  HICUMstate+87
#define HICUMixf2_Vbici  HICUMstate+88
#define HICUMixf2_Vfx1   HICUMstate+89

#define HICUMith         HICUMstate+90
#define HICUMith_Vrth    HICUMstate+91

#define HICUMnumStates 92

/* per model data */
typedef struct sHICUMmodel {           /* model structure for a hicum */

    struct GENmodel gen;

#define HICUMmodType gen.GENmodType
#define HICUMnextModel(inst) ((struct sHICUMmodel *)((inst)->gen.GENnextModel))
#define HICUMinstances(inst) ((HICUMinstance *)((inst)->gen.GENinstances))
#define HICUMmodName gen.GENmodName

//Circuit simulator specific parameters
    int HICUMtype;
    double HICUMtnom;

//Transfer current
    double HICUMc10;
    double HICUMqp0;
    double HICUMich;
    double HICUMhf0;
    double HICUMhfe;
    double HICUMhfc;
    double HICUMhjei;
    double HICUMahjei;
    double HICUMrhjei;
    double HICUMhjci;

//Base-Emitter diode;
    double HICUMibeis;
    double HICUMmbei;
    double HICUMireis;
    double HICUMmrei;
    double HICUMibeps;
    double HICUMmbep;
    double HICUMireps;
    double HICUMmrep;
    double HICUMmcf;

//Transit time for excess recombination current at b-c barrier
    double HICUMtbhrec;

//Base-Collector diode currents
    double HICUMibcis;
    double HICUMmbci;
    double HICUMibcxs;
    double HICUMmbcx;

//Base-Emitter tunneling current
    double HICUMibets;
    double HICUMabet;
    int HICUMtunode;

//Base-Collector avalanche current
    double HICUMfavl;
    double HICUMqavl;
    double HICUMkavl;
    double HICUMalfav;
    double HICUMalqav;
    double HICUMalkav;

//Series resistances
    double HICUMrbi0;
    double HICUMrbx;
    double HICUMfgeo;
    double HICUMfdqr0;
    double HICUMfcrbi;
    double HICUMfqi;
    double HICUMre;
    double HICUMrcx;

//Substrate transistor
    double HICUMitss;
    double HICUMmsf;
    double HICUMiscs;
    double HICUMmsc;
    double HICUMtsf;

//Intra-device substrate coupling
    double HICUMrsu;
    double HICUMcsu;

//Depletion Capacitances
    double HICUMcjei0;
    double HICUMvdei;
    double HICUMzei;
    double HICUMajei;
    double HICUMcjep0;
    double HICUMvdep;
    double HICUMzep;
    double HICUMajep;
    double HICUMcjci0;
    double HICUMvdci;
    double HICUMzci;
    double HICUMvptci;
    double HICUMcjcx0;
    double HICUMvdcx;
    double HICUMzcx;
    double HICUMvptcx;
    double HICUMfbcpar;
    double HICUMfbepar;
    double HICUMcjs0;
    double HICUMvds;
    double HICUMzs;
    double HICUMvpts;
    double HICUMcscp0;
    double HICUMvdsp;
    double HICUMzsp;
    double HICUMvptsp;

//Diffusion Capacitances
    double HICUMt0;
    double HICUMdt0h;
    double HICUMtbvl;
    double HICUMtef0;
    double HICUMgtfe;
    double HICUMthcs;
    double HICUMahc;
    double HICUMfthc;
    double HICUMrci0;
    double HICUMvlim;
    double HICUMvces;
    double HICUMvpt;
    double HICUMaick;
    double HICUMdelck;
    double HICUMtr;
    double HICUMvcbar;
    double HICUMicbar;
    double HICUMacbar;

//Isolation Capacitances
    double HICUMcbepar;
    double HICUMcbcpar;

//Non-quasi-static Effect
    double HICUMalqf;
    double HICUMalit;
    int HICUMflnqs;

//Noise
    double HICUMkf;
    double HICUMaf;
    int HICUMcfbe;
    int HICUMflcono;
    double HICUMkfre;
    double HICUMafre;

//Lateral Geometry Scaling (at high current densities)
    double HICUMlatb;
    double HICUMlatl;

//Temperature dependence
    double HICUMvgb;
    double HICUMalt0;
    double HICUMkt0;
    double HICUMzetaci;
    double HICUMalvs;
    double HICUMalces;
    double HICUMzetarbi;
    double HICUMzetarbx;
    double HICUMzetarcx;
    double HICUMzetare;
    double HICUMzetacx;
    double HICUMvge;
    double HICUMvgc;
    double HICUMvgs;
    double HICUMf1vg;
    double HICUMf2vg;
    double HICUMzetact;
    double HICUMzetabet;
    double HICUMalb;
    double HICUMdvgbe;
    double HICUMzetahjei;
    double HICUMzetavgbe;

//Self-Heating
    int HICUMflsh;
    double HICUMrth;
    double HICUMzetarth;
    double HICUMalrth;
    double HICUMcth;

//Compatibility with V2.1
    double HICUMflcomp;

//SOA check parameters
    double HICUMvbeMax; /* maximum voltage over B-E junction */
    double HICUMvbcMax; /* maximum voltage over B-C junction */
    double HICUMvceMax; /* maximum voltage over C-E branch */

//Circuit simulator specific parameters
    unsigned HICUMtypeGiven : 1;
    unsigned HICUMtnomGiven : 1;

//Transfer current
    unsigned HICUMc10Given : 1;
    unsigned HICUMqp0Given : 1;
    unsigned HICUMichGiven : 1;
    unsigned HICUMhf0Given : 1;
    unsigned HICUMhfeGiven : 1;
    unsigned HICUMhfcGiven : 1;
    unsigned HICUMhjeiGiven : 1;
    unsigned HICUMahjeiGiven : 1;
    unsigned HICUMrhjeiGiven : 1;
    unsigned HICUMhjciGiven : 1;

//Base-Emitter diodeGiven : 1;
    unsigned HICUMibeisGiven : 1;
    unsigned HICUMmbeiGiven : 1;
    unsigned HICUMireisGiven : 1;
    unsigned HICUMmreiGiven : 1;
    unsigned HICUMibepsGiven : 1;
    unsigned HICUMmbepGiven : 1;
    unsigned HICUMirepsGiven : 1;
    unsigned HICUMmrepGiven : 1;
    unsigned HICUMmcfGiven : 1;

//Transit time for excess recombination current at b-c barrier
    unsigned HICUMtbhrecGiven : 1;

//Base-Collector diode currents
    unsigned HICUMibcisGiven : 1;
    unsigned HICUMmbciGiven : 1;
    unsigned HICUMibcxsGiven : 1;
    unsigned HICUMmbcxGiven : 1;

//Base-Emitter tunneling current
    unsigned HICUMibetsGiven : 1;
    unsigned HICUMabetGiven : 1;
    unsigned HICUMtunodeGiven : 1;

//Base-Collector avalanche current
    unsigned HICUMfavlGiven : 1;
    unsigned HICUMqavlGiven : 1;
    unsigned HICUMkavlGiven : 1;
    unsigned HICUMalfavGiven : 1;
    unsigned HICUMalqavGiven : 1;
    unsigned HICUMalkavGiven : 1;

//Series resistances
    unsigned HICUMrbi0Given : 1;
    unsigned HICUMrbxGiven : 1;
    unsigned HICUMfgeoGiven : 1;
    unsigned HICUMfdqr0Given : 1;
    unsigned HICUMfcrbiGiven : 1;
    unsigned HICUMfqiGiven : 1;
    unsigned HICUMreGiven : 1;
    unsigned HICUMrcxGiven : 1;

//Substrate transistor
    unsigned HICUMitssGiven : 1;
    unsigned HICUMmsfGiven : 1;
    unsigned HICUMiscsGiven : 1;
    unsigned HICUMmscGiven : 1;
    unsigned HICUMtsfGiven : 1;

//Intra-device substrate coupling
    unsigned HICUMrsuGiven : 1;
    unsigned HICUMcsuGiven : 1;

//Depletion Capacitances
    unsigned HICUMcjei0Given : 1;
    unsigned HICUMvdeiGiven : 1;
    unsigned HICUMzeiGiven : 1;
    unsigned HICUMajeiGiven : 1;
    unsigned HICUMcjep0Given : 1;
    unsigned HICUMvdepGiven : 1;
    unsigned HICUMzepGiven : 1;
    unsigned HICUMajepGiven : 1;
    unsigned HICUMcjci0Given : 1;
    unsigned HICUMvdciGiven : 1;
    unsigned HICUMzciGiven : 1;
    unsigned HICUMvptciGiven : 1;
    unsigned HICUMcjcx0Given : 1;
    unsigned HICUMvdcxGiven : 1;
    unsigned HICUMzcxGiven : 1;
    unsigned HICUMvptcxGiven : 1;
    unsigned HICUMfbcparGiven : 1;
    unsigned HICUMfbeparGiven : 1;
    unsigned HICUMcjs0Given : 1;
    unsigned HICUMvdsGiven : 1;
    unsigned HICUMzsGiven : 1;
    unsigned HICUMvptsGiven : 1;
    unsigned HICUMcscp0Given : 1;
    unsigned HICUMvdspGiven : 1;
    unsigned HICUMzspGiven : 1;
    unsigned HICUMvptspGiven : 1;

//Diffusion Capacitances
    unsigned HICUMt0Given : 1;
    unsigned HICUMdt0hGiven : 1;
    unsigned HICUMtbvlGiven : 1;
    unsigned HICUMtef0Given : 1;
    unsigned HICUMgtfeGiven : 1;
    unsigned HICUMthcsGiven : 1;
    unsigned HICUMahcGiven : 1;
    unsigned HICUMfthcGiven : 1;
    unsigned HICUMrci0Given : 1;
    unsigned HICUMvlimGiven : 1;
    unsigned HICUMvcesGiven : 1;
    unsigned HICUMvptGiven : 1;
    unsigned HICUMaickGiven : 1;
    unsigned HICUMdelckGiven : 1;
    unsigned HICUMtrGiven : 1;
    unsigned HICUMvcbarGiven : 1;
    unsigned HICUMicbarGiven : 1;
    unsigned HICUMacbarGiven : 1;

//Isolation Capacitances
    unsigned HICUMcbeparGiven : 1;
    unsigned HICUMcbcparGiven : 1;

//Non-quasi-static Effect
    unsigned HICUMalqfGiven : 1;
    unsigned HICUMalitGiven : 1;
    unsigned HICUMflnqsGiven : 1;

//Noise
    unsigned HICUMkfGiven : 1;
    unsigned HICUMafGiven : 1;
    unsigned HICUMcfbeGiven : 1;
    unsigned HICUMflconoGiven : 1;
    unsigned HICUMkfreGiven : 1;
    unsigned HICUMafreGiven : 1;

//Lateral Geometry Scaling (at high current densities)
    unsigned HICUMlatbGiven : 1;
    unsigned HICUMlatlGiven : 1;

//Temperature dependence
    unsigned HICUMvgbGiven : 1;
    unsigned HICUMalt0Given : 1;
    unsigned HICUMkt0Given : 1;
    unsigned HICUMzetaciGiven : 1;
    unsigned HICUMalvsGiven : 1;
    unsigned HICUMalcesGiven : 1;
    unsigned HICUMzetarbiGiven : 1;
    unsigned HICUMzetarbxGiven : 1;
    unsigned HICUMzetarcxGiven : 1;
    unsigned HICUMzetareGiven : 1;
    unsigned HICUMzetacxGiven : 1;
    unsigned HICUMvgeGiven : 1;
    unsigned HICUMvgcGiven : 1;
    unsigned HICUMvgsGiven : 1;
    unsigned HICUMf1vgGiven : 1;
    unsigned HICUMf2vgGiven : 1;
    unsigned HICUMzetactGiven : 1;
    unsigned HICUMzetabetGiven : 1;
    unsigned HICUMalbGiven : 1;
    unsigned HICUMdvgbeGiven : 1;
    unsigned HICUMzetahjeiGiven : 1;
    unsigned HICUMzetavgbeGiven : 1;

//Self-Heating
    unsigned HICUMflshGiven : 1;
    unsigned HICUMrthGiven : 1;
    unsigned HICUMzetarthGiven : 1;
    unsigned HICUMalrthGiven : 1;
    unsigned HICUMcthGiven : 1;

//Compatibility with V2.1
    unsigned HICUMflcompGiven : 1;

    unsigned HICUMvbeMaxGiven : 1;
    unsigned HICUMvbcMaxGiven : 1;
    unsigned HICUMvceMaxGiven : 1;
} HICUMmodel;

#ifndef NPN
#define NPN 1
#define PNP -1
#endif /*NPN*/

/* device parameters */
enum {
    HICUM_AREA = 1,
    HICUM_OFF,
    HICUM_IC,
    HICUM_IC_VB,
    HICUM_IC_VE,
    HICUM_IC_VC,
    HICUM_IC_VBi,
    HICUM_IC_VBp,
    HICUM_IC_VEi,
    HICUM_IC_VCi,
    HICUM_IC_Vt,
    HICUM_TEMP,
    HICUM_DTEMP,
    HICUM_M,
};

/* model parameters */
enum {
//Circuit simulator specific parameters
    HICUM_MOD_NPN = 101,
    HICUM_MOD_PNP,
    HICUM_MOD_TNOM,

//Transfer current
    HICUM_MOD_C10,
    HICUM_MOD_QP0,
    HICUM_MOD_ICH,
    HICUM_MOD_HF0,
    HICUM_MOD_HFE,
    HICUM_MOD_HFC,
    HICUM_MOD_HJEI,
    HICUM_MOD_AHJEI,
    HICUM_MOD_RHJEI,
    HICUM_MOD_HJCI,

//Base-Emitter diode,
    HICUM_MOD_IBEIS,
    HICUM_MOD_MBEI,
    HICUM_MOD_IREIS,
    HICUM_MOD_MREI,
    HICUM_MOD_IBEPS,
    HICUM_MOD_MBEP,
    HICUM_MOD_IREPS,
    HICUM_MOD_MREP,
    HICUM_MOD_MCF,

//Transit time for excess recombination current at b-c barrier
    HICUM_MOD_TBHREC,

//Base-Collector diode currents
    HICUM_MOD_IBCIS,
    HICUM_MOD_MBCI,
    HICUM_MOD_IBCXS,
    HICUM_MOD_MBCX,

//Base-Emitter tunneling current
    HICUM_MOD_IBETS,
    HICUM_MOD_ABET,
    HICUM_MOD_TUNODE,

//Base-Collector avalanche current
    HICUM_MOD_FAVL,
    HICUM_MOD_QAVL,
    HICUM_MOD_KAVL,
    HICUM_MOD_ALFAV,
    HICUM_MOD_ALQAV,
    HICUM_MOD_ALKAV,

//Series resistances
    HICUM_MOD_RBI0,
    HICUM_MOD_RBX,
    HICUM_MOD_FGEO,
    HICUM_MOD_FDQR0,
    HICUM_MOD_FCRBI,
    HICUM_MOD_FQI,
    HICUM_MOD_RE,
    HICUM_MOD_RCX,

//Substrate transistor
    HICUM_MOD_ITSS,
    HICUM_MOD_MSF,
    HICUM_MOD_ISCS,
    HICUM_MOD_MSC,
    HICUM_MOD_TSF,

//Intra-device substrate coupling
    HICUM_MOD_RSU,
    HICUM_MOD_CSU,

//Depletion Capacitances
    HICUM_MOD_CJEI0,
    HICUM_MOD_VDEI,
    HICUM_MOD_ZEI,
    HICUM_MOD_AJEI,
    HICUM_MOD_CJEP0,
    HICUM_MOD_VDEP,
    HICUM_MOD_ZEP,
    HICUM_MOD_AJEP,
    HICUM_MOD_CJCI0,
    HICUM_MOD_VDCI,
    HICUM_MOD_ZCI,
    HICUM_MOD_VPTCI,
    HICUM_MOD_CJCX0,
    HICUM_MOD_VDCX,
    HICUM_MOD_ZCX,
    HICUM_MOD_VPTCX,
    HICUM_MOD_FBCPAR,
    HICUM_MOD_FBEPAR,
    HICUM_MOD_CJS0,
    HICUM_MOD_VDS,
    HICUM_MOD_ZS,
    HICUM_MOD_VPTS,
    HICUM_MOD_CSCP0,
    HICUM_MOD_VDSP,
    HICUM_MOD_ZSP,
    HICUM_MOD_VPTSP,

//Diffusion Capacitances
    HICUM_MOD_T0,
    HICUM_MOD_DT0H,
    HICUM_MOD_TBVL,
    HICUM_MOD_TEF0,
    HICUM_MOD_GTFE,
    HICUM_MOD_THCS,
    HICUM_MOD_AHC,
    HICUM_MOD_FTHC,
    HICUM_MOD_RCI0,
    HICUM_MOD_VLIM,
    HICUM_MOD_VCES,
    HICUM_MOD_VPT,
    HICUM_MOD_AICK,
    HICUM_MOD_DELCK,
    HICUM_MOD_TR,
    HICUM_MOD_VCBAR,
    HICUM_MOD_ICBAR,
    HICUM_MOD_ACBAR,

//Isolation Capacitances
    HICUM_MOD_CBEPAR,
    HICUM_MOD_CBCPAR,

//Non-quasi-static Effect
    HICUM_MOD_ALQF,
    HICUM_MOD_ALIT,
    HICUM_MOD_FLNQS,

//Noise
    HICUM_MOD_KF,
    HICUM_MOD_AF,
    HICUM_MOD_CFBE,
    HICUM_MOD_FLCONO,

    HICUM_MOD_KFRE,
    HICUM_MOD_AFRE,

//Lateral Geometry Scaling (at high current densities)
    HICUM_MOD_LATB,
    HICUM_MOD_LATL,

//Temperature dependence
    HICUM_MOD_VGB,
    HICUM_MOD_ALT0,
    HICUM_MOD_KT0,
    HICUM_MOD_ZETACI,
    HICUM_MOD_ALVS,
    HICUM_MOD_ALCES,
    HICUM_MOD_ZETARBI,
    HICUM_MOD_ZETARBX,
    HICUM_MOD_ZETARCX,
    HICUM_MOD_ZETARE,
    HICUM_MOD_ZETACX,
    HICUM_MOD_VGE,
    HICUM_MOD_VGC,
    HICUM_MOD_VGS,
    HICUM_MOD_F1VG,
    HICUM_MOD_F2VG,
    HICUM_MOD_ZETACT,
    HICUM_MOD_ZETABET,
    HICUM_MOD_ALB,
    HICUM_MOD_DVGBE,
    HICUM_MOD_ZETAHJEI,
    HICUM_MOD_ZETAVGBE,

//Self-Heating
    HICUM_MOD_FLSH,
    HICUM_MOD_RTH,
    HICUM_MOD_ZETARTH,
    HICUM_MOD_ALRTH,
    HICUM_MOD_CTH,

//Compatibility with V2.1
    HICUM_MOD_FLCOMP,

//SOA check
    HICUM_MOD_VBE_MAX,
    HICUM_MOD_VBC_MAX,
    HICUM_MOD_VCE_MAX,
};

/* device questions */
enum {
    HICUM_QUEST_COLLNODE = 251,
    HICUM_QUEST_BASENODE,
    HICUM_QUEST_EMITNODE,
    HICUM_QUEST_SUBSNODE,
    HICUM_QUEST_COLLCINODE,
    HICUM_QUEST_BASEBPNODE,
    HICUM_QUEST_BASEBINODE,
    HICUM_QUEST_EMITEINODE,
    HICUM_QUEST_SUBSSINODE,
    HICUM_QUEST_XFNODE,
    HICUM_QUEST_XF1NODE,
    HICUM_QUEST_XF2NODE,
/* temperature */
    HICUM_QUEST_TK,
    HICUM_QUEST_DTSH,
/* voltages */
    HICUM_QUEST_VBE,
    HICUM_QUEST_VBBP,
    HICUM_QUEST_VBC,
    HICUM_QUEST_VCE,
    HICUM_QUEST_VSC,
    HICUM_QUEST_VBIEI,
    HICUM_QUEST_VBPBI,
    HICUM_QUEST_VBICI,
    HICUM_QUEST_VCIEI,
/* currents */
    HICUM_QUEST_CC,
    HICUM_QUEST_CAVL,
    HICUM_QUEST_CB,
    HICUM_QUEST_CE,
    HICUM_QUEST_CS,
    HICUM_QUEST_CBEI,
    HICUM_QUEST_CBCI,
/* resistances */
    HICUM_QUEST_RCX_T,
    HICUM_QUEST_RE_T,
    HICUM_QUEST_IT,
    HICUM_QUEST_RBI,
    HICUM_QUEST_RB,
/* transconductances and capacitances */
    HICUM_QUEST_BETADC,
    HICUM_QUEST_GMI,
    HICUM_QUEST_GMS,
    HICUM_QUEST_RPII,
    HICUM_QUEST_RPIX,
    HICUM_QUEST_RMUI,
    HICUM_QUEST_RMUX,
    HICUM_QUEST_ROI,
    HICUM_QUEST_CPII,
    HICUM_QUEST_CPIX,
    HICUM_QUEST_CMUI,
    HICUM_QUEST_CMUX,
    HICUM_QUEST_CCS,
    HICUM_QUEST_BETAAC,
    HICUM_QUEST_CRBI,
/* transit time */
    HICUM_QUEST_TF,
    HICUM_QUEST_FT,
    HICUM_QUEST_ICK,
/* power */
    HICUM_QUEST_POWER,
};

/* model questions */
enum {
    HICUM_MOD_COLLCONDUCT = 301,
    HICUM_MOD_BASECONDUCT,
    HICUM_MOD_EMITTERCONDUCT,
    HICUM_MOD_SUBSTRATECONDUCT,
    HICUM_MOD_TYPE,
};

#include "hicum2ext.h"
#endif /*HICUM*/
