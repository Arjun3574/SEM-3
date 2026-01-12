// Title: Scenario: Car Dealership – Branch ID, Customer ID
// Name: Arjun Mankuskar
// PRN No: 202401110038

#include <iostream>
using namespace std;

class CarDealership {
    int branchId;
    int customerId;

public:
    ~CarDealership() {
        cout << "Destructor"<<endl;
    }

    // Default constructor
    CarDealership() {
    	branchId=413512;
        cout << "Branch ID = " << branchId<<endl;
    }

    // Parameterized constructor
    CarDealership(int c) {
        customerId = c;
        cout<<"Enter customerId :";
        cin>>customerId;
        cout << "Customer ID =" << customerId<<endl;
    }

    // Copy constructor
    CarDealership(CarDealership & newCar) {
        branchId = newCar.branchId;
        cout << "Branch ID =" << branchId<<endl;
    }
};

int main() {
	int customerId;
	string cusname;
	cout <<"Info about 1st Order:"<<endl;
    CarDealership ord1;
    cout<<"Enter Customer name:";
    cin>>cusname;
    CarDealership ord2(customerId);
    CarDealership ord3(ord1);
    cout<<"*********************************"<<endl;
    cout <<"\nInfo about 2nd Order:"<<endl;
    CarDealership ord4;
    cout<<"Enter Customer name:";
    cin>>cusname;
    CarDealership ord5(customerId);
    CarDealership ord6(ord1);
     cout<<"*********************************"<<endl;
    
}



/********************Output****************/
/*
Info about 1st Order:
Branch ID = 413512
Enter Customer name:Arjun
Enter customerId :700
Customer ID =700
Branch ID =413512
*********************************

Info about 2nd Order:
Branch ID = 413512
Enter Customer name:Kalyani
Enter customerId :701
Customer ID =701
Branch ID =413512
*********************************
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
*/
