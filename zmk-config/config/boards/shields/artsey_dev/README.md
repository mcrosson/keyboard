# ARTSEY Dev

A dev/test board designed by crides for testing ARTSEY keymaps.

ZMK Build command (devcontainer): `west build --board nice_nano -d build/artsey_dev -- -DSHIELD=artsey_dev -DZMK_CONFIG=/workspaces/zmk-config/config`

**WARNING**

Needs ZMK [PR 661](https://github.com/zmkfirmware/zmk/pull/661) to work correctly.
