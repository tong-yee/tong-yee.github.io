// File name: Turtle.hpp
#ifndef Turtle_HPP
#define Turtle_HPP

#include <ostream> //std::ostream, used in << operator for Direction

/**
 * @brief Represents the state of the turtle's drawing pen.
 *
 * UP  - the pen is lifted; movement does not draw.
 * DOWN - the pen is lowered; movement draws a trail.
 */
enum class Pen { UP, DOWN };

/**
 * @brief Represents the four cardinal directions the turtle can face.
 */
enum class Direction { NORTH, EAST, SOUTH, WEST };

/**
 * @brief Overloads the stream insertion operator for Direction.
 * @param os      The output stream to write to.
 * @param heading The Direction value to print.
 * @return        Reference to the output stream, with the direction written
 *                as a human-readable string: "NORTH", "EAST", "SOUTH", or "WEST".
 */
std::ostream& operator<<(std::ostream& os, Direction heading);

/**
 * @brief Models a turtle that moves on a 2-D grid and optionally draws a trail.
 *
 * The turtle tracks its position (row, col), the direction it faces (heading),
 * and whether its pen is up or down. All data members are initialized at the
 * point of declaration so no user-defined constructor is required.
 */
class Turtle {
public:

  // No user-defined constructor is needed.
  // All data members are initialized where they are declared (modern C++ style),
  // and the compiler-generated default constructor is sufficient.

  /**
   * @brief Resets the turtle to its initial state.
   *
   * After this call:
   *   - pen     == Pen::UP
   *   - heading == Direction::EAST
   *   - row     == 0
   *   - col     == 0
   */
  void reset();

  /**
   * @brief Reports whether the pen is currently lifted.
   * @return true  if pen == Pen::UP  (turtle does not draw while moving).
   * @return false if pen == Pen::DOWN (turtle draws while moving).
   */
  bool isPenUp() const;

  /**
   * @brief Lifts the pen so that subsequent moves do not draw.
   * @post  pen == Pen::UP
   */
  void liftUpPen();

  /**
   * @brief Lowers the pen so that subsequent moves draw a trail.
   * @post  pen == Pen::DOWN
   */
  void putDownPen();

  /**
   * @brief Moves the turtle forward by the given number of steps in its current heading.
   *
   * The axis updated depends on the current heading:
   *   - EAST  : col += steps
   *   - WEST  : col -= steps
   *   - SOUTH : row += steps
   *   - NORTH : row -= steps
   *
   * Negative values for steps move the turtle in the opposite direction.
   * No bounds checking is performed; the caller is responsible for
   * keeping the turtle within any grid boundaries.
   *
   * @param steps Number of grid cells to move (may be negative).
   */
  void move(int steps);

  /**
   * @brief Rotates the turtle 90 degrees to the left (counter-clockwise).
   *
   * Heading transitions:
   *   EAST  -> NORTH
   *   NORTH -> WEST
   *   WEST  -> SOUTH
   *   SOUTH -> EAST
   *
   * @post heading is updated to the next counter-clockwise direction.
   */
  void turnLeft();

  /**
   * @brief Rotates the turtle 90 degrees to the right (clockwise).
   *
   * Heading transitions:
   *   EAST  -> SOUTH
   *   SOUTH -> WEST
   *   WEST  -> NORTH
   *   NORTH -> EAST
   *
   * @post heading is updated to the next clockwise direction.
   */
  void turnRight();

  /**
   * @brief Sets the turtle's row position on the grid.
   *
   * No bounds checking is performed; the caller is responsible for
   * passing a valid row index.
   *
   * @param row The new row index (0-based).
   */
  void setRow(int row);

  /**
   * @brief Sets the turtle's column position on the grid.
   *
   * No bounds checking is performed; the caller is responsible for
   * passing a valid column index.
   *
   * @param col The new column index (0-based).
   */
  void setCol(int col);

  /**
   * @brief Returns the turtle's current row position.
   * @return The current row index (0-based).
   */
  int getRow() const;

  /**
   * @brief Returns the turtle's current column position.
   * @return The current column index (0-based).
   */
  int getCol() const;

  /**
   * @brief Sets the direction the turtle is facing.
   *
   * Because Direction is a scoped enum, only the four defined values
   * (NORTH, EAST, SOUTH, WEST) are valid; no explicit validation is needed.
   *
   * @param heading The new heading for the turtle.
   */
  void setHeading(Direction heading);

  /**
   * @brief Returns the direction the turtle is currently facing.
   * @return The current heading as a Direction value.
   */
  Direction getHeading() const;

private:
  // Modern C++ preferred style: initialize members where they are declared,
  // and let the compiler generate the default constructor.
  Pen       pen     = Pen::UP;           ///< Current pen state (UP or DOWN).
  Direction heading = Direction::EAST;   ///< Current heading (NORTH/EAST/SOUTH/WEST).
  int       row     = 0;                 ///< Current row position on the grid (0-based).
  int       col     = 0;                 ///< Current column position on the grid (0-based).
};

#endif
