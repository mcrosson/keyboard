# QMK Notes

## Inspiration

- https://git.sr.ht/~sungo/qmk_userspace/tree/main

## Compiling

``` sh
qmk compile -kb tidbit -km kemonine
```

## Docker Critical

### Docker Run

``` sh
# PowerShell
#     Use ` instead of \
#     Use ${PWD} instead of $(pwd)
docker run --rm -it \
  -v qmk_firmware:/qmk_firmware \
  -v $(pwd)/.build:/qmk_firmware/.build \
  -v $(pwd)/kemonine:/qmk_firmware/users/kemonine \
  qmkfm/qmk_cli /bin/bash
 ```

### Update / Clone Sources

``` sh
# PowerShell
#     Use ` instead of \
docker run --rm -it `
  -v qmk_firmware:/qmk_firmware \
  qmkfm/qmk_cli /bin/bash

cd /qmk_firmware
if [ -d .git ]; 
then 
git pull; 
else 
git clone https://github.com/qmk/qmk_firmware.git .; 
fi
cd /qmk_firmware/keyboards/nullbitsco
if [ -d tidbit ];
then
cd tidbit;
git pull;
else
git clone https://github.com/nullbitsco/tidbit tidbit
fi
```

### Docker Volumes

#### QMK Sources

`qmkfm/qmk_cli` lacks sources. Use named volume to speed dev and output

#### KemoNine

Need to have the `qmk/users/kemonine` directory mounted at `/qmk_firmware/users/kemonine` in Docker container

#### Build output

Need to have a local dir for build artifact extraction at `/qmk_firmware/.build`
