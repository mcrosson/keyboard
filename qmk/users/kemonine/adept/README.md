# QMK User Dir For Ploopy Adept Trackball

My personal QMK Ploopy Adept trackball userspace

## General Info

- Hardware: [link](https://github.com/ploopyco/adept-trackball)
- Forked layout: [link]https://github.com/vial-kb/vial-qmk/tree/vial/keyboards/ploopyco/madromys)

## Docker

``` powershell
docker run --rm -it `
-v S:\src\vial-qmk:/qmk_firmware `
-v S:\src\qmk_adept_kmn:/qmk_adept_kmn `
qmkfm/qmk_cli:latest
```

## Prep

### Sources

1. Clone `https://github.com/vial-kb/vial-qmk.git`
1. Clone this repo

### QMK Build Env

``` shell
cd /qmk_firmware
qmk setup
qmk compile -kb ploopyco/madromys/rev1_001 -km vial
```

## Building Layouts

``` shell
cd /qmk_adept_kmn
qmk config user.overlay_dir="$(realpath .)"
qmk userspace-list
qmk compile -kb ploopyco/madromys/rev1_001 -km vial_kmn
```
