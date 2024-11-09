// WAP to implement a function to calculate the simple interest. Use the option of default value of rate of interest if it is not entered by the user. (C++).
#include <iostream>
using namespace std;
double calculateSimpleInterest(double principal, double time, double rate = 11.0) {
    return (principal * time * rate) / 100;
}
int main() {
    double principal, time, rate;
    char choice; // Y or y 
    cout << "\n\nEnter the principal amount: ";
    cin >> principal;
    cout << "Enter the time (in years): ";
    cin >> time;
    cout << "Do you want to enter the rate of interest? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        cout << "Enter the rate of interest: ";
        cin >> rate;
        cout << "Simple Interest = " << calculateSimpleInterest(principal, time, rate) << endl;
    } else {
        cout << "Simple Interest (with default rate of 11%) = " << calculateSimpleInterest(principal, time) << endl;
    }
    return 0;
}
