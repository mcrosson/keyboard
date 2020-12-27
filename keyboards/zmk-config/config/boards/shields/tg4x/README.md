# TG4X

Standard setup for the [TG4X](https://github.com/MythosMann/tg4x/) 40% keyboard.

The `keymap` directory contains the keyboard layout and were created by [Keyboard Layout Editor](http://www.keyboard-layout-editor.com/). Please note: the zmk keymap is slightly adjusted from the default shown on the main TG4X pages and QMK.

## Alternate Builds

The `tg4x_mdk` shield is setup to use the MakerDiary MDK board as a dongle for the TG4X. This will setup the TG4X as a split ZMK keyboard. The "peripheral half" will be the TG4X and the "controller half" will be the MDK.

## Build Commands

Below are the three commands that can be used to build ZMK for the TG4X as a stand alone board or with a MakerDiary MDK as a dongle.

``` sh

# Stand alone build
west build --board nice_nano -d build/tg4x/default -- -DSHIELD=tg4x -DZMK_CONFIG=/workspaces/zmk-config/keyboards/zmk-config/config

# MDK Dongle build
west build --board nrf52840_mdk -d build/tg4x/mdk -- -DSHIELD=tg4x_mdk -DZMK_CONFIG=/workspaces/zmk-config/keyboards/zmk-config/config

# TG4X as a peripheral to the MDK
west build --board nice_nano -d build/tg4x/peripheral -- -DSHIELD=tg4x_peripheral -DZMK_CONFIG=/workspaces/zmk-config/keyboards/zmk-config/config

```
