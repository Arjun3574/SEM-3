#include<iostream>
using namespace std;
/*
int fib(int n){
	if (n==0){
		return 0;
	}
	else if (n==1){
		return 1;
	}
	else{
		return fib(n-1)+fib(n-2);
	}

	
}


int main(){
	int n=2;
	for(int i=0;i<n;i++){
		cout<<fib(i)<<"\t";
	}
	return 0;
}*/


int main (){
	int a=-1, b=1;int c=a+b;
	cout<<c<<"\t";
	for (int i=0;i<8;i++){
		a=b;
		b=c;
		c=a+b;
		cout<<c<<"\t";
	}
}

