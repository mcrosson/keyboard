# Keyboards

Various sources and information on how KemoNine has setup their keyboards and macro pads.

## Organization

- The ```notes``` folder has various notes KemoNine has taken while working on keyboard stuff
- The ```keyboards``` folder has KemoNine's keyboard/macro pad setups
- The ```qmk``` folder has KemoNine's QMK work (see below section for more information)

## Source Tweaks

- The ```qmk``` sources have KemoNine's massdrop alt configuration/keymap
- The ```qmk``` sources have KemoNine's port of QMK for the Qvex Lynepad

## mdloader

Given Drop *finally* updated their mdloader sources for more recent keyboard revisions the fork that was previously hosted here has been removed. Please use the upstream sources and builds.

## Building mdloader on Windows

*Please note:* This section has been retained for those who may need/want to build mdloader from the official sources.

1. Install Chocolatey
    * See https://chocolatey.org/install for details on how to install Chocolatey
1. Install build tools via Administrator Powershell window: ```choco install make mingw gnuwin32-coreutils.portable```
    - make : for the Makefile included with mdloader
    - mingw : for gcc, the compiler used to build mdloader binaries
    - gnuwin32-coreutils.portable : for rm, used by the Makefile included with mdloader

## Licensing

Unless otherwise stated all source code is licensed under the [Apache 2 License](LICENSE-APACHE-2.0.txt).

Unless otherwise stated the non source code contents of this repository are licensed under a [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License](LICENSE-CC-Attribution-NonCommercial-ShareAlike-4.0-International.txt)
