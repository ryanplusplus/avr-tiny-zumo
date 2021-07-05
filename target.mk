TARGET := zumo
MCU := atmega328p
BUILD_DIR := build/target
DEVICE_PACK := Atmel.ATmega_DFP.1.6.364

# dwdebug or avrdude
UPLOAD_TYPE := dwdebug
AVRDUDE_PROGRAMMER_TYPE := atmelice_isp
AVRDUDE_PROGRAMMER_ARGS :=
DWDEBUG_DEVICE := ttyUSB0

DEFINES := \
  F_CPU=8000000UL \

# http://eleccelerator.com/fusecalc/fusecalc.php?chip=atmega328p&LOW=E2&HIGH=9E&EXTENDED=FD&LOCKBIT=FF
FUSES := \
  lfuse=0xE2 \
  hfuse=0x9E \
  efuse=0xFD \

include tools/defaults.mk

CPPFLAGS += \

SRC_DIRS := \
  src \
  src/application \
  src/bsp \
  src/data_model \
  src/hardware \
  src/type \

SRC_FILES := \

include lib_tiny.mk

include tools/tools.mk
