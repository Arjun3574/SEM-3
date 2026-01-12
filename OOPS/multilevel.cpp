#include <iostream>
using namespace std;

class A {
public:
    void a() { cout << "Class A\n"; }
};

class B : public A {
public:
    void b() { cout << "Class B\n"; }
};

class C : public B {
public:
    void c() { cout << "Class C\n"; }
};

int main() {
    C obj;
    obj.a();
    obj.b();
    obj.c();
    return 0;
}
