#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    // Overload + operator
    Complex operator + (const Complex& other) {
        Complex temp;
        temp.real = real + other.real;
        temp.imag = imag + other.imag;
        return temp;
    }

    // Overload - operator
    Complex operator - (const Complex& other) {
        Complex temp;
        temp.real = real - other.real;
        temp.imag = imag - other.imag;
        return temp;
    }

    // Overload * operator
    Complex operator * (const Complex& other) {
        Complex temp;
        temp.real = real * other.real - imag * other.imag;
        temp.imag = real * other.imag + imag * other.real;
        return temp;
    }

    // Display function
    void display() {
        cout << real << (imag >= 0 ? " + " : " - ") << abs(imag) << "i" << endl;
    }
};

int main() {
    Complex c1(2, 3);
    Complex c2(1, -4);

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;

    cout << "c1 = "; c1.display();
    cout << "c2 = "; c2.display();
    cout << "Sum = "; sum.display();
    cout << "Difference = "; diff.display();
    cout << "Product = "; prod.display();

    return 0;
}
