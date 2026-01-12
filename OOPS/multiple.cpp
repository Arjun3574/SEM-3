#include <iostream>
using namespace std;

class Base1 {
public:
    void b1() { cout << "Base1\n"; }
};

class Base2 {
public:
    void b2() { cout << "Base2\n"; }
};

class Derived : public Base1, public Base2 {
public:
    void d() { cout << "Derived (from Base1 and Base2)\n"; }
};

int main() {
    Derived obj;
    obj.b1();
    obj.b2();
    obj.d();
    return 0;
}
