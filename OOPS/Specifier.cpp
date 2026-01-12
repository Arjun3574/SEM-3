//  Title: Scenario:
// Name: Arjun Mankuskar
// PRN No: 202401110038

#include<iostream>
using namespace std;

class emp
{
    int no_of_emp;
    int empid;
    char empname[20];

    public:
        void get();
        void display();
};

void emp::get()
{
    cout<<"\nEnter the no of Employee\n";
    cin>>no_of_emp;
    cout<<"\nEnter the Employee ID \n";
    cin>>empid;
    cout<<"\nEnter the Employee name\n";
    cin>>empname;
}

void emp::display()
{
    cout<<"\nNo of Employee=\t"<<no_of_emp;
    cout<<"\nEmployee ID =\t"<<empid;
    cout<<"\nEmployee Name=\t"<<empname;
}

int main()
{
    emp info;
    info.get();
    info.display();
}

/*************************Output****************/
/*

Enter the no of Employee
1

Enter the Employee ID
45678

Enter the Employee name
Arjun

No of Employee= 1
Employee ID =   45678
Employee Name=  Arjun
*/
