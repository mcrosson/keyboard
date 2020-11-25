west build -p --board nice_nano -d build/tidbit/default -- -DSHIELD=tidbit

west build -p --board nice_nano -d build/tidbit/19_keys -- -DSHIELD=tidbit -DKEYMAP_FILE=${PWD}/boards/shields/tidbit/tidbit_19key.keymap
