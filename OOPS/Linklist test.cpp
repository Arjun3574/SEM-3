#include <iostream>
// The NULL macro is defined in cstddef, but iostream often includes it indirectly.
// Including it explicitly is good practice.
#include <cstddef> 

using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* next;
};

int main() {
    // 1. Declare the head pointer inside main and initialize it to NULL.
    //    This indicates the list is empty at the start.
    Node* head = NULL; 

    int val;

    // Allocate memory for a new node
    Node* ptr = new(nothrow) Node();

    // Check if memory allocation was successful
    if (ptr == NULL) { // 2. Use NULL for comparison
        cout << "Memory is not allocated" << endl;
    } else {
        cout << "Enter value: ";
        cin >> val;
        
        ptr->data = val; // Assign the input value

        // Check if the list is currently empty
        if (head == NULL) { // 3. Use NULL for comparison
            ptr->next = NULL; // The new node's next is also NULL
            head = ptr;       // The new node is now the head
        } else {
            // If the list is not empty, insert the new node at the beginning
            ptr->next = head; // The new node points to the old head
            head = ptr;       // The new node becomes the new head
        }
        
        cout << "Node inserted successfully at the beginning." << endl;
        if (head != NULL) {
            cout << "New head value is: " << head->data << endl;
        }
    }

    return 0;
}
