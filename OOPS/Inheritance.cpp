#include<iostream>
using namespace std;

class a{
	int roll;
	public:
		void get(){
			cout<<"Enter Roll: ";
			cin>>roll;
		}
};

class b:public a{
	int grade;
	public:b(){
		grade=100;
	}
		
		void disp(){
			get();
			
			cout<<"\n Grade= "<<grade;
		}
};

int main(){
	b obj;
	obj.disp();
	
	
	
	return 0;
}
