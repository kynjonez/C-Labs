#include <iostream>
#include <iomanip>
using namespace std;

float pounds;
float user_input();
float conversion(float input);

int main() {
    float input = user_input();
    conversion(input);
    return 0;
}

float user_input() {
    // title of my converter
    cout << "POUNDS TO KILOGRAMS CONVERTER" << endl;
    // takes user input
    cout << "Enter weight in pounds: ";

    float lbs;
    cin >> lbs;

    return lbs;
}

// conversion function
float conversion(float lbs) {
    // needs to be a float to round to 2 decimal points
    float kg;
    // to get pounds to kg, divide user input by 2.205
    kg = lbs / 2.205;

    // returns user's weight in kilograms
    // rounds return to two decimal places for final answer

    cout << fixed << showpoint;
    cout << "Your weight in kilograms is " << setprecision(2) << kg << endl;

    return kg; 
}

// OUTPUT OF MY CODE
// Enter weight in pounds: 115
// Your weight in kilograms is 52.15

// SIDE NOTE: thank you for helping me Dr. Hazzazi