#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;


void insertAtBegin(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << value << " at BEGIN\n";
}


void insertAtLast(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << " Inserted " << value << " at LAST\n";
}


void display() {
    if(head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = head;
    cout << "Linked List: ";
    while(temp != NULL) {
        
        temp = temp->next;
    }
    
}

int main() {
    int choice, value;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at Last\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBegin(value);
                display();
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtLast(value);
                display();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 4);

    return 0;
}

