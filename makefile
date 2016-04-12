# Project: dcmo5

files = dcmo5main dcmo5boutons dcmo5dialog dcmo5devices dcmo5keyb dcmo5emulation dc6809emul dcmo5options dcmo5video

objects = $(files:%=object/%.o)

dcmo5 : $(objects)
	cc -o dcmo5  $(objects) -lSDL -lSDL_ttf

object/dcmo5main.o : source/dcmo5main.c source/dcmo5msg.h include/policettf.h include/dcmo5icon.h
	cc -c source/dcmo5main.c -o object/dcmo5main.o -O2

object/%.o : source/%.c
	cc -c $^ -o $@ -O2

clean :
	rm -f dcmo5 $(objects)