# Keyboards

Various sources and information on how KemoNine has setup their keyboards and macro pads.

## Organization

- The ```firmware``` folder has pre-compiled firmware as well as screen shots of the board layout
- The ```mdloader``` folder has a copy of the ```mdloader 1.0.3``` release that's been patched to work with more keyboard chip ids than massdrop provides
- The ```keyboards``` folder has KemoNine's keyboard/macro pad setups

## Source Tweaks

- The ```qmk``` sources have KemoNine's massdrop alt configuration/keymap
- The ```mdloader``` code has had the following chip id's added so others don't have to add them
  - ```0x60060006```
  - ```0x60060305```
  - ```0x60060306```
  - ```0x60060005```

## Using mdloader

To work with this repo's fork of mdloader, build and run the ```mdloader``` tool with ```--list```. I have patched the code to show *all* of the chip ids for boards found. Once you have the chip id, edit ```mdloader_common.c``` and change the chip id as necessary. Rebuild the tool and run per the standard documentation.

## Licensing

Unless otherwise stated all source code is licensed under the [Apache 2 License](LICENSE-APACHE-2.0.txt).

Unless otherwise stated the non source code contents of this repository are licensed under a [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License](LICENSE-CC-Attribution-NonCommercial-ShareAlike-4.0-International.txt)
