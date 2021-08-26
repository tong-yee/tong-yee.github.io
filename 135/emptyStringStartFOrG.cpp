//File name: /Users/laptopuser/Documents/student_code/emptyStringStartFOrG.cpp
#include <iostream>
#include <cassert>
using namespace std;

bool empty_or_start_F_G(string str);

int main()
{
    assert(empty_or_start_F_G("")); 
    assert(empty_or_start_F_G("For")); 
    assert(empty_or_start_F_G("Given")); 
    assert(!empty_or_start_F_G("given")); 
    assert(!empty_or_start_F_G("abc")); 
    return 0;
}

//possible empty string, when not empty, start with 'F' or 'G'
bool empty_or_start_F_G(string str)
{
    return (str.empty() || (str[0] == 'F' || str[0] == 'G'));
}
