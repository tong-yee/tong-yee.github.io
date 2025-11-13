# This is an example Makefile for tic tac toe project. This
# program uses TicTacToeBoard, TicTacToeGame, and TestTicTacToeGame modules.
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
# TestTicTacToeGame.o, TicTacToeBoard.o
run:  TicTacToeBoard.o TestTicTacToeGame.o TicTacToeGame.o
	$(CC) -o run TestTicTacToeGame.o TicTacToeGame.o TicTacToeBoard.o

# To create the object file TestTicTacToeGame.o, we need the source
# files TestTicTacToeGame.cpp and TicTacToeBoard.hpp 
#
TestTicTacToeGame.o:  TestTicTacToeGame.cpp
	$(CC) -c TestTicTacToeGame.cpp

TicTacToeGame.o:  TicTacToeGame.cpp
	$(CC) -c TicTacToeGame.cpp

# To create the object file TicTacToeBoard.o, we need the source
# files TicTacToeBoard.cpp, TicTacToeBoard.hpp
TicTacToeBoard.o:  TicTacToeBoard.cpp
	$(CC) -c TicTacToeBoard.cpp

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) run *.o *~

