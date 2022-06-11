# ZMK Notes

## Docker Volume

Need to have the `zmk-config` directory mounted at `/workspaces/zmk-config` in Docker container

## git commit linting setup

Issue 575 on GitHub

``` sh
# cd /path/to/zmk
npm install --save-dev @commitlint/{cli,config-conventional}
echo "module.exports = {extends: ['@commitlint/config-conventional']};" > commitlint.config.js
npm install --save-dev husky@next
npm install pinst --save-dev
npx husky install
npx husky add .husky/commit-msg "npx --no-install commitlint --edit $1"
npx commitlint --from HEAD~1 --to HEAD --verbose
touch foo
git commit -m "foo: this will fail"
git commit -m "chore: lint on commitmsg"
git reset HEAD~1
rm foo

```

## Building

``` sh

-DCMAKE_EXPORT_COMPILE_COMMANDS=1

west build --board nice_nano -d /workspaces/zmk/app/build/settings_reset -- -DSHIELD=settings_reset

west build --board nice_nano_v2 -d /workspaces/zmk/app/build/nibble/nnv2 -- -DSHIELD=nibble -DZMK_CONFIG=/workspaces/zmk-config/kemonine/zmk-config/config

west build --board nice_nano_v2 -d /workspaces/zmk/app/build/nibble/nnv1 -- -DSHIELD=nibble -DZMK_CONFIG=/workspaces/zmk-config/kemonine/zmk-config/config


west build --board nice_nano_v2 -d /workspaces/zmk/app/build/tidbit -- -DSHIELD=tidbit -DZMK_CONFIG=/workspaces/zmk-config/kemonine/zmk-config/config

west build --board nice_nano -d /workspaces/zmk/app/build/the_paintbrush_left -- -DSHIELD=the_paintbrush_left -DZMK_CONFIG=/workspaces/zmk-config/zmk-artsey/config

west build --board nice_nano_v2 -d /workspaces/zmk/app/build/the_paintbrush_left_nn_v2 -- -DSHIELD=the_paintbrush_left -DZMK_CONFIG=/workspaces/zmk-ardux/config

west build --board nice_nano -d /workspaces/zmk/app/build/the_paintbrush_right -- -DSHIELD=the_paintbrush_right -DZMK_CONFIG=/workspaces/zmk-config/zmk-artsey/config

west build --board nice_nano_v2 -d /workspaces/zmk/app/build/the_paintbrush_right_nn_v2 -- -DSHIELD=the_paintbrush_right -DZMK_CONFIG=/workspaces/zmk-config/zmk-artsey/config

west build --board nice_nano -d /workspaces/zmk/app/build/corne_5_col_artsey_left_big -- -DSHIELD=corne_5_col_artsey_left_big -DZMK_CONFIG=/workspaces/zmk-config/zmk-artsey/config

west build --board nice_nano -d /workspaces/zmk/app/build/corne_5_col_artsey_right_big -- -DSHIELD=corne_5_col_artsey_right_big -DZMK_CONFIG=/workspaces/zmk-config/zmk-artsey/config

west build --board nrf52840_mdk_dongle -d build/pockettype/central -- -DSHIELD=pockettype_central -DZMK_CONFIG=/workspaces/zmk-config/kemonine/zmk-config/config

west build --board nice_nano -d build/pockettype/peripheral -- -DSHIELD=pockettype_peripheral -DZMK_CONFIG=/workspaces/zmk-config/kemonine/zmk-config/config

west build --board nice_nano -d build/tg4x -- -DSHIELD=tg4x -DZMK_CONFIG=/workspaces/zmk-config/kemonine/zmk-config/config

west build --board nice_nano -d /workspaces/zmk/app/build/7skb_left -- -DSHIELD=7skb_left -DZMK_CONFIG=/workspaces/zmk-config/kemonine/zmk-config/config

west build --board nice_nano -d /workspaces/zmk/app/build/7skb_right -- -DSHIELD=7skb_right -DZMK_CONFIG=/workspaces/zmk-config/kemonine/zmk-config/config

west build --board nice_nano -d build/miryoku/corne_left -- -DSHIELD=corne_left -DZMK_CONFIG=/workspaces/miryoku/config

west build --board nice_nano -d build/miryoku/corne_right -- -DSHIELD=corne_right -DZMK_CONFIG=/workspaces/miryoku/config

west build --board nice_nano -d build/pockettype/default -- -DSHIELD=pockettype -DZMK_CONFIG=/workspaces/zmk-config/kemonine/zmk-config/config

west build --board nrf52840_mdk_dongle -d build/mdk_dongle -- -DSHIELD=mdk_dongle -DZMK_CONFIG=/workspaces/zmk-config/kemonine/zmk-config/config

west build --board nice_nano -d build/pockettype/default -- -DSHIELD=pockettype -DZMK_CONFIG=/workspaces/zmk-config/kemonine/zmk-config/config

west build --board nice_nano_v2 -d /workspaces/zmk/app/build//tidbit_artsey_left -- -DSHIELD=tidbit_artsey_left -DZMK_CONFIG=/workspaces/zmk-config/zmk-artsey/config

west build --board nice_nano -d /workspaces/zmk/app/build//tidbit_artsey_right -- -DSHIELD=tidbit_artsey_right -DZMK_CONFIG=/workspaces/zmk-config/zmk-artsey/config

west build --board nice_nano -d /workspaces/zmk/app/build/navi10 -- -DSHIELD=navi10 -DZMK_CONFIG=/workspaces/zmk-config/kemonine/zmk-config/config

west build --board nice_nano -d /workspaces/zmk/app/build/corne_left -- -DSHIELD=corne_left -DZMK_CONFIG=/workspaces/zmk-config/kemonine/zmk-config/config

west build --board nice_nano -d /workspaces/zmk/app/build/corne_right -- -DSHIELD=corne_right -DZMK_CONFIG=/workspaces/zmk-config/kemonine/zmk-config/config

west build --board nice_nano -d /workspaces/zmk/app/build/lily58_left -- -DSHIELD=lily58_left -DZMK_CONFIG=/workspaces/zmk-config/kemonine/zmk-config/config

west build --board nice_nano -d /workspaces/zmk/app/build/lily58_right -- -DSHIELD=lily58_right -DZMK_CONFIG=/workspaces/zmk-config/kemonine/zmk-config/config

west build --board itsybitsy_nrf52840 -d build/azarashi64/left -- -DSHIELD=azarashi64_left -DZMK_CONFIG=/workspaces/zmk-config/kemonine/zmk-config/config

west build --board itsybitsy_nrf52840 -d build/azarashi64/right -- -DSHIELD=azarashi64_right -DZMK_CONFIG=/workspaces/zmk-config/kemonine/zmk-config/config

```
