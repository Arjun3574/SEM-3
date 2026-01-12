//Title: Assignment 1.
//Scenario:Info about employee like Id,name,Age and salary.
// Name: Arjun Mankuskar.
// PRN No: 202401110038.
// Practical No.01 - Class and Objects
// Car Dealership #include <iostream>
#include <iostream>
using namespace std;

class Car {
    long accNo;      
    string make;
    string model;
    int year;

public:
    Car()  {
        cout<< "Car object created\n";
    }

    void get() {
        cout << "Enter Stock/Reg No: "; cin >> accNo;
        cout << "Enter Make: ";      cin >> make;
        cout << "Enter Model: ";     cin >> model;
        cout << "Enter Year: ";      cin >> year;
    }

    void display() const {
        cout << "\nCar Details\n";
        cout << "Stock/Reg No: " << accNo << '\n';
        cout << "Make        : " << make << '\n';
        cout << "Model       : " << model << '\n';
        cout << "Year        : " << year << '\n';
    }

    ~Car() { cout << "Car object destroyed\n"; }
};

int main() {
    Car c;
    c.get();
    c.display();
    return 0;
}


/*
OUTPUT:-

Car object created
Enter Stock/Reg No: 12
Enter Make: 41
Enter Model: 125
Enter Year: 2002

Car Details
Stock/Reg No: 12
Make        : 41
Model       : 125
Year        : 2002
Car object destroyed
*/
