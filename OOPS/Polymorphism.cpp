#include<iostream>
using namespace std;

class shape {
	public:
		
		
		void area(int a ){
		cout<<"Area of  square is:"<<a*a<<endl;
	}
	
	void area(int a,int b){
		cout<<"Area of Rectangle is:"<<a*b<<endl;
	}
	
	void area(float c ,float l,float b){
		cout<<"Area of Tritangle is:"<<c*l*b<<endl;
	}
	
	void area(double r){
		cout<<"Area of circle is:"<<3.14*r*r<<endl;
	}
	
};

int main (){
	shape s;
	int sq,r1,r2,t1,t2;
	double c;
	cout<<"Enter side of square in integer:";
	cin>>sq;
	s.area(sq);
	cout<<endl;
	
	cout<<"Enter Length in integer for Rectangle area:";
	cin>>r1;
	cout<<"Enter Breath in integer for Rectangle area:";
	cin>>r2;
	s.area(r1,r2);
	cout<<endl;
	
	cout<<"Enter Length and Breath in integer for Triangle area:";
	cin>>t1;
	cout<<"Enter Breath in integer for Triangle area:";
	
	
	cin>>t2;
	s.area(0.5,t1,t2);
	cout<<endl;
	
	cout<<"Enter radius of circle in decimal:";
	cin>>c;
	s.area(c);  
	
	return 0;
}
