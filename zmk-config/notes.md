# Boards to Shelve

Keep "handy"

- lily58 pro
- m60
- lynepad

# Chording/Steno

Start with tidbit
ARTSEY: https://www.artsey.io/_FILES/images/ARTSEY.jpg
Beluga board : https://github.com/keyboard-magpie/belugaboard
Mod beluga for tilt encoder + thumb switch?
ASETNIOP
	http://asetniop.com/layouts/
	http://asetniop.com/combinations/

# LEDs

Generic behavior for led on/off via gpio (see pocket type / mdk personal sources for ideas)

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

# Hardware To Do / Notes

## Mini mouse pad / track pad

- Adafruit itsybitsy nrf
	- https://github.com/nuxiom/zmk/tree/60split
- ItsyBitsy lipo backpack
	- pins like nice!nano for quick swap of battery / removal of battery
- 110mAh battery
	- soldered to short mill max socket for hot swap / removal from lipo backpack
- Largest trackpad ordered
- Blue led indicate charging status (same as nice!nano)
- Dotstar red if unpaired
- Dotstar yellow if disconnected
- Dotstar green if connected
- Dotstar blue if pairing
- Push and hold button to clear BT profile
- Tap button to connect to default BT profile

# VS Code Documentation

- Command Pallet -> Run Task -> npm -> Shows list of npm build tasks for the docs
- code @ the container command line will open a file directly within code on the main machine

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