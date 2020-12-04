# ZMK Notes for Tidbit

## Docker Volume

Need to have the `zmk-config` directory mounted at `/root/zmk-config` in Docker container

## Building

``` sh

west build -p --board nice_nano -d build/tidbit/ -- -DSHIELD=tidbit -DZMK_CONFIG="/root/zmk-config/config"

```
