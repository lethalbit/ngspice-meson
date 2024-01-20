> [!IMPORTANT]
> This is only a rough enough port from autoconf to meson to get the ngspice
> shared library to build on Linux, YMMV for any other use!

> [!WARNING]
> Currently the meson translation is quite rough, it's not quite a 1:1 from the
> autoconf, so things may be wonky, and not done right, and the resulting builds
> might not work at all. Not all flags are hooked up to the build, etc.

README for NGSPICE
==================

Ngspice is a mixed-level/mixed-signal circuit simulator. Its code
is based on three open source software packages: Spice3f5, Cider1b1
and Xspice.

Spice3 does not need any introduction, is the most popular circuit
simulator. In over 30 years of its life Spice3 has become a de-facto
standard for simulating circuits.

Cider couples Spice3f5 circuit level simulator to a device simulator
to provide greater simulation accuracy of critical devices. So you may
create device models for diodes, bipolar, JFet and MOSFETs derived
from their cross-sectional structures and materials.

Xspice is an extension to Spice3C1 that provides code modelling support
and simulation of digital components through an embedded event driven
algorithm.

Ngspice is, anyway, much more than the simple sum of the packages
above, as many people contributed to the project with their experience,
their bug fixes and their improvements. If you are interested, browse
the site and discover what ngspice offers and what needs. If you think
you can help, join the development team.

Ngspice is an ongoing project, growing everyday from users contributions,
suggestions and reports. What we will be able to do depends mostly on
user interests, contributions and feedback.



USER DISCUSSION FORUMS:
-----------------------

 For discussions on ngspice, there are five discussion forums, to be
 found at https://sourceforge.net/p/ngspice/discussion/. These
 typically provide quick answers to any question concerning ngspice.
 A new section on 'tips and examples' assembles useful tips provided
 by maintainers and users.



MAILING LISTS:
-------------

 There are two mailing lists dedicated to the use and development of ngspice.

 * ngspice-users@lists.sourceforge.net:
   This list is the list for the users of the ngspice simulator.

 * ngspice-devel@lists.sourceforge.net:
   ngspice development issues. Developers and "want to be" developers should
   subscribe here.

 To subscribe the list(s), send a message to:
   <ngspice-users-subscribe@lists.sourceforge.net>
   <ngspice-devel-subscribe@lists.sourceforge.net>



WEB SITEs:
--------

This project is hosted on Sourceforge.net.
The home page is https://ngspice.sourceforge.io
The page offering source code, MS Windows executables, and user interaction is
https://sourceforge.net/projects/ngspice
