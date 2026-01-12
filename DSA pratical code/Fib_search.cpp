#include <iostream>
using namespace std;

int fib_search(int rollnos[], int n, int key) {
    int a = 0, b = 1;
    int c = a + b;

    while (c < n) {
        a = b;
        b = c;
        c = a + b;
    }

    int offset = -1;

    while (c > 1) {
        int i = offset + a;
        if (i >= n) i = n - 1;

        if (rollnos[i] < key) {
            c = b;
            b = a;
            a = c - b;
            offset = i;
        } else if (rollnos[i] > key) {
            c = a;
            b = b - a;
            a = c - b;
        } else {
            return i;
        }
    }

    if (b && offset + 1 < n && rollnos[offset + 1] == key)
        return offset + 1;

    return -1;
}

void displayRollnos(int rollnos[], int n) {
    cout << "\nRoll Number Database:\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << rollnos[i] << endl;
    }
}

int main() {
    int rollnos[] = {101, 105, 110, 120, 135, 150, 160, 175, 190, 200};
    int n = sizeof(rollnos) / sizeof(rollnos[0]);

    int choice;
    do {
        cout << "\n====== MENU ======\n";
        cout << "1. Search Roll Number\n";
        cout << "2. Display All Roll Numbers\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int searchRoll;
                cout << "Enter roll number to search: ";
                cin >> searchRoll;

                int index = fib_search(rollnos, n, searchRoll);
                if (index != -1)
                    cout << "Roll number " << searchRoll << " found at position " << index + 1 << ".\n";
                else
                    cout << "Roll number " << searchRoll << " not found in database.\n";
                break;
            }
            case 2:
                displayRollnos(rollnos, n);
                break;

            case 3:
                cout << "Thank You\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 3);

    return 0;
}

/*

====== MENU ======
1. Search Roll Number
2. Display All Roll Numbers
3. Exit
Enter your choice: 1
Enter roll number to search: 101
Roll number 101 found at position 1.

====== MENU ======
1. Search Roll Number
2. Display All Roll Numbers
3. Exit
Enter your choice: 2

Roll Number Database:
1. 101
2. 105
3. 110
4. 120
5. 135
6. 150
7. 160
8. 175
9. 190
10. 200

====== MENU ======
1. Search Roll Number
2. Display All Roll Numbers
3. Exit
Enter your choice: 3
Thank You
*/
