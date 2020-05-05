#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void GetData(int&, int&);
// hours and miles are int
void PrintData(int, int);
// prints miles and hours


ofstream myfile;

int main()
{
    myfile.open("outputfile.txt"); // opens output file

    int miles;
    int hours;
    float MPH;
    GetData(miles, hours);
    PrintData(miles, hours);

    cout << fixed << showpoint;

    MPH = float(miles)/hours;
    
}

void GetData(int& miles, int& hours) 
{
    // prompt user to enter miles
    cout << "Enter the number of miles: ";
    cin >> miles; 

    cout << "Enter the number of hours: ";
    cin >> hours;

}


void PrintData(int miles, int hours)
{
    cout << fixed << showpoint << endl;
    float MPH; 
 
    MPH = float(miles)/float(hours);

    cout << "The number of miles is: " << setprecision(2) << miles << endl;
    cout << "The number of hours is: " << setprecision(2) << hours << endl;
    cout << "The number of miles per hour is: " << setprecision(2) << MPH << endl;

    myfile << setprecision(2) << endl;
    myfile << "The number of miles is: "  << miles << endl;
    myfile << "The number of hours is: " <<  hours << endl;
    myfile << "The number of miles per hour is: " << showpoint << fixed << MPH;

}

// --- OUTPUT ---

// Enter the number of miles: 289
// Enter the number of hours: 7

// The number of miles is: 289
// The number of hours is: 7
// The number of miles per hour is: 41.29