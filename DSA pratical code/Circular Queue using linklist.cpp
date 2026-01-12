#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int val){
    struct Node* ptr;
    ptr = new Node();
    ptr->data = val;
    ptr->next = NULL;
    if(front == NULL){
        front = rear = ptr;
        rear->next = front;
    } else {
        rear->next = ptr;
        rear = ptr;
        rear->next = front;
    }
    cout << val << " is inserted." << endl;
}

void dequeue(){
    if(front == NULL){
        cout << "Queue is empty." << endl;
        return;
    }

    struct Node* temp = front;
    if(front == rear){
        cout << front->data << " is deleated." << endl;
        delete front;
        front = rear = NULL;
    }
    else{
        cout << front->data << " is deleated." << endl;
        front = front->next;
        rear->next = front;
        delete temp;
    }
}

void display(){
    if(front == NULL){
        cout << "Queue is empty." << endl;
        return;
    }
    struct Node* temp = front;
    while(true){
        cout << temp->data << " ";
        temp = temp->next;
        if(temp == front) break;
    }

    cout << endl;
}

void peek(){
    if(front == NULL){
        cout << "Queue is empty." << endl;
    } else {
        cout << "Front element: " << front->data << endl;
    }
}

int main(){
    int choice;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Peek\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";

        if(!(cin >> choice)){
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input.\n";
            continue;
        }

        switch(choice) {
            case 1: {
                int val;
                cout << "Enter value to enqueue: ";
                while(!(cin >> val)){
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid input. Enter an integer: ";
                }
                enqueue(val);
                break;
            }
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                cout << "Exiting.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while(choice != 5);

    return 0;
}


/*

--- Menu ---
1. Enqueue
2. Dequeue
3. Display
4. Peek
5. Exit
Enter choice: 1
Enter value to enqueue: 45
45 is inserted.

--- Menu ---
1. Enqueue
2. Dequeue
3. Display
4. Peek
5. Exit
Enter choice: 1
Enter value to enqueue: 85
85 is inserted.

--- Menu ---
1. Enqueue
2. Dequeue
3. Display
4. Peek
5. Exit
Enter choice: 3
45 85

--- Menu ---
1. Enqueue
2. Dequeue
3. Display
4. Peek
5. Exit
Enter choice: 4
Front element: 45

--- Menu ---
1. Enqueue
2. Dequeue
3. Display
4. Peek
5. Exit
Enter choice: 2
45 is deleated.

--- Menu ---
1. Enqueue
2. Dequeue
3. Display
4. Peek
5. Exit
Enter choice: 5
Exiting.
*/
