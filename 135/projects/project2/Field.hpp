//#pragma once //not work in older version of C++
#ifndef FIELD_H //include guard
#define FIELD_H
#include<string>
class Field {
   private:
       int* cells;
       bool* checked;
       int size;
       int num_mines;

       //std::string getSeparateLine() const; //not needed

   public:
       Field(); //constructor
       Field(int size, int num_mines);
       ~Field(); //destructor
       std::string to_string() const;
       std::string answer_string() const;
       std::string empty_layout_string() const;
       int get_size() const;
       int get_num_mines() const;
       int neighbor_mines(int index) const;
       void mark_checked(int index);
       bool is_checked(int index) const;
       bool has_mine(int index) const;
};
#endif
