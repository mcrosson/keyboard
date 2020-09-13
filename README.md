# mdloader

A fork of the main [mdloader](https://github.com/Massdrop/mdloader) repo that has some tweaks so users can re-build ```mdloader``` with the proper chip id of their keyboard.

## Organization

- The ```firmware``` folder has pre-compiled firmware as well as screen shots of the board layout
- The ```src_mdloader``` folder has a copy of the ```mdloader 1.0.3``` release

## Source Tweaks

- This code has had the following chip id's added so others don't have to add them
  - ```0x60060006```
  - ```0x60060305```
  - ```0x60060306```
  - ```0x60060005```

## Using

To work with this repo build and run the ```mdloader``` tool with ```--list```. I have patched the code to show *all* of the chip ids for boards found. Once you have the chip id, edit ```mdloader_common.c``` and change the chip id as necessary. Rebuild the tool and run per the standard documentation.

# Licensing

Unless otherwise stated all source code is licensed under the [Apache 2 License](LICENSE-APACHE-2.0.txt).

Unless otherwise stated the non source code contents of this repository are licensed under a [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License](LICENSE-CC-Attribution-NonCommercial-ShareAlike-4.0-International.txt)
