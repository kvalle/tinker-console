# Project journal

## Project description

The **Tinker Console** is an interactive, play-focused control panel designed for children, inspired by factory dashboards, rocket launch consoles, and audio mixing boards. Built around an ESP8266 NodeMCU, the panel features multiple buttons, a potentiometer, a strip of nine Neopixel LEDs, and two buzzers.

The main goal is to spark curiosity and give the child something tactile to play with. When the child presses a button, turns the knob, or triggers any input, the console responds with colorful lighting effects and simple sounds, creating an engaging “cause-and-effect” experience.

![Illustration drawing of a child playing with the Tinker Console](/docs/pics/illustration.png)

## Making the prototype

The first step was to wire up all the components, make sure I could get them to work properly, and make the basic code for controlling them. This is the wiring diagram with the basic components on breadboards.

I used [Fritzing](https://fritzing.org/) to draw the diagram.

![Diagram of breadboard setup for prototyping](/docs/diagrams/breadboard.png)

I wired the prototype up on breadboards and played around with the components until I had everything working individually.

![Picture of the breadboard setup, seen from the side](/docs/pics/breadboard-side.jpg)
![Picture of the breadboard setup, seen from above](/docs/pics/breadboard-over.jpg)

Then I made some code to make sure I could change state using the buttons, display different effects on the NeoPixel, and ajust speed on the pot.
Here is a [video of the prototype in action](https://github.com/kvalle/tinker-console/raw/refs/heads/main/docs/pics/breadboard-prototype.m4v), with some early code, making sure I have the needed parts working.

## Preparing for soldering

To prepare for soldering I made a simple scematic diagram by hand, to make an overview of all the connections. It's not pretty, but helpful for the next step.

![Scematic diagram drawn by hand](/docs/diagrams/scematic-v1.png)

Based on this, I prepared the layout for the veroboard/stripboard. I used [DIY Layout Creator](https://github.com/bancika/diy-layout-creator) to draw this.

![Diagram of veroboard layout for soldering](/docs/diagrams/vero-v1.png)

## Thinking about the enclosure

I received the big arcade machien buttons I ordered, and wanted to see how they would look on the console. The plan is to build a simple wooden box as enclsure for the project. But to make it look better the front will be laser cut from acrylic. Here is the first test cut for the panel:

![First test cut for the console front panel with buttons inserted](/docs/pics/front-panel-prototype.jpg)

## Soldreing

Spent some time soldring everything up on veroboard, and have a working panel (without enclosure or battery power, for now).

![The panel running with the veroboard soldered up](/docs/pics/first-hookup-with-veroboard.jpg)
![Closeup of the assembled veroboard](/docs/pics/closeup-of-soldered-veroboard.jpg)

As seen in the photos, the panel is still powered by USB. I'm still waiting to receive the battery, so the power wiring has to wait until later.

The work did not go completely frictionless. First I found that there were differences between my diagram and the specs, making me have to double check everything before wiring. The diagram also had 3V3 and GND mixed up on the ESP, leading to some late less-than-optimal changes to the wiring.

The biggest problem encountered was that the D7 pin seems to have been fried on the ESP, working only sporadically. This took way too long to figure out, and made me change for D3 instead.

I also found out that D8, which now powers one of the buzzers, is used while uploading new code to the ESP. This makes _a lot_ of noise, which is very annoying. I might have to disconnect the buzzers when working on the code in the future, or just use some ear plugs 🙉

D8 is also high for a brief moment _before_ the `setup` function is called, making a short _beep_. Guess we'll just have to call that an accidental feature 🤷

The wiring diagram and vero layout diagrams also look a bit different now, after all the changes (and some previous thinking about batteries and power).

![Updated scematic](/docs/diagrams/scematic-v2.png)
![Updated vero diagram](/docs/diagrams/vero-v2.png)

Next steps should probably be to make a better enclosure and screw the PCBs in place.

## Building the wooden enclosure

Woodworking isn't something I have much experience with outside of making wooden boxes and the like using the laser cutter. This time I wanted a more hands-on approach, with a simple wooden box enclosre to go with the front panel in acrylic that I had already prototyped.

I experimented with different tilt angles to get the panel's incline right, and drew a simple sketch of what I thought I wanted it to look like with some measurements.

![Initial sketch of the enclosure](/docs/pics/enclosure-sketch.png)

After cutting and sanding some (somewhat) even and straight sides and a bottom piece, and gluing/screwing them together, I laser cut new panel pieces. The front panel itself is from two layers of MDF (for holding the LED strip in place) and a front layer from white acrylic. This layer has holes for the buttons, LEDs and the potentiometer.

![Enclosure assembly, without panel](/docs/pics/enclosure-box-1.jpg)
![Enclosure assembly, with panel](/docs/pics/enclosure-box-2.jpg)

I also laser cut covers for the front and top from veneer. For the back I cut a piece of clear acrylic, to make it a display window for the electronics inside.

Finally I laser cut a small veneer frame for the LED strip, and a speedometer dail for the potentiometer.

The SVG file for all the laser cut parts is available [here](/docs/lasercutter/enclosure.svg). The parts were cut on a Epilog Zing-16 laser cutter, using these settings:

| Material    | Power | Speed | Freq   | Used for                     |
| ----------- | ----- | ----- | ------ | ---------------------------- |
| 3mm veneer  | 50%   | 80%   | 500Hz  | Top and front covers         |
| 3mm MDF     | 40%   | 60%   | 500Hz  | Panel (botton layers)        |
| 3mm acrylic | 20%   | 100%  | 5000Hz | Panel (top layer)            |
| 4mm acrylic | 25%   | 100%  | 5000Hz | Clear back cover             |
| 1mm veneer  | 60%   | 100%  | 500Hz  | LED strip frame, speedometer |

Here are some photos of the enclousre (almost) assembled. The front/top/back are not yet screwed in, as I need to finish the electronics, but otherwise done.

![Photo of the console enclosure from the front.](/docs/pics/enclosure-assembled-front.jpg)
![Photo of the console enclosure from the back.](/docs/pics/enclosure-assembled-back.jpg)
