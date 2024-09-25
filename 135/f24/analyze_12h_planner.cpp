//file name: analyze_12h_planner.cpp
#include <iostream>
#include <fstream> //ifstream, ofstream
#include <string>
using namespace std;

//(1) function declaration with only function header, no function body.
//(2) main function needs to know the parameters and return type of
//    a function so that it can call the function.
//(3) function definitation will be put after the definition of main function
void hours_minutes_in_24h(string str, int& hours, int& minutes);

int duration(string str);

#ifndef UNIT_TEST
int main() {
    //TODO: enter file name
    
    //TODO: enter the priority to search for as a string

    //TODO: instantiate an ifstream object fin to open the file with given file name

    //TODO: skip the first line of the csv file since it is captions, no actual data
  
    //each row of data has time interval, activity name, and priority
    string time; //variable to save time interval
    string activity; //variable to save activity name
    string priority; //variable to save priority

    //Note that fin is the ifstream object to read the input file.
    while (getline(fin, time, ',')) { 
        getline(fin, activity, ',');
        getline(fin, priority); //priority is the last data in a row, no ',' followed 
        
        //TODO:  process the read data
    }

    //TODO: close file object fin.

    //TODO: print total duration of all activities in that priority

    return 0;
}
#endif

//Purpose: Let str be a string representing time in 12-hour notation. 
//Convert 12-hour time notation str to 24-hour notation,
//where hours information is put in variable hours,
//minutes information is put in variable minutes.
//For example, if str is "12:30 am", then hours is 0 and minutes is 30.
//if str is "1:02 pm", then hours is 13 and minutes is 2.
//
//The & following type int in int& hours
//means formal parameter hours is pass by reference.
//Similar for & in int& minutes.

//function definition, with instructions provided in function body.
void hours_minutes_in_24h(string str, int& hours, int& minutes) {
    //TODO: write instructions in function body 
}

//Let time be a string using dash symbol '-' to separate two time in 12 hours notation.
//An example of str is "11:30 am-2:15 pm", return the duration between those two time notations in minutes.
//Since the number of minutes between 11:30 am and 2:15 pm is 165 minutes,
//the return is 165.
int duration(string str) {
    //TODO: write instructions in function body 
}
