//Name:-Arjun Mankuskar
//PRN:-202401110038
//Batch:-A2



// ========================================================================
//
// C++ OOPs: Notes on Hierarchical Inheritance 
//
// ========================================================================
//
//
// 1. Definition (What is it?)
// ----------------------------
// Hierarchical Inheritance is when one main class (the "parent")
// gives its features to two or more "child" classes.
//
// Think of it like a real family: one parent can have several children.
// * The parent is the "Base Class".
// * The children are the "Derived Classes".
//
// All the children get traits from the same parent, but they can each
// have their own unique skills too.
//
// It creates a "one-to-many" pattern:
//
//      [     Parent Class     ]
//      /         |            \
//     /          |             \
// [ Child 1 ] [ Child 2 ] ... [ Child 3 ]
//
//
// 2. Syntax 
// ----------------------------
// The code for it is simple. You just tell each "child" class
// which "parent" class it learns from.
//
//   // 1. Make the Parent Class
//   class Parent {
//       // Put code here that all children will share
//   };
//
//   // 2. Make Child Class 1
//   // The ": public Parent" part means "Child1 learns from Parent".
//   class Child1 : public Parent {
//       // Put code here that is *only* for Child1
//   };
//
//   // 3. Make Child Class 2
//   // Notice it also learns from Parent!
//   class Child2 : public Parent {
//       // Put code here that is *only* for Child2
//   };
//
// The key idea is that Child1 and Child2 all point back to the *same* Parent.
//
//
// 3. Why and Where to Use It?
// ----------------------------
// Why?:- The main reason is to avoid writing the same code over and over.
// It also keeps your code neat and organized.
//
// Where?:- You use this when you can say "is a type of...".
// * A `Manager` "is a type of" `Employee`.
// * An `Engineer` "is a type of" `Employee`.
// This is a perfect time to use it.
//
//
// 4. Real-World Applications
// ----------------------------
// * Employees: (This code's example)
//     * Parent: `Employee` ( has `name`, `employeeID`)
//     * Children: `Manager`, `Engineer`, `Intern`
// * Vehicles:
//     * Parent: `Vehicle` ( has `startEngine()`, `brand`)
//     * Children: `Car`, `Truck`, `Motorcycle`
// * Shapes:
//     * Parent: `Shape` ( has `color`, `getArea()`)
//     * Children: `Circle`, `Rectangle`, `Triangle`
//
//
// 5. Advantages (The Good Parts)
// ----------------------------
// 1.  Write Less Code: You write shared code (like `showInfo()`) just
//     one time in the parent class. All children can use it.
// 2.  Easy to Understand: It makes your code's plan clear.
//     Anyone can see that a Manager and Engineer are related.
// 3.  Easy to Fix or Update: If you find a bug in `showInfo()`,
//     you only fix it in the parent class.
// 4.  Keeps Things Tidy: Each child class can focus on its own
//     special job (like `conductMeeting()`).
//
// ========================================================================
//
//      END OF NOTES. C++ CODE BEGINS BELOW.
//
// ========================================================================


// This code demonstrates Hierarchical Inheritance
// using an Employee scenario.
//
// We will create one "Parent" class (Employee)
// and two "Child" classes (Manager and Engineer).
//
//      [ Employee ]  <-- Parent
//      /          \
//     /            \
// [ Manager ]    [ Engineer ]  <-- Children

#include <iostream>
#include <string>
using namespace std;

// ===================================
// 1. THE PARENT CLASS (Base Class)
// ===================================
// This class has the shared features for all employees.
// This shows "Advantage 1: Write Less Code"
// We write this code only ONCE.
class Employee {
protected:
    // We use 'protected' so child classes can see these
    string name;
    int employeeID;

public:
    // This function sets the shared data
    void setData(string n, int id) {
        name = n;
        employeeID = id;
    }

    // This function is shared by ALL children
    void showInfo() {
        cout << "Name: " << name << ", ID: " << employeeID << endl;
    }
};

// ===================================
// 2. THE FIRST CHILD CLASS (Derived Class 1)
// ===================================
// The syntax ": public Employee" means "Manager learns from Employee".
// A Manager "is a type of" Employee.
class Manager : public Employee {
public:
    // This is a special function *only* for a Manager.
    // This shows "Advantage 4: Keeps Things Tidy"
    void conductMeeting() {
        cout << "Manager " << name << " is conducting a team meeting." << endl;
    }
};

// ===================================
// 3. THE SECOND CHILD CLASS (Derived Class 2)
// ===================================
// The syntax ": public Employee" is used again.
// Both Manager and Engineer learn from the *same* parent.
// This is what makes it HIERARCHICAL.
// An Engineer "is a type of" Employee.
class Engineer : public Employee {
public:
    // This is a special function *only* for an Engineer.
    void writeCode() {
        cout << "Engineer " << name << " is writing C++ code." << endl;
    }
};


// ===================================
// 4. THE MAIN FUNCTION 
// ===================================
int main() {
    
    cout << "--- Manager's Details ---" << endl;
    Manager mgr1;
    mgr1.setData("Arjun Mankuskar", 101); // This function comes from the Parent (Employee)
    mgr1.showInfo();                  // This function ALSO comes from the Parent (Employee)
    mgr1.conductMeeting();            // This function is *only* for the Manager

    
    cout << "\n--- Engineer's Details ---" << endl;
    Engineer eng1;
    eng1.setData("Gandhar Chafle", 202);  // This function comes from the Parent (Employee)
    eng1.showInfo();                   // This function ALSO comes from the Parent (Employee)
    eng1.writeCode();                  // This function is *only* for the Engineer

    // This shows "Advantage 2: Easy to Understand"
    // We can clearly see Manager and Engineer are related.
    
    // If we found a bug in showInfo(), we would only need to
    // fix it in the Employee class.
    // This shows "Advantage 3: Easy to Fix or Update"

    return 0;
}

// ===================================
// 5. OUTPUT 
// ===================================
// 
//
// --- Manager's Details ---
// Name: Arjun Mankuskar, ID: 101
// Manager Arjun Mankuskar is conducting a team meeting.
//
// --- Engineer's Details ---
// Name: Gandhar Chafle, ID: 202
// Engineer Gandhar Chafle is writing C++ code.
//


