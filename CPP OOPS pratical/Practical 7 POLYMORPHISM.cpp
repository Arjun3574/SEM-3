// Name :- Arjun Mankuskar
// PRN :- 202401110038
// Title :- Polymorphism

#include <iostream>
using namespace std;

class College {
public:
    virtual void displayInfo() {
        cout << "Displaying general college information" << endl;
    }
};

class Department : public College {
    string deptName;
public:
    Department(string name) {
        deptName = name;
    }
    void displayInfo() {
        cout << "Department Name: " << deptName << endl;
    }
};

class Student : public College {
    string studentName;
    int rollNo;
public:
    Student(string name, int roll) {
        studentName = name;
        rollNo = roll;
    }
    void displayInfo() {
        cout << "Student Name: " << studentName << ", Roll No: " << rollNo << endl;
    }
};

int main() {
    College* c;     

    Department d("Computer Engineering(AIML)");
    Student s("Arjun Mankuskar", 38);

    c = &d;        
    c->displayInfo();

    c = &s;         
    c->displayInfo();

    return 0;
}


/*
================== OUTPUT :-   ==================

Department Name: Computer Engineering(AIML)
Student Name: Arjun Mankuskar, Roll No: 38

*/
