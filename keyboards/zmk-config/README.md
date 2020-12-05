# ZMK Notes for Tidbit

## Docker Volume

Need to have the `zmk-config` directory mounted at `/workspaces/zmk-config` in Docker container

## Building

``` sh

west build --board nice_nano -d build/tidbit . -- -DSHIELD=tidbit -DZMK_CONFIG=/workspaces/zmk-config/keyboards/zmk-config

```
