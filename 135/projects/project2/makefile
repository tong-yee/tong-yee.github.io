# This is an example Makefile for dig mine project. This
# program uses Field, Game, and TestGame modules.
# Typing 'make' or 'make run' will create the executable file.
#

# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++
CC = g++ -std=c++11
#CFLAGS  = -g -Wall

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
all: run

# To create the executable file run we need the object files
# TestGame.o, Field.o
run:  Field.o TestGame.o Game.o
	$(CC) -o run TestGame.o Field.o Game.o

# To create the object file TestGame.o, we need the source
# files TestGame.cpp and Field.hpp 
#
TestGame.o:  TestGame.cpp
	$(CC) -c TestGame.cpp

# compile Game.cpp to get Game.o
Game.o:  Game.cpp
	$(CC) -c Game.cpp

# To create the object file Field.o, we need the source
# files Field.cpp, Field.hpp
Field.o:  Field.cpp
	$(CC) -c Field.cpp

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) run *.o *~

