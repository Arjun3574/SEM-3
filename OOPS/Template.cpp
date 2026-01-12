#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) { return a + b; }

template <typename T>
T sub(T a, T b) { return a - b; }

template <typename T>
T mul(T a, T b) { return a * b; }

template <typename T>
T divi(T a, T b) { return a / b; }





template <class T>
	class SY{
		T var1;
		public :
			SY(T var2){
				var1=var2;
			}
			void show (){
				cout<<var1;
			}
	};	
	
	
int main() {
    cout << add(20, 10) << endl;
    cout << sub(20, 10) << endl;
    cout << mul(20, 10) << endl;
    cout << divi(20, 10) << endl;
    cout << add(20.1, 10.1) << endl;
    
    SY<int> obj(1);
    SY<float> obj1(1.2);
	obj.show();
	obj1.show(); 
}
