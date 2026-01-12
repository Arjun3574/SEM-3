#include <iostream>
#include <iomanip> // 1. IMPORTANT: Include this header
using namespace std;

int main() {
    double num = 10.5;
    double pi = 3.14159265;

    // 2. Use 'fixed' and 'setprecision'
    cout << fixed << setprecision(2);

    cout << "Number: " << num << endl; // Prints 10.50
    cout << "Pi:     " << pi << endl;  // Prints 3.14 (Rounds automatically)
printf("%.2f", pi); // Prints 3.14
    return 0;
}
