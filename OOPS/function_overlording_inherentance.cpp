#include<iostream>
using namespace std;

class first{
	public:
		void add(int a, int b){
			cout<<"Add 2 : "<<a+b;
		}
};

class second : public first{
	public:
		using first::add;
		void add(int a, int b,int c){
			cout<<"\nAdd 3 : "<<a+b+c;
		}
};

class third: public second{
	public:
		using second::add;
		void add(int a,int b,int c,int d){
			cout<<"\nAdd 4 : "<<a+b+c+d;
		} 
};

int main(){
	third obj;
	obj.add(1,2);
	obj.add(1,2,3);
	obj.add(1,2,3,4);
}
