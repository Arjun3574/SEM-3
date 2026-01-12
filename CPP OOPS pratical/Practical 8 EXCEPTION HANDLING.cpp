// Name :- Arjun Mankuskar
// PRN :- 202401110038
// Title :- Exception Handling

#include <iostream>
using namespace std;

class College {
public:
    void displayCollege() {
        cout << "Welcome" << endl;
    }

    void registerStudent(const char name[], int age) {
        try {
            if (age < 17)
                throw age; 
            cout << "Student Registered Successfully: " << name << " (Age " << age << ")" << endl;
        }
        catch (int invalidAge) {
            cout << "Student age " << invalidAge << " is below minimum admission age (17 years)." << endl;
        }
    }

    void calculateResult(int totalMarks, int subjects) {
        try {
            if (subjects <= 0)
                throw 'Z';  
            if (totalMarks < 0)
                throw totalMarks;  

            float average = static_cast<float>(totalMarks) / subjects;
            cout << "Average Marks: " << average << endl;

            if (average < 40.0f)
                throw false;  

            cout << "Result: Pass" << endl;
        }
        catch (char) {
            cout << "Number of subjects cannot be zero or negative!" << endl;
        }
        catch (int marks) {
            cout << "Invalid total marks (" << marks << ")" << endl;
        }
        catch (bool) {
            cout << "Result: Fail" << endl;
        }
    }
};

int main() {
    College c;
    c.displayCollege();

    cout << "\n--- Student Registration ---" << endl;
    c.registerStudent("Arjun", 19);
    c.registerStudent("Sujal", 16);

    cout << "\n--- Result Calculation ---" << endl;
    c.calculateResult(360, 5);   
    c.calculateResult(-5, 5);    
    c.calculateResult(142, 0);   
    c.calculateResult(178, 5);   

    return 0;
}

/*
=================== OUTPUT :-  ===================

Welcome

--- Student Registration ---
Student Registered Successfully: Arjun (Age 19)
Student age 16 is below minimum admission age (17 years).

--- Result Calculation ---
Average Marks: 72
Result: Pass
Invalid total marks (-5)
Number of subjects cannot be zero or negative!
Average Marks: 35.6
Result: Fail
*/
