//File name: /Users/laptopuser/Documents/courses_macbook_pro/cs135/s25/project1_study_guide_update/taskC/v3_read_from_file/checkAnswer.cpp

#include <iostream>
#include <fstream> //ifstream
#include <string> //starts_with, c++20
#include <climits> //INT_MAX
#include <string.h> //c-string, strlen(...)
#include <cctype> //isspace

using namespace std;

struct Question {
    string text; //question text
    string answer;
    string explanation;
    string version;
    string type;
    string label;
};

void read_file(string fileName, Question ques[], int capacity, int& size);

void display(Question ques[], int size);

string trim(string str);

//count number of occurrences of ch in str
int count_occurrence(string str, char ch); 

//extract type separated by ; 
//then put the trimmed type in 
//dynamically allocated array of strings
string* extract_type(string type, int& num_types_curr_item); 

void insert_order_unique(string types[], int type_capacity, int& type_count, string toAdd);

void insert_order_unique(string types[], int type_capacity, int& type_count, Question ques[], int ques_size);


void randomize(Question ques[], int size);

string choose_type(string* types, int type_count);

//answer questions, let users try at most 3 times,
//and return the number of correct answers in three or fewer tries
void answer_by_type(Question ques[], int size, string chosenType);

void feedback(int numCorrect, int numQuestionsInType);

int main() {
    //Declare CAPACITY as a const int with value 1000.
    const int CAPACITY = 1000;
    //Declare ques as an array of Questions
    //that hold CAPACITY many Questions.
    Question ques[CAPACITY]; //question array

    //Declare size to be 0.
    int size = 0;
    read_file("cs135_midterm_f24_v1.txt", ques, CAPACITY, size);
    read_file("cs135_midterm_f24_v2.txt", ques, CAPACITY, size);
    read_file("cs135_midterm_s24_v1.txt", ques, CAPACITY, size);

    //optional
    //display(ques, size);

    //suppose that there are at most 30 types.
    const int TYPE_CAPACITY = 30;
    string types[TYPE_CAPACITY]; 
 
    //declare typeCount to be an int with value 0
    int typeCount = 0;

    //TODO: call insert_order_unique function on questions.

    //TODO: call choose_type function, save the return in a variable.

    //TODO: call answer_by_type with the return from the above statement. 
    
    return 0;
}

//TODO: implement code
void read_file(string fileName, Question ques[], int capacity, int& size) {
    fstream fin(fileName);
    
    if (fin.fail()) {
       cerr << fileName << " cannot be opened" << endl;
       exit(1);
    }

    string text;
    string answer;
    string explanation;
    string version;
    string type; //type of the code
    string label;

    string line;

//skip lines until get the first question
    while ( getline(fin, line) && !( line.starts_with("question: ") || line.starts_with("Question: ") ) )
        ;

    while (line.starts_with("question: ")) {
        text = line.substr(strlen("question: ")); 

        line = "";
        while (getline(fin, line) && !line.starts_with("answer: ") )
            text += '\n' + line;

        if ( line.starts_with("answer: ") ) {
           answer = line.substr(strlen("answer: "));

           line = "";
           while (getline(fin, line) && !(line.starts_with("question: ") || line.starts_with("version: ") || line.starts_with("label: ") || line.starts_with("type: ") || line.starts_with("explanation: ") ) )
               answer += line + '\n';

           //explanation is the next entry following answer. 
           //Need to starts with "explanation: ",
           //cannot handle the case like "explanation:\n"
           if ( line.starts_with("explanation: ") ) {
              explanation = line.substr(strlen("explanation: ")) + '\n';
              line = "";
              while (getline(fin, line) && !(line.starts_with("question: ") || line.starts_with("version: ") || line.starts_with("label: ") || line.starts_with("type: ") ) )
                  explanation += line + '\n';
           }

           //use do-while statement, otherwise, the entry following answer: is not read
           do {
               if (line.starts_with("version: "))
                  version = line.substr(strlen("version: "));
               else if (line.starts_with("type: "))
                       type = line.substr(strlen("type: ")); 
               else if (line.starts_with("label: "))
                       label = line.substr(strlen("label: "));
               line = "";
           } while (getline(fin, line) && !(line.starts_with("question: ")));

           //TODO: if size is larger or equal to capacity, close the file and return.


           //TODO: save text, answer, ..., explantion, to the corresponding field of ques[size].
           

           //TODO: increase size by 1
           
           
           text = "";
           answer = "";
           version = "";
           type = "";
           label = "";
           explanation = "";
        }
    }
    fin.close();
}

void display(Question ques[], int size) {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << endl;
        cout << "question: " << ques[i].text << endl;
        cout << "answer: " << ques[i].answer << endl;
        cout << "explanation: " << ques[i].explanation << endl;
        cout << "type: " << ques[i].type <<  endl;
        cout << "version: " << ques[i].version <<  endl;
        cout << "label: " << ques[i].label <<  endl;
        cout << endl; 
    }
}

//TODO: implement code
string trim(string str) {

}

//TODO: implement code
//count number of occurrences of ch in str
int count_occurrences(string str, char ch) { 

}

//TODO: implement code
string* extract_type(string type, int& num_types_curr_item) {

}

//TODO: implement code
void insert_order_unique(string types[], int type_capacity, int& size, string toAdd) {

}

//TODO: implement code
void insert_order_unique(string types[], int type_capacity, int& numTypes, Question ques[], int ques_size) {

}

//TODO: implement code
string choose_type(string* types, int type_count) {

}

//TODO: implement code
void answer_by_type(Question ques[], int size, string chosenType) {
    //TODO: call randomize function

    //TODO: display questions and answer them
    //If fail to answer a question correctly in 3 tries,
    //if explanation field is not empty,
    //display explantion field of that question.


    //TODO: call feedback function 
   

}

//TODO: implement code
void feedback(int numCorrect, int numQuestions) { 

}

//TODO: implement code
void randomize(Question ques[], int size) {

}
