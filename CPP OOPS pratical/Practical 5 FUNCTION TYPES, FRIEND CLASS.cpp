//Name- Arjun Mankuskar
//PRN-202401110038

#include <iostream>
#include <string>


using namespace std;


class DeanOffice; 



class Student {
private:

    string studentName;
    int studentID;
    double gpa;


    static int totalStudents; 

public:

    Student(string name, int id, double gpa) {

        this->studentName = name;
        this->studentID = id;
        this->gpa = gpa;
        totalStudents++;
        cout << "New student record created for " << this->studentName << "." << endl;
    }


    void displayDetails() {
        cout << "\n--- Student Details ---" << endl;
        cout << "ID: " << studentID << endl;
        cout << "Name: " << studentName << endl;
        cout << "GPA: " << gpa << endl;
    }
    


    inline string getName() {
        return studentName;
    }
    


    static int getTotalStudentCount() {
        return totalStudents;
    }
     
    friend class DeanOffice;
};

int Student::totalStudents = 0;


class DeanOffice {
public:
    
    void checkAcademicProbation(Student &s) {
        cout << "\n--- Dean's Office Confidential Check ---" << endl;
        
        cout << "Checking academic status for: " << s.studentName << " (ID: " << s.studentID << ")" << endl;
        if (s.gpa < 2.0) {
            cout << "Status: " << s.studentName << " is on academic probation." << endl;
        } else {
            cout << "Status: " << s.studentName << " is in good academic standing." << endl;
        }
    }
};


int main() {
    cout << "--- University Enrollment System ---" << endl;

    
    cout << "Initial number of students enrolled: " << Student::getTotalStudentCount() << endl;

    
    Student student1("Alice", 101, 3.8);
    Student student2("Bob", 102, 1.9);
    
    student1.displayDetails();
    student2.displayDetails();
    
    
    cout << "\nFetching student name via inline function: " << student1.getName() << endl;
    
    
    cout << "\nTotal number of students enrolled now: " << Student::getTotalStudentCount() << endl;

   
    DeanOffice dean; 
    dean.checkAcademicProbation(student1); 
    dean.checkAcademicProbation(student2); 

    cout << "\n--- System Operations Finished ---" << endl;

    return 0;
}

/*OUTPUT
--- University Enrollment System ---
Initial number of students enrolled: 0
New student record created for Alice.
New student record created for Bob.

--- Student Details ---
ID: 101
Name: Alice
GPA: 3.8

--- Student Details ---
ID: 102
Name: Bob
GPA: 1.9

Fetching student name via inline function: Alice

Total number of students enrolled now: 2

--- Dean's Office Confidential Check ---
Checking academic status for: Alice (ID: 101)
Status: Alice is in good academic standing.

--- Dean's Office Confidential Check ---
Checking academic status for: Bob (ID: 102)
Status: Bob is on academic probation.

--- System Operations Finished ---
*/
