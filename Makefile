# This sample Makefile, explains how you can compile plain AVR C file.
#
# Arduino Make file. Refer to https://github.com/sudar/Arduino-Makefile

NO_CORE = Yes

BOARD_TAG    = atmega328
MCU = atmega328p
F_CPU = 16000000L

AVRDUDE_ARD_PROGRAMMER=arduino
AVRDUDE_ARD_BAUDRATE = 57600

include /usr/share/arduino/Arduino.mk

