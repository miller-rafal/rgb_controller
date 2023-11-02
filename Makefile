# A Makefile for compiling C/C++ source code for the ATMega328P and programming the Arduino Uno board
# (without the Arduino IDE)

# targets:
#   build:  compiles the source code
#   flash:  writes compiled hex file to the mcu's flash memory
#   clean:  removes all .hex, .elf, and .o files in the source code and library directories

####################################################################################################
################################### PARAMETERS (CHANGE ACCORDINGLY) ################################
####################################################################################################

# project name
PRJ = main

# avr mcu
MCU = atmega328p 

# mcu clock frequency
CLK = 16000000

# avr programmer and port
# e.g. PRG = arduino -P /dev/ttyACM0
PRG = arduino -P /dev/ttyACM0

# program source files (not including external libraries)
SRC = $(PRJ).c

# where to look for external libraries (consisting of .c/.cpp files and .h files)
# e.g. EXT = ../../adc ../../uart
EXT = ./pwm ./rgb

####################################################################################################
################ DO NOT MODIFY BELOW LINES UNLESS YOU REALLY KNOW WHAT YOU'RE DOING ################
####################################################################################################

# include path
INCLUDE := $(foreach dir, $(EXT), -I$(dir))

# c flags
CFLAGS    = -Wall -Os -DF_CPU=$(CLK) -mmcu=$(MCU) $(INCLUDE)

# any aditional flags for c++
CPPFLAGS =

# executables
AVRDUDE = avrdude -c $(PRG) -p $(MCU)
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
SIZE    = avr-size --format=avr --mcu=$(MCU)
CC      = avr-gcc

# generate list of objects
CFILES    = $(filter %.c, $(SRC))
EXTC     := $(foreach dir, $(EXT), $(wildcard $(dir)/*.c))
CPPFILES  = $(filter %.cpp, $(SRC))
EXTCPP   := $(foreach dir, $(EXT), $(wildcard $(dir)/*.cpp))
OBJ       = $(CFILES:.c=.o) $(EXTC:.c=.o) $(CPPFILES:.cpp=.o) $(EXTCPP:.cpp=.o)

# user targets

# compile all files
build: $(PRJ).hex

# flash program to mcu
flash: build
	$(AVRDUDE) -U flash:w:$(PRJ).hex:i

# remove compiled files
clean:
	rm -f *.hex *.elf *.o
	$(foreach dir, $(EXT), rm -f $(dir)/*.o;)

# other targets

# objects from c files
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

# objects from c++ files
.cpp.o:
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# elf file
$(PRJ).elf: $(OBJ)
	$(CC) $(CFLAGS) -o $(PRJ).elf $(OBJ)

# hex file
$(PRJ).hex: $(PRJ).elf
	rm -f $(PRJ).hex
	$(OBJCOPY) -j .text -j .data -O ihex $(PRJ).elf $(PRJ).hex
	$(SIZE) $(PRJ).elf
