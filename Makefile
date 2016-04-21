NAME = micromo
files = micromo_main \
   dcmo5emulation \
   dc6809emul \
   micromo_dialogstub \
   micromo_keyboard \
   micromo_devices \
   micromo_dialog

# dcmo5keyb    dcmo5video dcmo5devices

DEFINES += VGAMODE_400 KEYB_FR DISABLE_ESC_EXIT

GAME_C_FILES = $(files:%=source/%.c)
GAME_BINARY_FILES = software/SHR_MO5_FirstEver.k7 mo5.rom

include $(BITBOX)/lib/bitbox.mk

source/micromo_devices.c: build/binaries.h
