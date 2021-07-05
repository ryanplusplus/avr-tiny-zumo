TARGET := zumo
MCU := atmega328p
FRAMEWORK := tiny

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

BUILD_DIR := ./build/$(TARGET)

DEVICE_PACK := Atmel.ATmega_DFP.1.6.364

include tools/defaults.mk

CXXFLAGS += \
  -Wno-effc++ \

CPPFLAGS += \
  -flto \
  -fwhole-program \

SRC_DIRS := \
  src/hardware/ \

SRC_FILES := \
  src/main.c \

include lib_tiny.mk

include tools/tools.mk
