# MPLAB IDE generated this makefile for use with GNU make.
# Project: test.mcp
# Date: Sun Oct 15 12:28:07 2017

AS = MPASMWIN.exe
CC = mcc18.exe
LD = mplink.exe
AR = mplib.exe
RM = rm

test.cof : main.o
	$(LD) /p18LF46K80 /l"C:\Program Files (x86)\Microchip\mplabc18\v3.47\lib" "main.o" /u_CRUNTIME /u_DEBUG /z__MPLAB_BUILD=1 /z__MPLAB_DEBUG=1 /o"test.cof" /M"test.map" /W

main.o : main.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18lf46k80.h
	$(CC) -p=18LF46K80 "main.c" -fo="main.o" -D__DEBUG -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

clean : 
	$(RM) "main.o" "test.cof" "test.hex"

