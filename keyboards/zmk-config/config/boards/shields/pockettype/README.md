# PocketType!

Standard setup for the [PocketType!](https://mechboards.co.uk/shop/kits/pockettype/) mini keyboard.

The `keymap` directory contains the keyboard layout and were created by [Keyboard Layout Editor](http://www.keyboard-layout-editor.com/). Please note: the zmk keymap is slightly adjusted from the default shown on the main PocketType! pages and QMK.

## Alternate Builds

The `pockettype_mdk` shield is setup to use the MakerDiary MDK board as a dongle for the Pockettype!. This will setup the PocketType! as a split ZMK keyboard. The "peripheral half" will be the Pockettype! and the "controller half" will be the MDK.

## Build Commands

Below are the three commands that can be used to build ZMK for the Pockettype! as a stand alone board or with a MakerDiary MDK as a dongle.

``` sh

# Stand alone build
west build --board nice_nano -d build/pockettype/default -- -DSHIELD=pockettype -DZMK_CONFIG=/workspaces/zmk-config/keyboards/zmk-config/config

# MDK Dongle build
west build --board nrf52840_mdk -d build/pockettype/mdk -- -DSHIELD=pockettype_mdk -DZMK_CONFIG=/workspaces/zmk-config/keyboards/zmk-config/config

# Pockettype as a peripheral to the MDK
west build --board nice_nano -d build/pockettype/peripheral -- -DSHIELD=pockettype_peripheral -DZMK_CONFIG=/workspaces/zmk-config/keyboards/zmk-config/config

```
