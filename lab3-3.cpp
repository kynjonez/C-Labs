// Write a program that calls a value-returning function that prompts the user to enter 
// the weight of a person in pounds and then calls another 
// value returning function to calculate the equivalent weight in kilograms. 
// Output both the weights rounded to two decimal places. (Note that 1 kilogram = 2.2 pounds.) 
// Format your output with two decimal places.

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double lbs;
    double kg;

    cout << "POUNDS TO KILOGRAMS CONVERT:" << endl;
    cout << "Enter weight in pounds: " << endl;
    cin >> lbs;
    cout << endl; 

    kg = 0.45 * lbs;
    lbs = 2.2 * kg;

    cout << "Your weight in kilograms is " << kg << endl;
    cout << endl;

    return 0; 
}

// OUTPUT OF MY CODE
// Enter weight in pounds: 115
// Your weight in kilograms is 52.1631