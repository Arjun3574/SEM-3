// Name :- Arjun Mankuskar
// PRN  :- 202401110038
// Title:- Template

#include <iostream>
using namespace std;

template <class T>
class Clg {
    int Clg_ID;
    T ranking;
    T clg_rank;

public:
    // Default constructor
    Clg() {
        Clg_ID = 61703;
        ranking = T();     
        clg_rank = 21;
        cout << "The College ID is " << Clg_ID << "." << endl;
        cout << "Thanks For Visiting." << endl;
    }

    // Copy constructor
    Clg(const Clg &other) {
        Clg_ID = other.Clg_ID;
        ranking = other.ranking;
        clg_rank = other.clg_rank;
        cout << "The College ID is " << Clg_ID << endl;
    }

    // Parameterized constructor
    Clg(T rank) {
        Clg_ID = 61703;
        ranking = rank;
        clg_rank = 21;
        cout << "Rank Of the College is " << ranking << endl;
    }

    // Destructor
    ~Clg() {
        cout << "The rank of your college is " << clg_rank << endl;
    }
};

int main() {
    Clg<int> obj1;
    Clg<int> obj2;
    Clg<int> obj3(13);
    Clg<int> obj4(obj2);
    return 0;
}


/*
The College ID is 61703.
Thanks For Visiting.
The College ID is 61703.
Thanks For Visiting.
Rank Of the College is 13
The College ID is 61703
The rank of your college is 21
The rank of your college is 21
The rank of your college is 21
The rank of your college is 21
*/
