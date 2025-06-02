# Project journal

## Project description

The **Tinker Console** is an interactive, play-focused control panel designed for children, inspired by factory dashboards, rocket launch consoles, and audio mixing boards. Built around an ESP8266 NodeMCU, the panel features multiple buttons, a potentiometer, a strip of nine Neopixel LEDs, and two buzzers.

The main goal is to spark curiosity and give the child something tactile to play with. When the child presses a button, turns the knob, or triggers any input, the console responds with colorful lighting effects and simple sounds, creating an engaging “cause-and-effect” experience.

![Illustration drawing of a child playing with the Tinker Console](/docs/pics/illustration.png)

## Making the prototype

The first step was to wire up all the components, make sure I could get them to work properly, and make the basic code for controlling them. This is the wiring diagram with the basic components on breadboards.

I used [Fritzing](https://fritzing.org/) to draw the diagram.

![Diagram of breadboard setup for prototyping](/docs/diagrams/breadboard.png)

Here is a video of the prototype in action, with some early code:

https://github.com/kvalle/tinker-console/raw/refs/heads/main/docs/pics/breadboard-prototype.mov

## Preparing for soldering

To prepare for soldering I made a simple scematic diagram by hand, to make an overview of all the connections. It's not pretty, but helpful for the next step.

![Scematic diagram drawn by hand](/docs/diagrams/scematic.png)

Based on this, I prepared the layout for the veroboard/stripboard. I used [DIY Layout Creator](https://github.com/bancika/diy-layout-creator) to draw this.

![Diagram of veroboard layout for soldering](/docs/diagrams/vero.png)
