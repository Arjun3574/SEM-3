// Name :- Arjun Mankuskar
// PRN :- 202401110038
// Title :- Inheritance

#include <iostream>
using namespace std;

// ---------------- Single Inheritance ----------------
class College {
public:
    void collegeInfo() {
        cout << "Single Inheritance: This is MIT College." << endl;
    }
};
class Department : public College {
public:
    void deptInfo() {
        cout << "Single Inheritance: Computer Engineering Department." << endl;
    }
};

// ---------------- Multilevel Inheritance ----------------
class University {
public:
    void uniInfo() {
        cout << "Multilevel: University - Tech University" << endl;
    }
};
class Faculty : public University {
public:
    void facultyInfo() {
        cout << "Multilevel: Faculty - Engineering Faculty" << endl;
    }
};
class Student : public Faculty {
public:
    void studentInfo() {
        cout << "Multilevel: Student - Enrolled in 2nd Year B.Tech" << endl;
    }
};

// ---------------- Multiple Inheritance ----------------
class Sports {
public:
    void sportsInfo() {
        cout << "Multiple: Sports Department - Football and Cricket" << endl;
    }
};
class Cultural {
public:
    void culturalInfo() {
        cout << "Multiple: Cultural Club - Music and Drama" << endl;
    }
};
class Club : public Sports, public Cultural {
public:
    void clubInfo() {
        cout << "Multiple: College Club - Active Member of Sports & Cultural Teams" << endl;
    }
};

// ---------------- Hierarchical Inheritance ----------------
class CollegeBase {
public:
    void baseInfo() {
        cout << "Hierarchical: Base College - Common Notice Board" << endl;
    }
};
class Teacher : public CollegeBase {
public:
    void teacherInfo() {
        cout << "Hierarchical: Teacher - Conducts Lectures" << endl;
    }
};
class NonTeaching : public CollegeBase {
public:
    void staffInfo() {
        cout << "Hierarchical: Non-Teaching Staff - Maintains College Records" << endl;
    }
};

// ---------------- Hybrid Inheritance ----------------
class Admin {
public:
    void adminInfo() {
        cout << "Hybrid: Admin - Manages All Departments" << endl;
    }
};
class DepartmentA : public Admin {
public:
    void deptAInfo() {
        cout << "Hybrid: Department A - Computer Science" << endl;
    }
};
class DepartmentB {
public:
    void deptBInfo() {
        cout << "Hybrid: Department B - Electronics" << endl;
    }
};
class CombinedDept : public DepartmentA, public DepartmentB {
public:
    void combinedInfo() {
        cout << "Hybrid: Combined Department - Interdisciplinary Projects" << endl;
    }
};

// ---------------- Main Function ----------------
int main() {
    cout << "\n--- Single Inheritance ---" << endl;
    Department dept;
    dept.collegeInfo();
    dept.deptInfo();

    cout << "\n--- Multilevel Inheritance ---" << endl;
    Student stu;
    stu.uniInfo();
    stu.facultyInfo();
    stu.studentInfo();

    cout << "\n--- Multiple Inheritance ---" << endl;
    Club clb;
    clb.sportsInfo();
    clb.culturalInfo();
    clb.clubInfo();

    cout << "\n--- Hierarchical Inheritance ---" << endl;
    Teacher t;
    NonTeaching nt;
    t.baseInfo();
    t.teacherInfo();
    nt.baseInfo();
    nt.staffInfo();

    cout << "\n--- Hybrid Inheritance ---" << endl;
    CombinedDept cd;
    cd.adminInfo();
    cd.deptAInfo();
    cd.deptBInfo();
    cd.combinedInfo();

    return 0;
}

/*
=====================  OUTPUT :-  ===================

--- Single Inheritance ---
Single Inheritance: This is MIT College.
Single Inheritance: Computer Engineering Department.

--- Multilevel Inheritance ---
Multilevel: University - Tech University
Multilevel: Faculty - Engineering Faculty
Multilevel: Student - Enrolled in 2nd Year B.Tech

--- Multiple Inheritance ---
Multiple: Sports Department - Football and Cricket
Multiple: Cultural Club - Music and Drama
Multiple: College Club - Active Member of Sports & Cultural Teams

--- Hierarchical Inheritance ---
Hierarchical: Base College - Common Notice Board
Hierarchical: Teacher - Conducts Lectures
Hierarchical: Base College - Common Notice Board
Hierarchical: Non-Teaching Staff - Maintains College Records

--- Hybrid Inheritance ---
Hybrid: Admin - Manages All Departments
Hybrid: Department A - Computer Science
Hybrid: Department B - Electronics
Hybrid: Combined Department - Interdisciplinary Projects

*/
