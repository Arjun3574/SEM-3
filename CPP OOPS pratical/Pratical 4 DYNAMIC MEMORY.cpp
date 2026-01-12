//Title: Assignment 4
//Topic: Dynamic Memory
//Name: Arjun Mankuskar
//PRN: 202401110038


#include <iostream>
using namespace std;


void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside swapByValue: a = " << a << ", b = " << b << endl;
}


void swapByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    // References
    int x = 15;
    int &ref = x;
    cout << "Reference example: x = " << x << ", ref = " << ref << endl;

    //Pointers
    int y = 31;
    int *ptr = &y;
    cout << "Pointer example: y = " << y << ", *ptr = " << *ptr << endl;

    //Dynamic Memory Allocation
    int *arr = new int[3];
    arr[0] = 5; arr[1] = 10; arr[2] = 15;

    cout << "Dynamic Array: ";
    for (int i = 0; i < 3; i++) cout << arr[i] << " ";
    cout << endl;

    delete[] arr;

    //Call by Value vs Call by Reference 
    int a = 26, b = 54;
    cout << "\nBefore swapping: a = " << a << ", b = " << b << endl;

    swapByValue(a, b);
    cout << "After swapByValue: a = " << a << ", b = " << b << " (unchanged)" << endl;

    swapByReference(a, b);
    cout << "After swapByReference: a = " << a << ", b = " << b << " (swapped)" << endl;

    return 0;
}

//Output
// Reference example: x = 15, ref = 15
// Pointer example: y = 31, *ptr = 31
// Dynamic Array: 5 10 15 

// Before swapping: a = 26, b = 54
// Inside swapByValue: a = 54, b = 26
// After swapByValue: a = 26, b = 54 (unchanged)
// After swapByReference: a = 54, b = 26 (swapped)
