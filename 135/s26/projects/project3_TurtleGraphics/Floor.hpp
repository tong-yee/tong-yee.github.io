#ifndef FLOOR_HPP //Floor_HPP is ok, but not as good as FLOOR_HPP since the former mixes small and big case letters
#define FLOOR_HPP

#include <vector>
#include <string>

/**
 * @class Floor
 * @brief Manages a 2D character grid with specific labeling and safety checks.
 */
class Floor {
public:
    /**
     * @brief Default constructor.
     * Initializes a default 20 x 20 grid filled with spaces (' ').
     */
    Floor();
    
    /**
     * @brief Parameterized constructor.
     * @param size The desired dimension for a square grid.
     * @note If size < 10, a default 20x20 grid is created instead.
     */
    Floor(int size);

    /** @return The number of rows in the grid. */
    int getNumRows() const;

    /** @return The number of columns in the grid. */
    int getNumCols() const;

    /**
     * @brief Places a character at the specified coordinates.
     * @param row The row index from 0 to getNumRows() - 1.
     * @param col The column index from 0 to getNumCols() - 1.
     * @param ch The character to place.
     * @note If indices are out of bounds, the operation is silently ignored.
     */
    void mark(int row, int col, char ch);

    /**
     * @brief Retrieves the character at the specified coordinates.
     * @param row The row index from 0 to getNumRows() - 1.
     * @param col The column index from 0 to getNumCols() - 1.
     * @return The character at (row, col), or the null character '\0' if out of bounds.
     */
    char at(int row, int col) const;

    /**
     * @brief Resets all cells in the grid to a space (' ').
     */
    void clear();

    /**
     * @brief Returns a string representation of the grid with coordinate labels.
     * 
     * Labeling Rules:
     * 1. Designed for grids up to 99x99.
     * 2. The tens digit for row/column indices is displayed ONLY at multiples 
     *    of 10 (e.g., 10, 20, 30), appearing directly above or to the left.
     * 3. The units digit is displayed for every row and column.
     * 
     * @return A formatted string containing the labels and grid content.
     */
    std::string to_string() const;
 
private:
    std::vector<std::vector<char>> grid;
};

#endif
