// Name :- Arjun Mankuskar
// PRN  :- 202401110038
// Title :- STL : Vector and Multiset (College Scenario)

#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

void vectorDemo() {
    vector<int> rollNo;
    
    rollNo.push_back(11);
    rollNo.push_back(12);
    rollNo.push_back(13);

    cout << "\n****   College Roll Numbers (Vector Example) ****" << endl;

    rollNo.push_back(14);
    rollNo.pop_back();

    cout << "Current Roll Numbers: ";
    for (size_t i = 0; i < rollNo.size(); ++i)
        cout << rollNo[i] << " ";
    cout << "\nTotal Students: " << rollNo.size() << endl;
}

void multisetDemo() {
    multiset<string> submitted;
    cout << "\n****  Assignment Submission (Multiset Example) ****" << endl;

    submitted.insert(string("Arjun"));
    submitted.insert(string("Sujal"));
    submitted.insert(string("Gandhar"));
    submitted.insert(string("Sujal")); 

    cout << "Total submissions recorded: " << submitted.size() << endl;

    cout << "All submissions (sorted, duplicates allowed):" << endl;
   
    for (multiset<string>::iterator it = submitted.begin(); it != submitted.end(); ++it)
        cout << *it << endl;

    cout << "\nCount of submissions by Sujal: " << submitted.count("Sujal") << endl;

    multiset<string>::iterator it = submitted.find("Sujal");
    if (it != submitted.end()) {
        submitted.erase(it); 
        cout << "\nAfter removing one Sujal submission, remaining submissions:" << endl;
        for (multiset<string>::iterator jt = submitted.begin(); jt != submitted.end(); ++jt)
            cout << *jt << endl;
    }
}

int main() {
    vectorDemo();
    multisetDemo();

    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}

/*

****   College Roll Numbers (Vector Example) ****
Current Roll Numbers: 11 12 13
Total Students: 3

****  Assignment Submission (Multiset Example) ****
Total submissions recorded: 4
All submissions (sorted, duplicates allowed):
Arjun
Gandhar
Sujal
Sujal

Count of submissions by Sujal: 2

After removing one Sujal submission, remaining submissions:
Arjun
Gandhar
Sujal
*/
