# QMK User Dir For Qvex Lynepad

My personal QMK Qvex Lynepad userspace

## General Info

- Hardware: [link](https://lynepad.com)
- Forked layout: [link](https://github.com/qmk/qmk_firmware/tree/master/keyboards/qvex/lynepad)

## Docker

``` powershell
docker run --rm -it `
-v S:\src\qmk_firmware:/qmk_firmware `
-v S:\src\qmk_kmn_lynepad:/qmk_kmn_lynepad `
qmkfm/qmk_cli:latest
```

## Boot Mode

Hold bottom center button.

## Prep

### Sources

1. Clone `https://github.com/qmk/qmk_firmware.git`
1. Clone this repo

### QMK Build Env

``` shell
cd /qmk_firmware
qmk setup
qmk compile -kb qvex/lynepad -km default
```

## Building Layouts

``` shell
cd /qmk_kmn_lynepad
qmk config user.overlay_dir="$(realpath .)"
qmk userspace-list
qmk compile -kb qvex/lynepad -km kmn
```
