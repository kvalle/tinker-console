# Specs and info

## 🔧 Components

- **4 buttons**: Used as control inputs for various functions and states.
- **2 passive buzzers**: Play tones/sections of melodies based on interaction.
- **1 potentiometer**: Used as analog input – can adjust volume, brightness, or tempo.
- **1 Neopixel LED strip (w/ 9 LEDs)**: For visual effects and status indicators.
- **ESP8266 NodeMCU**: The microcontroller that controls the entire setup.

## 💻 Development environment, limitations, and considerations

This section is mostly for Copilot :)

- Using **PlatformIO** as the development platform.
- The code is written in **pure C++**, tailored for PlatformIO (e.g., `#include <Arduino.h>` is required). If code is generated, it should be adapted accordingly.
- The code uses **millis()**, **state machines**, and optionally the **Ticker library** for multitasking and control flow, avoiding the use of `delay()`.
- Care is taken with pins that affect the boot process. Notify if adjustments are needed, such as pull-up resistors during startup.
- Attempts are made to keep I2C pins free for future use. However, if needed to accommodate all components on the best/safest pins, it is acceptable.
- `Serial` (over USB) is used for debugging the code during development. GPIO pin selection should be adjusted if it has any impact.
- When referring to GPIO pins, provide the D-number in addition to the pin number. For example, D2 (GPIO4). This is because the D-number is easier to reference when starting to connect components.
- Several components are using the Automaton library.

## 🔌 Wiring

| Component              | D-number | GPIO   | Comment                                                               |
| ---------------------- | -------- | ------ | --------------------------------------------------------------------- |
| Button 1               | D0       | GPIO16 | OK for use as button, but will require **external pull-up resistor**. |
| Button 2               | D5       | GPIO14 |                                                                       |
| Button 3               | D6       | GPIO12 |                                                                       |
| Button 4               | D7       | GPIO13 |                                                                       |
| Buzzer 1 (PWM)         | D1       | GPIO5  | Good pin for PWM, works well with `tone()`.                           |
| Buzzer 2 (PWM)         | D2       | GPIO4  | Good pin for PWM, works well with `tone()`.                           |
| Neopixel (9 LEDs)      | D4       | GPIO2  | OK pin for Neopixel. **This pin needs to be HIGH at boot**            |
| Potensiometer (analog) | A0       | A0     | The only analog input.                                                |

See [the scematic](/docs/diagrams/scematic.png) for further details on wiring.
