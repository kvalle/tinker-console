# Project journal

## Project description

The **Tinker Console** is an interactive, play-focused control panel designed for children, inspired by factory dashboards, rocket launch consoles, and audio mixing boards. Built around an ESP8266 NodeMCU, the panel features multiple buttons, a potentiometer, a strip of nine NeoPixel LEDs, and two buzzers.

The main goal is to spark curiosity and give the child something tactile to play with. When the child presses a button, turns the knob, or triggers any input, the console responds with colorful lighting effects and simple sounds, creating an engaging “cause-and-effect” experience.

![Illustration drawing of a child playing with the Tinker Console](/docs/pics/illustration.png)

## Making the prototype

The first step was to wire up all the components, make sure I could get them to work properly, and make the basic code for controlling them. This is the wiring diagram with the basic components on breadboards.

I used [Fritzing](https://fritzing.org/) to draw the diagram.

![Diagram of breadboard setup for prototyping](/docs/diagrams/breadboard.png)

I wired the prototype up on breadboards and played around with the components until I had everything working individually.

![Picture of the breadboard setup, seen from the side](/docs/pics/breadboard-side.jpg)
![Picture of the breadboard setup, seen from above](/docs/pics/breadboard-over.jpg)

Then I made some code to make sure I could change state using the buttons, display different effects on the NeoPixel, and adjust speed on the pot.
Here is a [video of the prototype in action](https://github.com/kvalle/tinker-console/raw/refs/heads/main/docs/pics/breadboard-prototype.m4v), with some early code, making sure I have the needed parts working.

## Preparing for soldering

To prepare for soldering I made a simple schematic diagram by hand, to make an overview of all the connections. It's not pretty, but helpful for the next step.

![Schematic diagram drawn by hand](/docs/diagrams/scematic-v1.png)

Based on this, I prepared the layout for the veroboard/stripboard. I used [DIY Layout Creator](https://github.com/bancika/diy-layout-creator) to draw this.

![Diagram of veroboard layout for soldering](/docs/diagrams/vero-v1.png)

## Thinking about the enclosure

I received the big arcade machine buttons I ordered, and wanted to see how they would look on the console. The plan is to build a simple wooden box as enclosure for the project. But to make it look better the front will be laser cut from acrylic. Here is the first test cut for the panel:

![First test cut for the console front panel with buttons inserted](/docs/pics/front-panel-prototype.jpg)

## Soldering

Spent some time soldering everything up on veroboard, and have a working panel (without enclosure or battery power, for now).

![The panel running with the veroboard soldered up](/docs/pics/first-hookup-with-veroboard.jpg)
![Closeup of the assembled veroboard](/docs/pics/closeup-of-soldered-veroboard.jpg)

As seen in the photos, the panel is still powered by USB. I'm still waiting to receive the battery, so the power wiring has to wait until later.

The work did not go completely frictionless. First I found that there were differences between my diagram and the specs, making me have to double check everything before wiring. The diagram also had 3V3 and GND mixed up on the ESP, leading to some late less-than-optimal changes to the wiring.

The biggest problem encountered was that the D7 pin seems to have been fried on the ESP, working only sporadically. This took way too long to figure out, and made me change for D3 instead.

I also found out that D8, which now powers one of the buzzers, is used while uploading new code to the ESP. This makes _a lot_ of noise, which is very annoying. I might have to disconnect the buzzers when working on the code in the future, or just use some ear plugs 🙉

D8 is also high for a brief moment _before_ the `setup` function is called, making a short _beep_. Guess we'll just have to call that an accidental feature 🤷

The wiring diagram and vero layout diagrams also look a bit different now, after all the changes (and some previous thinking about batteries and power).

![Updated schematic](/docs/diagrams/scematic-v2.png)
![Updated vero diagram](/docs/diagrams/vero-v2.png)

Next steps should probably be to make a better enclosure and screw the PCBs in place.

## Building the wooden enclosure

Woodworking isn't something I have much experience with outside of making wooden boxes and the like using the laser cutter. This time I wanted a more hands-on approach, with a simple wooden box enclosure to go with the front panel in acrylic that I had already prototyped.

I experimented with different tilt angles to get the panel's incline right, and drew a simple sketch of what I thought I wanted it to look like with some measurements.

![Initial sketch of the enclosure](/docs/pics/enclosure-sketch.png)

After cutting and sanding some (somewhat) even and straight sides and a bottom piece, and gluing/screwing them together, I laser cut new panel pieces. The front panel itself is from two layers of MDF (for holding the LED strip in place) and a front layer from white acrylic. This layer has holes for the buttons, LEDs and the potentiometer.

![Enclosure assembly, without panel](/docs/pics/enclosure-box-1.jpg)
![Enclosure assembly, with panel](/docs/pics/enclosure-box-2.jpg)

I also laser cut covers for the front and top from veneer. For the back I cut a piece of clear acrylic, to make it a display window for the electronics inside.

Finally I laser cut a small veneer frame for the LED strip, and a speedometer dial for the potentiometer.

The SVG file for all the laser cut parts is available [here](/lasercutter/enclosure.svg). The parts were cut on a Epilog Zing-16 laser cutter, using these settings:

| Material    | Power | Speed | Freq   | Used for                     |
| ----------- | ----- | ----- | ------ | ---------------------------- |
| 3mm veneer  | 50%   | 80%   | 500Hz  | Top and front covers         |
| 3mm MDF     | 40%   | 60%   | 500Hz  | Panel (bottom layers)        |
| 3mm acrylic | 20%   | 100%  | 5000Hz | Panel (top layer)            |
| 4mm acrylic | 25%   | 100%  | 5000Hz | Clear back cover             |
| 1mm veneer  | 60%   | 100%  | 500Hz  | LED strip frame, speedometer |

Here are some photos of the enclosure (almost) assembled. The front/top/back are not yet screwed in, as I need to finish the electronics, but otherwise done.

![Photo of the console enclosure from the front.](/docs/pics/enclosure-assembled-front.jpg)
![Photo of the console enclosure from the back.](/docs/pics/enclosure-assembled-back.jpg)

## Battery power, part 1

The package with the battery finally arrived, and I returned to the workshop to wire up the battery circuit.

The plan for powering the console is:

- Power from a 3.7V 2000mAh battery
- Charging and battery protection circuit through the TP4056 module
- Power boost up to 5V from the MT3608 module
- On/off power switch for the console
- DC power in when charging through a standard “barrel jack”, from a 5V 1A power adapter

After reading up on the MT3608 and TP4056 modules I realized I should move the power switch in the circuit, and updated the diagram accordingly. The new plan looks like this:

![Updated diagram of veroboard layout, adjusting power circuit](/docs/diagrams/vero-v3.png)

I also decided to place the power switch and the power socket in the back panel, instead of the wooden front or top as I had originally planned.

After cutting a new acrylic plate on the laser cutter I soldered the power socket and battery up to the TP4056 module, and connected the (5V 1A) power adapter. The LED turned on, and battery is charging!

![TP4056 module charging the battery](/docs/pics/tp4056-charging-battery.jpg)

Next steps: Get the power onto the console and ESP through the MT3608 module, and mount everything in place in the enclosure.

## Battery power, part 2

After hooking up the MT3608 module to the power circuit, the console is finally powered by the battery. (Ignore the stray USB cable connected to the ESP in the photo.)

![Full charging module finished](/docs/pics/full-power-circuit-finished.jpg)

Here is a short video of the first test of the console using battery power:

![First test of console powered by the new battery circuit](/docs/pics/first-test-with-battery-power.mp4)

The parts are still hanging loose, as I don't want to commit to positioning them inside until everything is finished.

## New audio module

Even though I now had everything I needed to assemble the console, I wanted to make a new version of the audio module. The reason being that I wanted to be able to mute the sound with a physical switch, something the previous module lacked.

I _could_ have added a switch directly to the cables of the old one, but I also wanted a narrower form factor so figured I might as well make a new one.

This is the updated layout diagram:

![Updated diagram of veroboard layout, adjusting audio module](/docs/diagrams/vero-v4.png)

And here is a photo of the new audio module, now with power/mute switch.

![New audio module](/docs/pics/new-audio-module.jpg)

## Assembly

With all the parts done it was finally time to connect, screw and glue everything together.

I glued the different modules (main board, TP4056, MT3608, and audio module) to thin strips of MDF, and then glued these to the base board of the console.

The base board is screwed in place using two screws in the back, and easy to remove should I need to adjust anything later. The battery is fastened inside a frame cut into the base board, and with a strip of MDF glued on top keeping it in place as long as the base board is screwed down.

![Gluing all the electronics in place inside the console](/docs/pics/gluing-everything-in-place.jpg)

And a few photos of the finished console:

![Front view of the finished console](/docs/pics/finished-console-front.jpg)

![Back view of the finished console](/docs/pics/finished-console-back.jpg)

![View of the insides of the finished console](/docs/pics/finished-console-back-inside.jpg)

## Final coding

The console was now complete, yet still not quite functional. I had left off the coding at the point where I had enough to test that the components worked together, but not with any form of coherent functionality suitable for a toy for a 2-year-old.

After trying a few different ideas I landed on the following behavior:

- When pressing a button, the leftmost LED is set to the corresponding color.
- The color spreads to the right on the LED strip, with a speed determined by the value of the potentiometer.
- Each button has a different short sound sequence.
- When long-pressed, the buttons change the console to different "modes" for spreading the colors: From the right, from the center out, from the edges and in (and the default left to right).

[🎬 See a video of the console in action here](https://raw.githubusercontent.com/kvalle/tinker-console/main/docs/pics/finished-console-being-used.mp4)

## Delivery

The deadline (i.e. the two year birthday of my daughter) arrived, and it was time to see how well the console was received.

![Delivering the console to its intended user](/docs/pics/delivering-to-the-end-user.jpg)

She seems to enjoy hammering on the buttons. But, at least for now, it seems the on/off power switch on the back is more interesting than what's on the front panel…

Hopefully she'll enjoy playing with the console. But if not, at least it's been fun (and educational) to make.
