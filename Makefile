NAME = micromo
files = micromo_main \
   dcmo5emulation \
   dc6809emul \
   micromo_keyboard \
   micromo_devices \
   micromo_dialog

K7=$(wildcard software/[^_]*.k7)

DEFINES += VGAMODE_320 KEYB_FR DISABLE_ESC_EXIT

GAME_C_FILES = $(files:%=source/%.c)
GAME_BINARY_FILES = $(K7) mo5.rom

include $(BITBOX)/lib/bitbox.mk

build/k7.h: $(sort $(K7))
	mkdir -p build
	python2 k7list.py $^ > $@

source/micromo_devices.c source/micromo_main.c: build/k7.h
