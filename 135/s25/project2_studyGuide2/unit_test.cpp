#include <iostream>
#include <string>
#include <climits> //INT_MAX
#include "checkAnswer_function_rand.cpp"

//How to run this file:
//1. We have two files, checkAnswer_function_rand.cpp and unit_test.cpp.
//2. File checkAnswer_function_rand.cpp is the source code of our project. 
//3. unit_test.cpp is to test functions defined in checkAnswer_function_rand.cpp.
//4. Both files have main functions. However, each C++ project can have only one main function.
//5. To run the main function in unit_test.cpp, change the name of function main of checkAnswer_function_rand.cpp to be main2.
//6. g++ -std=c++20 unit_test.cpp -o test
//7. If there is no error in unit_test.cpp, a runnable file called test is generated, run the following commands with return key to test each function.

//./test 1
//or
//./test 2
//./test 3
//...
//./test c

//8. Change main2 function in checkAnswer_function_rand.cpp back to main.

void read_file_into_array(Question ques[], int capacity);

int main(int argc, char** argv) {
    if (argc < 2) {
       std::cout << "missing argument in main function" << std::endl;
       exit(0);
    }

    //test answer_by_type
    Question q1;
    q1.text = "Given char arr[] = {'A', 'B', 'C'}, what is arr[1]?";
    q1.answer = "'B'";
            q1.explanation = "arr[1] is the second element of array arr, which is 'B' in this example.";
            q1.version = "f24 v1";
            q1.label = "1.1";
            q1.type = "array";

            Question q2;
            q2.text = "Declare function increase, given an integer array arr with size many elements, increase each element of the array by 1. Return type is void. Define the function header (no implementation is needed).";
            q2.answer = "void increase(int arr[], int size);";
            q2.explanation = "(1) the first parameter is int arr[], the name of array arr, which also implies the address of the first element of array.\n(2) the second parameter represents the number of elements of the array.";
            q2.version = "f24 v1";
            q2.label = "1.2";
            q2.type = "function; array";

            Question q3;
            q3.text = "Assume that n is properly declared and initialized. Write a statement to declare lastDigit as an integer and initialize it to be the least significant digit of integer n. Suppose n is 123, after the statement, lastDigit is 3.";
            q3.answer = "int lastDigit = n % 10;";
            q3.explanation = "(1) operator % is called remainder or modular operator.\n(2) For example, 12 % 10 means the remainder when dividing 12 pens among 10 students, each student gets 1 pen, and there are 2 pens left.\n(3) In general, n % 10 returns the last digit, or the rightmost digit (least significant digit), of n.\n(4) int lastDigit = n % 10; is a statement to declare lastDigit as an int and initialize it by the last digit of n.";
            q3.version = "f24 v1";
            q3.label = "1.3";
            q3.type = "arithmetic; modular; remainder";

            Question q4;
            q4.text = "What is the output?\n\nstring tens_name(int n);\n\nint main() {\n    cout << tens_name(82) << endl;\n    return 0;\n}\nstring tens_name(int n) {\n    if (n < 20 || n > 99)\n        return \"\";\n\n    string names[] = {\"\", \"\", \"twenty\", \"thirty\", \"forty\", \"fifty\", \"sixty\", \"seventy\", \"eighty\", \"ninety\"};\n    return names[n / 10];\n}";
            q4.answer = "eighty";
            q4.explanation = "(1) When calling tens_name(82), n in tens_name is initialized to be 82.\n(2) Since 82 is not less than 20 or 82 is not larger than 99, no return \"\";\n(3) 82 / 10 is integer division. It is like to divide 82 pens among 10 students, each student get 8 pens. So 82 / 10 returns 8.\n(4) names[n / 10] is names[82 / 10], which is names[8].\n\nindex    0  1      2       3        4       5        6       7      8\n\nelement +--+--+--------+--------+-------+-------+-------+---------+--------+...\n|\"\"|\"\"|\"twenty\"|\"thirty\"|\"forty\"|\"fifty\"|\"sixty\"|\"seventy\"|\"eighty\"|...\n +--+--+--------+--------+-------+-------+-------+---------+--------+...\n\n(5) The return of tens_name(82) is \"eighty\".\n(6) In main function, print tens_name(82), so the print out is \"eighty\" (without quotes).";
            q4.version = "f24 v1";
            q4.label = "1.4";
            q4.type = "integer division; array";

            Question ques[] = {q1, q2, q3, q4};

            int size = sizeof(ques) / sizeof(ques[0]);

    switch (*argv[1]) {
        case '1': {
             const int CAPACITY = 1000;
             Question ques[CAPACITY]; //question array

             read_file_into_array(ques, CAPACITY);
             break;
        }

        case '2': {
             //test when capacity is reached
             const int CAPACITY = 25;
             Question ques[CAPACITY]; //question array

             read_file_into_array(ques, CAPACITY);
             break;
        }

        case '3': {
             //test trim
             //the string is given randomly in gradescript
             cout << "Enter a string: ";
             string inputStr;
             getline(cin, inputStr);
             //cout << "input String: " << inputStr << endl;

             string trimmedStr = trim(inputStr);
             cout << "\"" 
                  << trimmedStr << "\"";
             break;

//Run ./test  3
//sample input / output
//Enter a string:    Hello, World   
//"Hello, World"
        }
        case '4': {
            //test string* extract_type(string type, int& num_types_curr_item)
            string types[] = {"function; array",
               "arithmetic; modular; remainder",               "integer division; array" };             
            for (string type : types) {
                int num_types_curr_item = 0;
                string* pStr = extract_type(type, num_types_curr_item); 
                for (int i = 0; i < num_types_curr_item; i++)
                    cout << pStr[i] << endl;

                //release dynamically allocated memory
                delete[] pStr;
                pStr = nullptr;
            }

            break;

//run
//./test 4
//Sample input/output:
//function
//array
//arithmetic
//modular
//remainder
//integer division
//array
        }
        
        case '5': {
            //test int count_occurrences(string str, char ch)
            string strs[] = {"integer division; array", "arithmetic; modular; remainder"};
            int size = sizeof(strs) / sizeof(strs[0]);
            for (int i = 0; i < size; i++) {
                cout << count_occurrences(strs[i], ';') << endl;
                cout << count_occurrences(strs[i], 'a') << endl;
            }

            break;
//Run ./test 5 in terminal
//Here is the sample input / output:
            //1
            //2
            //2
            //3
        }

        case '6': {
        //insert_order_unique(string types[], int type_capacity, int& type_count, string toAdd)
             const int TYPE_CAPACITY = 30;
             string types[TYPE_CAPACITY]; 
             int type_count = 0;

             string elmsToAdd[] = {"function",
                 "array",
                 "integer division",
                 "array"
             };

             for (string str: elmsToAdd) {
                 insert_order_unique(types,                 TYPE_CAPACITY, type_count, str);

                 cout << type_count << endl; 
                 for (int i = 0; i < type_count;
                     i++) {
                     cout << types[i] << endl; 
                 }
             }
             break;

//Run ./test 6 with return key in terminal.
//Sample output:
             //1
             //function
             //2
             //array
             //function
             //3
             //array
             //function
             //integer division
             //3
             //array
             //function
             //integer division
        }

//void insert_order_unique(string types[], int type_capacity, int& type_count, Question ques[], int ques_size);
        case '7': {
             const int QUES_CAPACITY = 1000;
             Question ques[QUES_CAPACITY];
             int ques_size = 10;
             ques[0].type = "array"; 
             ques[1].type = "function; array"; 
             ques[2].type = "arithmetic; modular; remainder"; 
             ques[3].type = "integer division; array"; 
             ques[4].type = "string; substring";
             ques[5].type = "arithmetic; integer division";
             ques[6].type = "arithmetic; integer division";
             ques[7].type = "repetition";
             ques[8].type = "function";
             ques[9].type = "condition";
   
             const int TYPE_CAPACITY = 30;
             string types[TYPE_CAPACITY];
             int type_count = 0;
             insert_order_unique(types, TYPE_CAPACITY, type_count, ques, ques_size);

             for (int i = 0; i < type_count; i++) 
                 cout << i + 1 << ". " << types[i] << endl;

            break;

//Run ./test 7 with return key in terminal,
//here is a sample output.
//1. arithmetic
//2. array
//3. condition
//4. function
//5. integer division
//6. modular
//7. remainder
//8. repetition
//9. string
//10. substring
        }
        
        case '8': {
             const int SIZE = 10;
             Question ques[SIZE];
             for (int i = 0; i < SIZE; i++) {
                 string str = "1.";
                 ques[i].label = str + to_string(i+1);
             }
  
             randomize(ques, SIZE);

             //Run in linux environment like onlinegdb to get same running out in gradescope.
             for (int i = 0; i < SIZE; i++)
                 cout << ques[i].label << endl;

             break;
//output in Mac when no srand setting up
//Run ./test 8 with return key in terminal
//1.4
//1.9
//1.6
//1.1
//1.3
//1.5
//1.7
//1.2
//1.10
//1.8
       }
        case '9': {
             answer_by_type(ques, size, "array");
             break;

//Run the following command with return key in terminal
//./test 9 
//sample input/output:
//question f24 v1 1.1: Given char arr[] = {'A', 'B', 'C'}, what is arr[1]?
//Enter you answer: 'B'
//number of tries: 1
//true
//
//question f24 v1 1.2: Declare function increase, given an integer array arr with size many elements, increase each element of the array by 1. Return type is void. Define the function header (no implementation is needed).
//Enter you answer: void increase(int arr[], int size);
//number of tries: 1
//true
//
//question f24 v1 1.4: What is the output?
//
//string tens_name(int n);
//
//int main() {
//    cout << tens_name(82) << endl;
//    return 0;
//}
//string tens_name(int n) {
//    if (n < 20 || n > 99)
//        return "";
//
//    string names[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
//    return names[n / 10];
//}
//Enter you answer: eighty
//number of tries: 1
//true
//
//number of correct problems: 3
//percentage of correct: 100%
//excellent
        }
    
        case 'a': {
             answer_by_type(ques, size, "");
             break;

//Run the following command with return key in terminal
//./test a 
//sample input/output:
//question f24 v1 1.1: Given char arr[] = {'A', 'B', 'C'}, what is arr[1]?
//Enter you answer: 'a'
//number of tries: 1
//false
//Enter you answer: 'A'
//number of tries: 2
//false
//Enter you answer: 'B'
//number of tries: 3
//true
//
//question f24 v1 1.3: Assume that n is properly declared and initialized. Write a statement to declare lastDigit as an integer and initialize it to be the least significant digit of integer n. Suppose n is 123, after the statement, lastDigit is 3.
//Enter you answer: int lastDigit = n % 10;
//number of tries: 1
//true
//
//question f24 v1 1.2: Declare function increase, given an integer array arr with size many elements, increase each element of the array by 1. Return type is void. Define the function header (no implementation is needed).
//Enter you answer: void increase(int arr[], int size);
//number of tries: 1
//true
//
//question f24 v1 1.4: What is the output?
//
//string tens_name(int n);
//
//int main() {
//    cout << tens_name(82) << endl;
//    return 0;
//}
//string tens_name(int n) {
//    if (n < 20 || n > 99)
//        return "";
//
//    string names[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
//    return names[n / 10];
//}
//Enter you answer: eighty
//number of tries: 1
//true
//
//number of correct problems: 4
//percentage of correct: 100%
//excellent
        }

        case 'b': {
            string types[] = {
              "arithmetic",
              "array",
              "condition",
              "function",
              "integer division",
              "modular",
            };
            int size = sizeof(types) / sizeof(types[0]);
           
            string chosenType = choose_type(types, size);
            cout << "chosen type: \"" << chosenType << "\"" << endl;

            cout << "\n\nTest when users choose 0. ALL TYPES\n\n";
            //run choose_type the second time
            chosenType = choose_type(types, size);
            cout << "chosen type: \"" << chosenType << "\"" << endl;
            break;

//Run the following command with return key in terminal
//./test b 
//sample input/ouput:
//0. ALL TYPES
//1. arithmetic
//2. array
//3. condition
//4. function
//5. integer division
//6. modular
//Enter a type: 1
//chosen type: "arithmetic"
//
//
//Test when users choose 0. ALL TYPES
//
//0. ALL TYPES
//1. arithmetic
//2. array
//3. condition
//4. function
//5. integer division
//6. modular
//Enter a type: 0
//chosen type: ""
        }

        case 'c': {
           //void feedback(int numCorrect, int numQuestions) 
            int numQuestions = 7;
            for (int numCorrect = 4; 
                 numCorrect <= numQuestions; 
                 numCorrect++)
                feedback(numCorrect, numQuestions);

            break;

//Run the following command with return key in terminal
//./test c

//sample input/output
//number of correct problems: 4
//percentage of correct: 57.1429%
//please ask help ASAP
//number of correct problems: 5
//percentage of correct: 71.4286%
//pass
//number of correct problems: 6
//percentage of correct: 85.7143%
//good
//number of correct problems: 7
//percentage of correct: 100%
//excellent
        }
    }

    return 0;
}

void read_file_into_array(Question ques[], int capacity) {
     int size = 0;

//The following code does not work, why?
//     string fileNames[] = {"cs135_midterm_f24_v1.txt",
//                          "cs135_midterm_f24_v2.txt",
//                          "cs135_midterm_s24_v1.txt"
//                         };
//
//     int numFiles = sizeof(fileNames, fileNames[0]);
//     for (int i = 0; i < numFiles; i++) {
//         //cout << "file name: " << fileNames[i] << endl;
//         read_file(fileNames[i], ques, capacity, size);
//     }

     read_file("cs135_midterm_f24_v1.txt", ques, capacity, size);
     read_file("cs135_midterm_f24_v2.txt", ques, capacity, size);
     read_file("cs135_midterm_s24_v1.txt", ques, capacity, size);
 
     string expected = "";
     for (int i = 0; i < size; i++) {
         expected += std::to_string(i + 1) + '\n';
         expected += "question: " + ques[i].text + '\n';
         expected += "answer: " + ques[i].answer + '\n';
         expected += "explanation: " + ques[i].explanation + '\n';
         expected += "type: " + ques[i].type + '\n';
         expected += "version: " + ques[i].version + '\n';
         expected += "label: " + ques[i].label + '\n';
     } 
    
     cout << expected << endl;
}
