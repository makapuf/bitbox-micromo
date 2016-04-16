NAME = micromo
files = micromo_main dcmo5emulation dc6809emul dcmo5options  micromo_dialogstub micromo_keyboard
# dcmo5keyb    dcmo5video dcmo5devices

DEFINES += VGAMODE_400 KEYB_FR DISABLE_ESC_EXIT

GAME_C_FILES = $(files:%=source/%.c)
GAME_BINARY_FILES =

include $(BITBOX)/lib/bitbox.mk


