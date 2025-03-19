To build personal corne remix from source:

```
qmk compile \
    -e ALLOW_WARNINGS=yes \
    -e ARDUX_SIZE=40p \
    -e ARDUX_HAND=left \
    -e ARDUX_LAYER_UNDERGLOW=yes \
    -e ARDUX_REMIX=yes \
	-e CONVERT_TO=kb2040 \
	-e OLED_ENABLE=no \
	layout/crkbd_rev1_40p.json
```
