//file: /Users/laptopuser/Documents/courses/cs135/135_f24/project1_planner/project1_planner_documents/code/unit_test_analyze_12h_planner.cpp

#include <iostream>
#include <string>
#include "analyze_12h_planner.cpp" //include the source code of file to be tested

//https://stackoverflow.com/questions/29734231/how-to-conditional-compile-main-in-c
//1. We have two files, analyze_12h_planner.cpp and unit_test_analyze_12h_planner.cpp.
//2. File analyze_12h_planner.cpp reads a csv file and prints the tasks by priority.
//3. File unit_test_analyze_12h_planner.cpp unit tests functions
//   other than main function defined in analyze_12h_planner.cpp.
//4. Both files have main functions.
//5. Enclose the main function of unit_test_analyze_12h_planner.cpp with #ifdef UNIT_TEST and #endif
//#ifdef UNIT_TEST
//int main(int argc, char** argv) {
//...
//}
//#endif
//6. Enclose the main function of analyze_12h_planner.cpp with #ifnedef UNIT_TEST and #endif
//7. When running the code, option -DUNIT_TEST means to define UNIT_TEST
//       g++ -DUNIT_TEST unit_test_analyze_12h_planner.cpp
//   choose main function of unit_test_analyze_12h_planner.cpp 
//
//8. When compiling and linking without -D option, 
//     g++ analyze_12h_planner.cpp
//   choose main function of analyze_12h_planner.cpp

#ifdef UNIT_TEST
int main(int argc, char** argv) {
    if (argc < 2) {
       std::cout << "missing argument in main function" << std::endl;
       exit(0);
    }

    switch (*argv[1]) {
        case '1': {
             int hours = 0;
             int minutes = 0;
             std::string strs[] = {"12:56 am", "11:35 am", "12:30 pm", "3:07 pm"};
             int expected_hours[] = {0, 11, 12, 15}; 
             int expected_minutes[] = {56, 35, 30, 7};

             int size = sizeof(strs) / sizeof(strs[0]);

             for (int i = 0; i < size; i++) {
                 get_hours_minutes_in_24h(strs[i], hours, minutes);
             
                 std::cout << "test for " << strs[i] << std::endl;
                 
                 if (hours != expected_hours[i] || minutes != expected_minutes[i]) 
                    std::cout << "fail test" << std::endl 
                          << "expected hours: " << expected_hours[i] 
                          << " and expected minutes: " << expected_minutes[i]
                          << std::endl
                          << "your code generate: hours: " << hours
                          << " and minutes: " << minutes << endl;
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
#endif //cannot missing
