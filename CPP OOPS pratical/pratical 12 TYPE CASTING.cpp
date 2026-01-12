//Name:Arjun Mankuskar
//PRN:202401110038
//Title:TYPE CASTING

#include <iostream>
using namespace std;

//IMPLICIT TYPECASTING
// 1. int to float
void implicit_int_to_float() {
    int a = 10;
    float b = a + 5.5f; 
    cout << "\nint + float = " << b << "  (int promoted to float)";
}

// 2. char to int
void implicit_char_to_int() {
    char ch = 'A';
    int val = ch; 
    cout << "\nchar '" << ch << "' converted to int = " << val;
}

// 3. int to double
void implicit_int_to_double() {
    int x = 7;
    double y = x + 3.25; 
    cout << "\nint + double = " << y << "  (int promoted to double)";
}

// 4. short to int
void implicit_short_to_int() {
    short s = 100;
    int total = s + 50; 
    cout << "\nshort + int = " << total << "  (short promoted to int)";
}

// EXPLICIT TYPECASTING  
// 5. float to int
void explicit_float_to_int() {
    float f = 9.8f;
    int i = static_cast<int>(f); 
    cout << "\nfloat " << f << " converted to int = " << i;
}

// 6. int to char
void explicit_int_to_char() {
    int x = 66;
    char c = static_cast<char>(x); 
    cout << "\nint " << x << " converted to char = '" << c << "'";
}

// 7. double to int
void explicit_double_to_int() {
    double d = 15.75;
    int i = static_cast<int>(d);
    cout << "\ndouble " << d << " converted to int = " << i;
}

// 8. int to float (prevent integer division)
void explicit_int_to_float() {
    int a = 7, b = 2;
    float result = static_cast<float>(a) / b; 
    cout << "\n" << a << " / " << b << " = " << result << "  (using explicit float cast)";
}


int main() {
    cout << "\nIMPLICIT TYPECASTING";
    implicit_int_to_float();
    implicit_char_to_int();
    implicit_int_to_double();
    implicit_short_to_int();

    cout << "\n\nEXPLICIT TYPECASTING";
    explicit_float_to_int();
    explicit_int_to_char();
    explicit_double_to_int();
    explicit_int_to_float();

    return 0;
}


/*

IMPLICIT TYPECASTING
int + float = 15.5  (int promoted to float)
char 'A' converted to int = 65
int + double = 10.25  (int promoted to double)
short + int = 150  (short promoted to int)

EXPLICIT TYPECASTING
float 9.8 converted to int = 9
int 66 converted to char = 'B'
double 15.75 converted to int = 15
7 / 2 = 3.5  (using explicit float cast)
--------------------------------
*/
