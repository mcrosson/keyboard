# Test notes

development/guides/tests

cd app
west test tests/to-layer/normal

add to app/tests/[folder]

fill in behavior_keymap.dtsi with appropriate keymap for testing
setup native_posix.keymap for the order of events you want to run (these will spit out events that become the test case)
fill in keycode_events.snapshot with the proper values after running the native_posix.keymap with appropriate output for the events expected
	remove the "+" prefix from the lines in the snapshot (should read like kp_pressed: and kp_released: on each line)
	you need a new line at the end of the snapshot file


# ItsyBitsy Bring Up

https://github.com/nuxiom/zmk/tree/60split

# Sleep / Blank

Also apply to underglow if Pete doesn't get there first

# Docker container use less instead of more

- need to install 'less' package
- need to set PAGER env var to 'less'
- submit as pr to zmk-docker repo AFTER testing locally

# Local github CI actions run

See https://github.com/nektos/act as a potential way to run local GH actions ahead of opening a PR

# Documentation ideas

Container tests
- west update
- git status
- nano -w .git/config
- cd docs
- npm ci
- npm run prettier:format
- npm run prettier:check
- npm run lint
- npm run build
- npm run start # Verify this works with http://localhost:3000
- cd ../app
- clang-format -i app/**/*.c
- clang-format -i app/**/*.h
- west build --board nice_nano -- -DSHIELD=tidbit -DZMK_CONFIG=/workspaces/zmk-config/keyboards/zmk-config/config
- west build -d build/ -t rom_report
- west build -d build/ -t ram_report
- west build -t menuconfig

# Dyanmic Layer Actions

- look at hold tap implementation for inspiration (keymap file poprtion)

- hooks for BOTH activate and de-activate

- change underglow color
- fire key press


	keymap {
		compatible = "zmk,keymap";

		default_layer {
			activate-behaviors = <
	            &rgb_ug sethsv (128, 255, 64) &kp NUM_LOCK
			>;
		};
	};

# Workspace documentation

finalize devcontainer-setupworkspace branch, may have existing PR open

# Mouse Keys

- see keymap for codes
- constant movement / accellerated option
- default accel mode (standard if unspecified)
- default speed mode (standard if unspcified)
- key code for changing accel mode (slow/standard/fast)
- key code for changing speed mode (slow/standard/fast)
- constant speed code that will momentarily activate constant speed motion
- accell speed code that will momentarily activate accell speed motion
- toggle to flip between constant and accell modes



3:51 AM
]
fischkopp
:
@innovaker what would it take to add mouse keys?
[
5:36 AM
]
innovaker
:
Hi @fischkopp, I don't believe we've spoken before?
1.  Implement a mouse report (I've already done some groundwork for that).
2.  Determine appropriate behaviours and implement them.
3.  Investigate into whether the current peripheral-to-central communication channels provide the necessary prerequisites, and if not, improve it.
4.  Probably need to implement a system that sits in-between the behavior and the reports which caters for inputs from multiple sources and amalgamates them.  I've been told this is a vital aspect that can be easily overlooked.
It's fairly easy to hack out a proof-of-concept for this, but trickier to engineer the system(s) we should be aiming for.
Are you looking to get involved?
[
5:37 AM
]
fischkopp
:
Yeah I'm interested in that
[
5:38 AM
]
fischkopp
:
but i'm actually not sure I understand what makes mouse key implementation so complex
[
5:38 AM
]
innovaker
:
Most of the steps require consideration of the big picture (because this is effectively a new type of input that we haven't built around yet, so we consider how it all fits together), but if you want to get a head start and make a prototype that would be really useful.
[
5:39 AM
]
fischkopp
:
(not really usually doing much embedded work besides getting android to run on platforms)
[
5:39 AM
]
innovaker
:
my understanding is that it's the multiple inputs to single output + acceleration which are the complicating factors
[
5:39 AM
]
innovaker
:
there's only one pointer output - with axes X and Y
[
5:40 AM
]
innovaker
:
but there could be numerous inputs to that, both sensors (controls) and keys which could need unifying
[
5:40 AM
]
innovaker
:
and you're doing binary to linear conversion using a stateful system that requires "natural" acceleration to feel right
[
5:40 AM
]
innovaker
:
so effectively a curve (perhaps even with a degree of hysteresis?  I don't know)
[
5:40 AM
]
innovaker
:
none of which is currently supported by ZMK
[
5:42 AM
]
innovaker
:
if we had a working prototype to iterate on, it would make it easier to nail down those aspects and design/implement the necessary prerequisites into ZMK.
[
5:42 AM
]
innovaker
:
I just haven't got onto it yet (there's other priorities at the moment).
[
5:42 AM
]
innovaker
:
You're most welcome to get it kick started tho!
[
5:43 AM
]
innovaker
:
and trail blaze it if you're capable
[
5:44 AM
]
innovaker
:
I doubt the naive solution of "hold UP to make Y increase at a constant rate" would be practical from what others have told me, but that's probably the first objective/target to shoot for.  It would give us a better vantage point for moving forward.
[
5:49 AM
]
innovaker
:
any thoughts on that @fischkopp?
[
5:50 AM
]
fischkopp
:
i don't know I personally like the constant rate more
  
[
5:50 AM
]
innovaker
:
as I say, that's the first goal post/marker, you're welcome to implement it
[
5:50 AM
]
fischkopp
:
I'll just need to add support for my keyboard mcu first
[
5:50 AM
]
innovaker
:
just keep in mind the big picture as you make design choices
[
5:52 AM
]
innovaker
:
there are also others interested in this area, so if you break ground then I'll give them a shout so that they can be involved if they want to be