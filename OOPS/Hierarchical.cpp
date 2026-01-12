#include<iostream>
using namespace std;

class B {
	public:
		void show(){
			cout<<"Base Class\n";
		}
};

class D1:public B{
	public:
		void DisplayD1(){
			cout<<"Derived class D1\n";
		}
};

class D2:public B{
	public:
		void DisplayD2(){
			cout<<"Derived class D2\n";
		}
};

int main(){
	D1 obj1;
	obj1.show();
	obj1.DisplayD1();
	
	cout<<"***********************************\n";
	
	D2 obj2;
	obj2.show();
	obj2.DisplayD2();
	
	return 0;
}
