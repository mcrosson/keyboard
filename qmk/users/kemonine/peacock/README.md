# QMK User Dir For Peacock Trackpad

My personal QMK Peacock trackpad userspace

## General Info

- Hardware: [link](https://github.com/george-norton/peacock)
- Additional notes: [link](https://github.com/george-norton/peacock/discussions/13)
- Forked layout: [link](https://github.com/george-norton/qmk_firmware/blob/multitouch_experiment/keyboards/georgen/peacock/keymaps/default)

### Layouts

#### minimal

The bare minimum I find reasonable for use with the Peacock trackpad. This assumes the encoders do *not* 'click' and that the device will be used ambidexterously (ie. with both hands).

Color / themeing is setup to compliment a black case, black caps and black encoder knobs with the purple PCBs from SaberKeeps.

## Docker

``` powershell
docker run --rm -it `
-v S:\src\qmk_trackpad:/qmk_firmware `
-v S:\src\qmk_peacock_kmn:/qmk_peacock_kmn `
qmkfm/qmk_cli:latest
```

## Prep

### Sources

1. Clone `https://github.com/george-norton/qmk_firmware/`
1. Checkout `multitouch_experimental` branch
1. Clone this repo

### QMK Build Env

``` shell
cd /qmk_firmware
qmk setup
qmk compile -kb georgen/peacock/v1_01 -km default
```

## Building Layouts

``` shell
cd /qmk_peacock_kmn
qmk config user.overlay_dir="$(realpath .)"
qmk userspace-list
qmk compile -kb georgen/peacock/v1_01 -km [layout]
```
