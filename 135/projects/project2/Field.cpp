#include "Field.hpp"
#include <iostream>
#include <cstdlib> //rand, srand
#include <ctime>

using namespace std;

//TODO: define default constructor
//1. Inialize size to be 7 and num_mines to be 2.  
//2. Set cells to be an array with capacity size, 
//   elements are either 0 or 1, where number of 1's 
//   equals num_mines.
//3. Set checked to be an array with capacity size, 
//   each element is set to be false. 
Field::Field() {

}
  
//TODO: define non-default constructor
//1. If given parameter size is <= 3, 
//   set data member size to be 7, 
//   otherwise, use given parameter size to 
//   inialize data member size.
//2. If given parameter num_mines < 2, 
//   set data member num_mines to be 2, 
//   otherwise, use given parameter num_mines to 
//   inialize data member num_mines.
//3. If num_mines >= size, which means mines are 
//   more than the number of cells, 
//   then set num_mines to be one third (1/3) of size.
//4. Set cells to be an array with capacity size, 
//   elements are either 0 or 1, 
//   where number of 1's equals num_mines.
//5. Set checked to be an array with capacity size, 
//   each element is set to be false. 
//6. Use srand(time(NULL)); to use current time as seed
//   to generate a sequence of random integers.
//7. VERY important, to distinct data member size from
//   given parameter size, use this->size to represent
//   data member size. 
//   Similarly, use this->num_mines to represent
//   data member num_mines,
//   where this is a pointer pointing to
//   the current Field object.
Field::Field(int size, int num_mines) {

}

//destructor ~Field is called 
//when the object is no longer needed.
//TODO: release dynamically allocated memory
//      applied by the data members of the current object.
//      After releasing the memory,
//      set the corresponding pointer to nullptr
//      to avoid dangling pointer problem.
Field::~Field() {

}

//Return a string representing labels of indices.
string get_labels(int size) {
    string str;
    for (int i = 0; i < size; i++) { 
        str += "  ";
        if (i < 10)
           str += " " + std::to_string(i);
        else str += to_string(i);
        str += "  ";
    }
    str += "\n";
    return str;
}

//Since get_separate_line is not a must-provid 
//functionality for Field class,
//it is not a method in Field class.
//Hence it does not have Field:: in front of its name.
//Function get_separate_line is called by
//to_string method of Field class.
string get_separate_line(int size) {
    string str = "+";
    for (int i = 0; i < size; i++)
        str += "-----+";
    str += "\n";
    return str;
}

//Return a string representing 
//a tabular format of cells with labels.
//If a cell does not have a mine and is checked, 
//then display the number of its neighbors,
//otherwise, that is, a cell does not have a mine 
//but is not checked or a cell has a mine,
//display an empty cell. 
string Field::to_string() const {
    string str = get_labels(size);
    str += get_separate_line(size);

    str += "|";
    for (int i = 0; i < size; i++) {
       if (cells[i] == 0) 
        {
           if (checked[i] == true)
               str += "  " + std::to_string(neighbor_mines(i)) +
                      "  |";
           else str += "     |";
        }
        else //must have a mine 
            str += "     |";

        //The above if-else can be simplified.
        //Idea: if a cell has no mine and is checked,
        //display its neighboring information,
        //otherwise, that is,
        //a cell has a mine or
        //it does not have a mine but is not checked yet,
        //do not display anything in that cell.
        //The code is as follows.

        //if (cells[i] == 0 && 
        //    checked[i] == true)
        //   str += "  " + std::to_string(neighbor_mines(i)) +
        //             "  |";
        //else str += "     |";
    }

    str += "\n";

    str += get_separate_line(size);

    return str;
}

//TODO: return a string represening 
//a tabular format of cells with labels.
//If a cell does not have a mine, 
//then display the number of its neighbors, 
//otherwise, that is,
//display an asterisk, which represents a mine.
string Field::answer_string() const {

}

//TODO: return a string represening a tabular format of 
//cells with labels.
//Each cell is empty. 
//This method is called in the beginning of a game.
string Field::empty_layout_string() const {

}

//TODO: return the number of cells of the field,
//that is, the value of data member size.
int Field::get_size() const {

}

//TODO: return the number of mines of the field,
//that is, the value of data member num_mines.
int Field::get_num_mines() const {

}

//TODO: if current cell indexed at index 
//does not contain a mine, 
//return number of mines in its left neighbor (if any) and
//right neighbor (if any), otherwise, return -1.
int Field::neighbor_mines(int index) const {

}

//TODO: if index is valid, that is, 
//index is larger than or equal to 0
//and is smaller than data member size, 
//set element at the corresponding index of
//checked array to be true.
void Field::mark_checked(int index) {

}

//TODO: if the element at the corresponding index of checked
//array is true, return true, otherwise, return false.
//That is, return the value of element at
//the corresponding index of checked array.
bool Field::is_checked(int index) const {
    
}

//TODO: if the element at the corresponding index of cells
//array contains a mine,
//that is, cells[index] is 1, return true, 
//otherwise, return false.
bool Field::has_mine(int index) const {
    
}
