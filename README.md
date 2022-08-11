# C Library for 28BYJ-48 stepper motor
The main aim of this simple project is verify function of rotary encoder with stepper motor. Primitive functions such as rotate left, rotate right and stop are created to control the stepper motor. Direction control is achieved by a rotary encoder and shown on the LCD display.

# Hardware
Necessary hardware to verify functionality: 
 - stepper motor, for example 28BYJ-48
 - OLED display, for example 0.96 OLED
 - microcontroller, used Atmega328p, but with small modification could be used Atmega8
 - rotary encoder
 - wires for mutual connection
 - external power supply 5 - 12 V

## Stepper motor
28BYJ-48 stepper motor was used in this project. The 28BYJ-48 is a 5-wire uni-polar stepper motor that runs on 5 or 12 volts. This motor has a stride angle of 5.625° with gear ratio 64 (63,68), this means that the motor will have to make 64 x 64 (63,68) = 4096 steps to complete one rotation in half step mode. Detailed information are described in [Datasheet 28BYJ-48](https://www.mouser.com/datasheet/2/758/stepd-01-data-sheet-1143075.pdf).

## Display
OLED display with SSD1306 controller was used in this project. Detailed information are described in [Datasheet SSD1306](https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf). The library for driving OLED display can be downloaded from the following [link](https://github.com/Matiasus/SSD1306).

## Encoder


## Scheme

## Library

# Links
- [28BYJ-48](https://www.mouser.com/datasheet/2/758/stepd-01-data-sheet-1143075.pdf)
- [Stepper Motor Arduino Tutorial](https://lastminuteengineers.com/28byj48-stepper-motor-arduino-tutorial/)
- [SSD1306](https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf)
