# Mill Max Sockets

A way to adapt your through hole PCB to hot swap sockets. Handy for keyboard PCB's to hot swap.

Site: https://www.mill-max.com/

Detailed breakdown from reddit [post](https://www.reddit.com/r/MechanicalKeyboards/comments/cbykxw/millmax_socket_guide_pxlnght/)

## SOCKET INFORMATION

The three viable sockets I've found are 0305, 7305, and 0279. All three work, but all 3 have benefits/drawbacks.

**0305** - These are reasonably cheap, and fit damn near any keyboard. Compared to the 7305, they have a thicker lip, but in my experience this has caused no issues (stablizers return properly). The drawbacks to this socket are it's long tail. If you're using a board with very tight spacing, they may be too tall and touch the bottom of the board. You can fix this by sanding the bottoms, but that's a lot of work. P/N used: 0305-2-15-80-47-80-10-0

**7305** - These are just about identical to the 0305, but they have a shorter tail and shorter lip. The short tail makes them ideal for those tight builds I mentioned before. They're gold plated depending on the exact model you select. These are one size fits all, but they're annoying as heck to install due to the short tail. When I buy these, I always buy 10 extra because it's nearly impossible to get through an entire build without borking a few and getting solder inside. P/N used: 7305-0-15-15-47-27-10-0

**0279** - These are neat, I've started using them recently. They have very long closed tails, and hexagonal lips before the main lip to secure itself in place. No solder required (disclaimer: solder required anyways). If you've got a PCB with nice tolerances on the switch holes, you can press these into place with zero problems. Now, realizing we're not in a perfect world, the tolerances are never perfect. Some holes are too small. When you push fit these into a smaller hole, they expand the hole and frick the heck out of the leads. You'll need to make a jump from a nearby switch to fix this. I've done 2 boards with these sockets and both needed 2 jumps. I use them anyways because it's much faster to install these and jump them afterwards (45mins-1hour) than to solder in 0305's or 7305's (like 2 hours or more). The speed scales with the # of switches you have to solder. Fullsize boards are a BREEZE with these, lemmie tell ya. THESE ARE NOT A GOOD OPTION IF YOUR PCB DOES NOT HAVE CIRCULAR HOLES. P/N used: 0279-0-15-01-47-27-10-0

## BUYING TIPS

Utilize GBs where you can, of course, as it'll be much cheaper than buying on your own. If you can't, use Octopart to find the cheapest place you can snag the sockets. When I buy sockets, I tend to toss all 3 part numbers into Ocotopart and pick the cheapest one. I also tend to look at other sockets that are similar, and if I consider them viable I give those a go. Frankly, when a socket becomes popular, the price of the socket shoots up. If you're the first person to find a viable socket, you're in luck bucko, get some cheap while you can.

If you want to run a GB, ask me and I'll add a GB section to this 'guide'.

## INSTALL TIPS

For all soldering: use a small tip and use thin solder. I use kester 0.031 in. 24-6337-0027

- 0305 and 7305
  1. Put sockets on a switch.
  1. Insert switch where it belongs, with sockets on the legs.
  1. Solder sockets.
  1. Remove switch
  1. Repeat 1-4 until done. Use like 10 switches at a time. Use switches you don't care about so that when you inevitably solder a socket into it, it's no biggie.
- 0305 and 7305 help
  1. Solder inside socket, but you can remove the switch:
  1. Take iron, press it onto the back of the socket. This will push it out a bit after it heats up. Remove iron. Stand PCB on it's side, use tweezers or whatever you've got, hold onto the top of the socket, and press the iron on the back of the socket again. Once it heats up, use the tweezers or whatevs to pull the socket out. Use the hand with the tweezers to push on the PCB if needed.
  1. Solder inside socket, and you CANT remove the switch:
  1. Heat up the socket and pull on the switch until it comes out. Usually the socket will come out with the switch and you can just toss it in the garbage. If the socket stays, but the switch comes out, see #1.
  1. Socket isn't flush with board.
  1. Rest 250C iron on the top of the socket for about 1 second. Push socket down with conservative force. Should go down fairly easily. Wait longer than a second for the solder to melt if needed. Don't push too hard.
- 0279
  1. Make sure PCB is placed on top of something so there's room to press the sockets in.
  1. Place sockets in holes via hand or tweezer.
  1. Heat iron to about 250C.
  1. Rest iron on socket for about 1 second.
  1. Push socket into hole.
  1. Repeat 0-4 until done.
  1. Check all switches for continuity. Make jumps where needed.

## RANDOM TIPS

- When you put keycaps on your stablizers, it might push the PCB off of the switches. I like to leave the board open until switches AND caps are installed, push everything to fit again, then close up the case.
- God tier QOL upgrade: add something non-conductive underneath the PCB to prevent the above issue and just to keep the PCB from backing off in general. Bumpons or shelf liner are great for this.
- Related to above: if you have a floating PCB that's held on mainly by the switches (Helix, Lets Split, idk others too probably) DEFINITELY do the above 'upgrade'. It makes a world of difference, because the PCB actually stays on when inserting and removing switches lol. Just leave the 4 corners in when swapping switches, put the new ones in, and swap the corners last. Much easier to work with this way. I use bumpons for my Helix.

## ADDITIONAL TIP

Your soldering method is actually way too time consuming with the use of switches. Plus you run the risk of soldering the switch and socket together as you've mentioned. What I typically do is:

- prop up the PCB on both sides (just so that the sockets later on won't get pushed up. I just use two rubber erasers)
- insert the sockets into the PCB through holes (one row at a time)
- use a long strip of electrical tape to secure the sockets to the PCB (one row at a time)
- give the tape a good rub up top to ensure the sockets are flush to the PCB (should be fairly obvious when it is, since you see the ring outline on the tape)
- flip the PCB over
- solder in all the sockets
- rip off the electrical tape and if you use good tape, you can re-use the same tape for the next row
- repeat the steps above

For the trickier PCB holes, you may need to isolate them with their own piece of electrical tape so that they're flush and positioned correctly. With enough practice, you can choose to tape down all the sockets and flip it over and solder them all in one go. Bit of a waste of tape though.