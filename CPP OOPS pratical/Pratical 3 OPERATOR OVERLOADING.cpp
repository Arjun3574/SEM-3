// Name: Arjun Mankuskar
// PRN No: 202401110038

#include <iostream>
using namespace std;

class Complex {
    float real, imag;

public:
    // Default constructor
    Complex() {
        real = 0;
        imag = 0;
    }

    // Parameterized constructor
    Complex(float r, float i) {
        real = r;
        imag = i;
    }

    // Operator overloading for '+'
    Complex operator+(const Complex &other) {
        Complex temp;
        temp.real = real + other.real;
        temp.imag = imag + other.imag;
        return temp;
    }

    // Display function
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1;               // uses default constructor
    Complex c2(3.5, 2.5),c3(1.5, 4.5);     // parameterized
   // Complex c3(1.5, 4.5);     // parameterized

    Complex result = c2 + c3; // operator+ used

    cout << "c1 = "; c1.display();
    cout << "c2 = "; c2.display();
    cout << "c3 = "; c3.display();
    cout << "Result = "; result.display();

    return 0;
}

/*
OUTPUT:-

c1 = 0 + 0i
c2 = 3.5 + 2.5i
c3 = 1.5 + 4.5i
Result = 5 + 7i
*/
