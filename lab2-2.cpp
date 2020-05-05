#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void heading();   //function prototype
float divide_sum();

float divide_sum(int value_1, int value_2, int value_3, int value_4, int value_5); // function prototype
void display_answer(float ); // function prototype

int main()
{
    // PROBLEM #1
    // heading which takes no parameters
    heading();

    // integer = number
    const int integer1 = 1066;
    const int integer2 = 1492;
    const int integer3 = 512;
    const int integer4 = 1;
    const int integer5 = -23;

    // PROBLEM #2
    // make values named constant

    // integer = number
    cout << setw(5) << integer1;
    cout << setw(5) << integer2;
    cout << setw(5) << integer3;
    cout << setw(5) << integer4;
    cout << setw(5) << integer5 << endl; 

    cout << fixed << showpoint;

    // PROBLEM #3
    // modify to prompt inputing 5 numbers
    int value_1;
    int value_2;
    int value_3;
    int value_4;
    int value_5;

    cout << "Please enter five integers: " << endl;
    cin >> value_1 >> value_2 >> value_3 >> value_4 >> value_5;

    divide_sum(value_1, value_2, value_3, value_4, value_5);

    return 0;
}

void heading() 
  {
    cout << "This function is a void. It returns nothing." << endl;
  }


  float divide_sum(int value_1, int value_2, int value_3, int value_4, int value_5) 

{
    float first_sum = value_1 + value_2;
    float second_sum = value_3 + value_4 + value_5;

    float OUTCOME = first_sum / second_sum; 

    display_answer(OUTCOME);

    return OUTCOME;
  }
void display_answer(float ans)
{
    // displays the answer of users input
    cout << "The result is " << setprecision(4) << ans << endl;

}


// OUTPUT FROM MY CODE - KYNDALL JONES
// This function is a void. It returns nothing.
// 1066 1492  512    1  -23
// Enter five numbers:
// 567 67 67 78 98
// The result is 2.6091
