//File name: /Users/laptopuser/Documents/courses/cs135/135_f24/project1_planner/gradescripts/taskD_list_tasks_by_priority/unit_test_analyze_12h_planner.cpp
#include <iostream>
#include <string>
#include "analyze_12h_planner.cpp"
#include <ctime> //time(NULL)

//https://stackoverflow.com/questions/29734231/how-to-conditional-compile-main-in-c
//1. We have two files, analyze_12h_planner.cpp and unit_test_analyze_12h_planner.cpp.
//2. File analyze_12h_planner.cpp reads a csv file and prints the tasks by priority.
//3. Both files have main functions.
//4. Enclose the main function of unit_test_analyze_12h_planner.cpp with #ifdef UNIT_TEST and #endif
//#ifdef UNIT_TEST
//int main(int argc, char** argv) {
//...
//}
//#endif
//5. Enclose the main function of analyze_12h_planner.cpp with #ifnedef UNIT_TEST and #endif
//which unit tests functions //defined in analyze_12h_planner.cpp,
//6. When running the code,
//g++ -DUNIT_TEST unit_test_analyze_12h_planner.cpp, choose main function of unit_test_analyze_12h_planner.cpp 
//g++ analyze_12h_planner.cpp, choose main function of analyze_12h_planner.cpp

//const char my_interp[] __attribute__((section(".interp"))) = "/lib/ld-linux.so.2"; //not work

//not work
//namespace mytest {
//   int main(int argc, char** argv); 
//}

//https://stackoverflow.com/questions/17868302/is-it-possible-to-run-tests-on-a-cpp-file-which-already-has-a-main-function
//int alternative_main(int argc, char** argv) {
//int _entry(int argc, char** argv) {
#ifdef UNIT_TEST
int main(int argc, char** argv) {
    if (argc < 2) {
       std::cout << "missing argument in main function" << std::endl;
       exit(0);
    }

    srand(time(NULL));
    switch (*argv[1]) {
        case '1': {
             int hours = 0;
             int minutes = 0;
             const int SIZE = 4;
             std::string strs[SIZE]; //{"12:56 am", "11:35 am", "12:30 pm", "3:07 pm"};
             int expected_hours[SIZE]; //{0, 11, 12, 15}; 
             int expected_minutes[SIZE]; //{56, 35, 30, 7};

             //sample like "12:56 am"
             expected_hours[0] = 0;
             expected_minutes[0] = rand() % 60; //random integer in [0, 59]
             if (expected_minutes[0] < 10)
                strs[0] = "12:0" + std::to_string(expected_minutes[0]) + " am";
             else strs[0] = "12:" + std::to_string(expected_minutes[0]) + " am";

             //sample like "11:35 am" 
             expected_hours[1] = rand() % 11 + 1; //random integer in [1, 11]
             expected_minutes[1] = rand() % 60; //random int in [0, 59]
             if (expected_minutes[1] < 10)
                  strs[1] = std::to_string(expected_hours[1]) + ":0" + 
                       std::to_string(expected_minutes[1]) + " am";
             else 
                  strs[1] = std::to_string(expected_hours[1]) + ":" + 
                       std::to_string(expected_minutes[1]) + " am";

             //sample like "12:30 pm"
             expected_hours[2] = 12;
             expected_minutes[2] = rand() % 50 + 10; //random integer in [10, 59]
             strs[2] = "12:" + std::to_string(expected_minutes[2]) + " pm";

             //sample like "3:07 pm"
             expected_hours[3] = rand() % 11 + 1; //random int in [1, 11]
             expected_minutes[3] = rand() % 10; //random integer in [0, 9]
             strs[3] = std::to_string(expected_hours[3]) + ":0" +
                       std::to_string(expected_minutes[3]) + " pm";
             expected_hours[3] += 12;

             for (int i = 0; i < SIZE; i++) {
                 hours_minutes_in_24h(strs[i], hours, minutes);
             
                 std::cout << "test for " << strs[i] << std::endl;
                 
                 if (hours != expected_hours[i] || minutes != expected_minutes[i]) 
                    std::cout << "fail test" << std::endl 
                          << "expected hours: " << expected_hours[i] 
                          << " and expected minutes: " << expected_minutes[i]
                          << std::endl
                          << "your code generate: hours: " << hours
                          << " and minutes: " << minutes << std::endl;
                  else std::cout << "pass test. "
                                 << "expected hours: " << expected_hours[i] 
                                 << " and expected minutes: " << expected_minutes[i] << std::endl;
             }

             break;
        }

        //for simplicity, no test for invalid input in this example
        //test duration
        case '2': {
            std::string strs[] = {"1:20 am-3:15 am", "11:37 am-2:25 pm",
                "2:15 pm-4:30 pm"}; 
            int expected_total_minutes[] = {115, 168, 135};
            int size = sizeof(strs) / sizeof(strs[0]);

            for (int i = 0; i < size; i++) {
                if (duration(strs[i]) == expected_total_minutes[i])
                   std::cout << "pass test to calculate duration of " << strs[i] 
                             << ". expected return: " << expected_total_minutes[i] << std::endl;
                else std::cout << "fail test to calculate duration of " << strs[i] 
                               << ". expected return: " << expected_total_minutes[i] 
                               << " and your return: " << duration(strs[i])
                               << std::endl;
            }

            break;
        }
    }

    return 0;
}
#endif
