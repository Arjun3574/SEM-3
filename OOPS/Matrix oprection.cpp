#include<iostream>
using namespace std;


int print(int n,int s[][100]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<s[i][j]<<" ";
		}
		cout<<endl;
	}
}

int mul(int n,int a[][100],int b[][100],int s[][100]){
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			s[i][j]=0;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				s[i][j]+=a[i][k]*b[k][j];
			}
			
		}
	}
	cout<<"Mul of 2 matrix: "<<endl;
	print(n,s);
}

int add(int n,int a[][100],int b[][100],int s[][100]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			s[i][j]=a[i][j] + b[i][j];
		}
	}
	cout<<"Addition of 2 matrix: "<<endl;
	print(n,s);
}

int main(){
	int n;
	cout<<"Enter row and col : ";
	cin>>n;
	int a[100][100],b[100][100],s[100][100];
	cout<<"Enter a matrix: ";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	cout<<"Enter b matrix: ";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>b[i][j];
		}
	}
	add(n,a,b,s);
	mul(n,a,b,s);
}
