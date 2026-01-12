#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() { cout << "Some generic animal sound\n"; }
};

class Dog : public Animal {
public:
    void sound() override { cout << "Dog barks!\n"; }
};

void printMessage(char* msg) {
    cout << "Message: " << msg << endl;
}

int main() {
    // ------------------------------
    // 1. Implicit Type Casting
    // ------------------------------
    int a = 5;
    double b = a + 2.5;  // int automatically converted to double
    cout << "Implicit casting (int + double): " << b << endl;

    // ------------------------------
    // 2. Explicit (C-style) Casting
    // ------------------------------
    double pi = 3.14159;
    int intPi = (int)pi;  // manual cast to int
    cout << "Explicit (C-style) casting double -> int: " << intPi << endl;

    // ------------------------------
    // 3. static_cast
    // ------------------------------
    int x = 10;
    double y = static_cast<double>(x); // safer cast
    cout << "static_cast int -> double: " << y << endl;

    // ------------------------------
    // 4. dynamic_cast
    // ------------------------------
    Animal* animalPtr = new Dog();      // Base pointer to Derived object
    Dog* dogPtr = dynamic_cast<Dog*>(animalPtr);
    if (dogPtr)
        cout << "dynamic_cast successful! It’s a Dog.\n";
    else
        cout << "dynamic_cast failed.\n";

    // ------------------------------
    // 5. const_cast
    // ------------------------------
    const char* message = "Hello Students!";
    printMessage(const_cast<char*>(message)); // remove const safely

    // ------------------------------
    // 6. reinterpret_cast
    // ------------------------------
    int num = 65;
    char* ch = reinterpret_cast<char*>(&num);
    cout << "reinterpret_cast int -> char*: " << *ch << endl;

    // Cleanup
    delete animalPtr;

    return 0;
}
