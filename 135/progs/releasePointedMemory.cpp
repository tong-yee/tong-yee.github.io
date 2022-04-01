//File name: /Users/laptopuser/Documents/courses/cs135/s22/progs/exercises/pointer/releasePointedMemory.cpp
#include <iostream>
using namespace std;

int main()
{
    const int size = 6;
    int arr[size];
    for (int i = 0; i < size; i++)
        arr[i] = 5;

    int *p = new int;
    *p = 5;
    delete p;
    p = nullptr;

    int size2 = 6;
    int* arr2 = new int[size2];
    for (int i = 0; i < size2; i++)
        arr2[i] = i;

    delete[] arr2;
    arr2 = nullptr;

    cout << *arr2 << endl; //segment error
    return 0;
}
