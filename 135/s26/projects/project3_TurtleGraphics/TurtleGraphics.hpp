#ifndef TurtleGraphics_HPP
#define TurtleGraphics_HPP
#include "Turtle.hpp"
#include "Floor.hpp"

// TurtleGraphics combines a Turtle and a Floor to simulate
// a turtle crawling on a floor and leaving marks behind.
// Commands direct the turtle to lift/lower its pen, turn,
// move, and display the floor.
class TurtleGraphics {
public:
  // Default constructor.
  // Creates a TurtleGraphics object with a default-sized floor
  // and a turtle initialized to its default state.
  TurtleGraphics();

  // Non-default constructor.
  // Creates a TurtleGraphics object with a square floor of the
  // given size, and a turtle initialized to its default state.
  // @param size: the number of rows and columns of the floor
  TurtleGraphics(int size);

  // Resets the TurtleGraphics object to its initial state:
  // clears all marks on the floor and resets the turtle
  // to its default position, heading, and pen state.
  void restart();

  // Runs the turtle graphics program in interactive mode.
  // Reads commands from the console (stdin) until the user
  // enters 9 to stop. Calls restart() before processing commands.
  // Valid commands:
  //   1 - pen up
  //   2 - pen down
  //   3 - turn right
  //   4 - turn left
  //   5 - move (followed by number of steps)
  //   6 - print floor
  //   9 - stop
  void run();

  // Runs the turtle graphics program using a predefined list of commands.
  // Each inner vector represents one command:
  //   - commands with no parameter:  {command}         e.g. {1}, {2}, {3}
  //   - commands with one parameter: {command, steps}  e.g. {5, 3}
  // Calls restart() before processing commands.
  // @param commands: a 2D vector of integer commands to execute
  void run(const std::vector<std::vector<int>>& commands);

  // Returns a const reference to the floor object.
  // Useful for inspecting the floor after commands have been run.
  const Floor& getFloor() const;

  // Returns a const reference to the turtle object.
  // Useful for inspecting the turtle's state, e.g. after restart().
  const Turtle& getTurtle() const;

private:
  Turtle turtle; // the turtle that crawls on the floor
  Floor floor;   // the floor that the turtle crawls on

  // Processes a single command.
  // @param command:        the command number (1-6, 9)
  // @param inputFromConsole: if true, reads numSteps from stdin for command 5;
  //                          if false, uses the numSteps parameter directly
  // @param numSteps:       number of steps for command 5 (used when inputFromConsole is false)
  void processCommand(int command, bool inputFromConsole, int numSteps);
};
#endif
