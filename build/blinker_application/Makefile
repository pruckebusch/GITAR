PROJECTDIRS += /home/user/Desktop/gitar/src/user/apps/blinker/

TARGET=z1

GITAR_PROJECT = blinker
all: $(GITAR_PROJECT)

GITAR = /home/user/Desktop/gitar
include $(GITAR)/make/Makefile.gitar

%.shell-upload: %.ce
	(echo; sleep 4; echo "~K"; sleep 4; \
         echo "dec64 | write $*.ce | null"; sleep 4; \
	 ../../tools/base64-encode < $<; sleep 4; \
         echo ""; echo "~K"; echo "read $*.ce | size"; sleep 4) | make login

.PHONY: compile-executable upload-executable
compile-executable: blinker.ce
	echo Compiled Gitar executable: $<
	
upload-executable: blinker.shell-upload
	echo Uploaded Gitar executable: $<
