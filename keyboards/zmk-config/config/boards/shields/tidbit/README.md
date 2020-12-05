# Building ZMK for the Tidbit

Some general notes/commands for building standard Tidbit layouts from the assembly documentation.

## Standard "Non Dense" Build

```

west build -p --board nice_nano -d build/tidbit/default -- -DSHIELD=tidbit

```

## Dense "19 keys" Build

```

west build -p --board nice_nano -d build/tidbit/19_key -- -DSHIELD=tidbit_19key

```

## LED Notes

If you built your tidbit without the LEDs *and* are using a Nice!Nano board, you'll need to add the following at the *end* of your local tidbit config.

```

CONFIG_ZMK_RGB_UNDERGLOW=n
CONFIG_WS2812_STRIP=n

```

## Encoder Notes

If you built your tidbit without encoders, you'll need to add the following at the *end* of your local tidbit config.

```

CONFIG_EC11=n
CONFIG_EC11_TRIGGER_GLOBAL_THREAD=n

```

## OLED Builds

If using an OLED screen you'll need to include the following at the *end* of your local tidbit config.

```
CONFIG_ZMK_DISPLAY=y

```
