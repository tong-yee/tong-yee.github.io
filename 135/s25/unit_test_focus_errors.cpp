#include <iostream>
#include <string>
#include <climits> //INT_MAX
#include "checkAnswer_focus_errors.cpp"

//How to run this file:
//1. We have two files, checkAnswer_focus_errors.cpp and unit_test_focus_errors.cpp.
//2. File checkAnswer_focus_errors.cpp is the source code of our project. 
//3. unit_test_focus_errors.cpp is to test functions defined in checkAnswer_focus_errors.cpp.
//4. Both files have main functions. However, each C++ project can have only one main function.
//5. To run the main function in unit_test_focus_errors.cpp, change the name of function main of checkAnswer_function_rand.cpp to be main2 or add #ifndef UNIT_TEST and #endif around this main function.
//6. g++ -std=c++20 -DUNIT_TEST unit_test_focus_errors.cpp -o test
//7. If there is no error in unit_test_focus_errors`.cpp, a runnable file called test is generated, run the following commands with return key to test each function.

//./test d
//./test e

//8. Change main2 function in checkAnswer_function_rand.cpp back to main.

void read_file_into_array(Question ques[], int capacity);

#ifdef UNIT_TEST
int main(int argc, char** argv) {
    if (argc < 2) {
       std::cout << "missing argument in main function" << std::endl;
       exit(0);
    }

    switch (*argv[1]) {
        case 'd': {
            //test type_related
            //Check whether curr_type and type_to_focus is related or not. That is, curr_type contains at least one item of type_to_focus, if yes, return true, otherwise, return false.
            //bool is_type_related(string type_to_focus, string curr_type);
            string type_to_focus = "array; function";
            string types[] = {
                "condition",
                "function; array",
                "arithmetic; modular; remainder",
                "string; substring",
                "arithmetic; integer division",
                "function",
                "array; integer division"
            };

            for (string curr_type : types)
                cout << boolalpha << type_related(type_to_focus, curr_type) << endl;
            break;

//sample output:
//false
//true
//false
//false
//false
//true
//true
        }

        case 'e': {
            //question type: function; array
            //just concentrate on type 
            //in fact, only need to keep type,             //because we reorder based on type

            string types[] = {
                "condition",
                "function; array",
                "arithmetic; modular; remainder",
                "string; substring",
                "arithmetic; integer division",
                "function",
                "array; integer division"
            };

            int size = sizeof(types) / sizeof(types[0]);
            Question* ptrQues = new Question[size];

            for (int i = 0; i < size; i++)
                ptrQues[i].type = types[i];
            
            //after reorder,
            cout << "original order of questions" << endl;
            for (int i = 0; i < size; i++)
                cout << ptrQues[i].type << endl;
 
            reorder(ptrQues, size, 1);

            //after reorder,
            cout << "\nIf fail the second problems for three times, reorder the rest array" << endl;
            for (int i = 0; i < size; i++)
                cout << ptrQues[i].type << endl;

            //release dynamically allocated memory
            delete[] ptrQues;
            ptrQues = nullptr;
            break;

//sample output
//original order of questions
//condition
//function; array
//arithmetic; modular; remainder
//string; substring
//arithmetic; integer division
//function
//array; integer division
//
//If fail the second problems for three times, reorder the rest array
//condition
//function; array
//array; integer division
//function
//arithmetic; integer division
//string; substring
//arithmetic; modular; remainder
        } 
    }

    return 0;
}
#endif
