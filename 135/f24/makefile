# This is an example makefile for number shuffle project.
# This program uses Board and BoardTest modules.
# Typing 'make' or 'make run' will create the executable file.
#

# define some makefile variables for the compiler and compiler flags
# to use makefile variables later in the makefile: $()
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

# To create the executable file shuffle (see -o shuffle), we need the object files
# BoardTest.o and Board.o:
run:  BoardTest.o Board.o 
	$(CC) -o shuffle BoardTest.o Board.o

# To create the object file BoardTest.o, we need the source
# files BoardTest.cpp, Competition.h 
BoardTest.o:  BoardTest.cpp
	$(CC) -c BoardTest.cpp

# To create the object file Board.o, we need the source files
# Board.cpp.
# By default, $(CC) -c Board.cpp generates Board.o
Board.o:  Board.cpp
	$(CC) -c Board.cpp

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) shuffle *.o *~
