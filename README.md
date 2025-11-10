# Tinker Console

This repo holds the files used to crate the Tinker Console (norwegian title "Fiklepanelet"), such as the code, wiring diagram, files for laser cutting, etc.

The the process of making the console is described through the [project journal](project-journal.md).

## What is the Tinker Console?

It started with my wish to make something for my daughter for her second year birthday. I envisioned a panel with LEDs, sounds, and buttons/switches she could play around with, but had only a vague idea of how it should look and function before starting to work on it.

This is the result after a few months of tinkering:

Front view:

![Front view of the finished console](/files/journal/finished-console-front.jpg)

Back view:

![Back view of the finished console](/files/journal/finished-console-back.jpg)

## What's inside?

### Components

The console uses the following parts for the electronics:

- **4 buttons** used as control inputs
- **2 passive buzzers** to play tones/short melodies
- **1 Neopixel LED strip (w/ 9 LEDs)** for showing colors based on the buttons pressed
- **1 potentiometer** used as analog input to adjust the speed of the color animations
- **An ESP8266 (NodeMCU)** microcontroller for controlling everything
- **A LiPo 103450** (rechargeable 2000mAh 3.7V battery) to power the electronics
- A **TP4056** module used as battery charger and protection circuit
- A **MT3608** module used for boosting the voltage up to 5V for the ESP
- A **power adapter** (1A 5V) for charging the battery
- **Assorted basic components** to wire everything together: Resistors, capasitors, JST-connectors, switches, DC power connector (see the [schematic](files/journal/schematic-v2.png) or [layout diagram](files/journal/vero-v4.png) for details).

### GPIO pins

The ESP is set up using hte following GPIO pins:

| Component              | Label | GPIO   | Comment                                               |
| ---------------------- | ----- | ------ | ----------------------------------------------------- |
| Button 1               | D2    | GPIO4  |                                                       |
| Button 2               | D3    | GPIO0  | **Required HIGH at boot.**                            |
| Button 3               | D5    | GPIO14 |                                                       |
| Button 4               | D6    | GPIO12 |                                                       |
| Buzzer 1 (PWM)         | D1    | GPIO5  |                                                       |
| Buzzer 2 (PWM)         | D8    | GPIO15 | **Required LOW at boot.**                             |
| Neopixel (9 LEDs)      | D4    | GPIO2  | **Required HIGH at boot.** Connected to on-board LED. |
| Potensiometer (analog) | A0    | ADC0   |                                                       |

### The software

The code is written in **pure C++** and has been developed on [PlatformIO](https://platformio.org/). A lot of the code is based on the [Automaton library](https://github.com/tinkerspy/Automaton/wiki).
