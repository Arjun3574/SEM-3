#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int a){
        data = a;
        next = NULL;
    }
};

class Stack{
    Node* head;
public:
    Stack(){
        head = NULL;
    }
    void push(int a){
        Node* x = new Node(a);
        if(head == NULL){
            head = x;
        } else{
            x->next = head;
            head = x;
        }
    }

    void pop(){
        if(head == NULL){
            cout << "Empty" << endl;
            return;
        }
        Node* x = head;
        head = head->next;
        cout << "Popped: " << x->data << endl;
        delete x;
    }

    void display(){
        if(head == NULL){
            cout << "Empty" << endl;
            return;
        }
       
        Node* cur = head;
        while(cur != NULL){
            cout << cur->data;
            if(cur->next != NULL) ;
            cur = cur->next;
        }
        cout << endl;
    }
};

int main(){
    int ch;
    Stack s;
    do{
        cout << "1. push" << endl;
        cout << "2. pop" << endl;
        cout << "3. display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> ch;
        switch(ch){
            case 1: {
                int a;
                cout << "Enter Value: ";
                cin >> a;
                s.push(a);
                break;
            }
            case 2:
                s.pop();
                break;
            case 3:
                s.display();
                break;
            case 4:
                cout << "Exiting" << endl;
                break;
            default:
                cout << "wrong choice" << endl;
        }
    } while(ch != 4);
    return 0;
}

/*
OUTPUT:-
--- Stack Menu ---
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter value to push: 78
78 pushed into stack.

--- Stack Menu ---
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter value to push: 96
96 pushed into stack.

--- Stack Menu ---
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 4
Stack elements (top to bottom): 96 78

--- Stack Menu ---
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 2
96 popped from stack.

--- Stack Menu ---
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 3
Top element: 78

--- Stack Menu ---
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 5

*/
