NAME = micromo
files = micromo_main \
   dcmo5emulation \
   dc6809emul \
   micromo_keyboard \
   micromo_devices \
   micromo_dialog

K7=$(wildcard software/[^_]*.k7)

DEFINES += VGA_MODE=320 VGA_BPP=8 KEYB_FR DISABLE_ESC_EXIT

GAME_C_FILES = $(files:%=source/%.c) lib/events/events.c
GAME_BINARY_FILES = $(K7) mo5.rom

include $(BITBOX)/kernel/bitbox.mk

build/k7.h: $(sort $(K7))
	mkdir -p build
	python2 k7list.py $^ > $@

source/micromo_devices.c source/micromo_main.c: build/k7.h
