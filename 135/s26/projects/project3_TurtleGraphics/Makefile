# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Object files
FLOOR_OBJ = Floor.o
TURTLE_OBJ = Turtle.o
TG_OBJ = TurtleGraphics.o

# -----------------------
# Default target
# -----------------------
all: floor turtle tg draw

# -----------------------
# Task A: Floor only
# -----------------------
floor: FloorUnitTest.o $(FLOOR_OBJ)
	$(CXX) $(CXXFLAGS) -o floor FloorUnitTest.o $(FLOOR_OBJ)

# -----------------------
# Task B: Turtle only
# -----------------------
turtle: TurtleUnitTest.o $(TURTLE_OBJ)
	$(CXX) $(CXXFLAGS) -o turtle TurtleUnitTest.o $(TURTLE_OBJ)

# -----------------------
# Task C: TurtleGraphics
# -----------------------
tg: TurtleGraphicsUnitTest.o $(TG_OBJ) $(TURTLE_OBJ) $(FLOOR_OBJ)
	$(CXX) $(CXXFLAGS) -o tg TurtleGraphicsUnitTest.o $(TG_OBJ) $(TURTLE_OBJ) $(FLOOR_OBJ)

# -----------------------
# Draw program (depends on ALL)
# -----------------------
draw: drawSideBySide.o $(TG_OBJ) $(TURTLE_OBJ) $(FLOOR_OBJ)
	$(CXX) $(CXXFLAGS) -o draw drawSideBySide.o $(TG_OBJ) $(TURTLE_OBJ) $(FLOOR_OBJ)

# -----------------------
# Compilation rules
# -----------------------
Floor.o: Floor.cpp Floor.hpp
	$(CXX) $(CXXFLAGS) -c Floor.cpp

Turtle.o: Turtle.cpp Turtle.hpp
	$(CXX) $(CXXFLAGS) -c Turtle.cpp

TurtleGraphics.o: TurtleGraphics.cpp TurtleGraphics.hpp Turtle.hpp Floor.hpp
	$(CXX) $(CXXFLAGS) -c TurtleGraphics.cpp

# Unit tests
FloorUnitTest.o: FloorUnitTest.cpp Floor.hpp
	$(CXX) $(CXXFLAGS) -c FloorUnitTest.cpp

TurtleUnitTest.o: TurtleUnitTest.cpp Turtle.hpp
	$(CXX) $(CXXFLAGS) -c TurtleUnitTest.cpp

TurtleGraphicsUnitTest.o: TurtleGraphicsUnitTest.cpp TurtleGraphics.hpp Turtle.hpp Floor.hpp
	$(CXX) $(CXXFLAGS) -c TurtleGraphicsUnitTest.cpp

# Draw program
drawSideBySide.o: drawSideBySide.cpp TurtleGraphics.hpp Turtle.hpp Floor.hpp
	$(CXX) $(CXXFLAGS) -c drawSideBySide.cpp

# -----------------------
# Clean
# -----------------------
clean:
	rm -f *.o floor turtle tg draw
