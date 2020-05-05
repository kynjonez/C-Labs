#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
ifstream myfile;

bool is_hung(int);
int Question = 0; // change variable name
int no_errors = 0; // change variable name
string user_answer; // change variable name
string star = "**************************************************************";
// change variable name

int main () 
{
    myfile.open("answers.txt");
    string question, ans_A, ans_B, ans_C, ans_D, correct_answer, user_answer; // change variable name
    cout << "********** WELCOME to KYNDALL'S HANGMAN GAME! **********" << endl;
    cout << "Enter 7 incorrect answers and you'll lose";
    cout << endl;
    while (Question < 16)
    {
        getline(myfile, question);
        getline(myfile, ans_A);
        getline(myfile, ans_B);
        getline(myfile, ans_C);
        getline(myfile, ans_D);
        getline(myfile.ignore(16), correct_answer);

        cout << endl;
        cout << question << endl << ans_A << endl << ans_B << endl << ans_C << endl << ans_D << endl;
        cout << "Enter the capital letter of your answer: ";
        cin >> user_answer;
        cout << endl;

        if (user_answer == correct_answer)
        {
          cout << "CORRECT!!!" << endl << star << endl;
          cout << "You currently have " << no_errors << " errors." << endl;
          cout << star << endl;
        }
        else //if (user_answer != correct_answer)
        {
            cout << "INCORRECT!!!" << endl;
            no_errors++;
            cout << "Correct answer is: " << correct_answer << endl;
            cout << "You currently have " << no_errors << " errors" << endl;
            cout << endl;
            is_hung(no_errors);
            cout << endl;
            cout << star << endl;
        }
        if (no_errors == 7)
        {
          exit(0);
        }
      Question++;
    }
    myfile.close();
    return 0;
    exit(0);
}

bool is_hung(int no_errors)
{
    bool print = false;
    if (no_errors == 1)
    {
      cout << "\t \t \t" << " O " << endl; 
    }
    else if (no_errors == 2)
    {
      cout << "\t \t \t" << " O " << endl;
      cout << "\t \t \t" << " |" << endl; 
    }
    else if (no_errors == 3)
    {
      cout << "\t \t \t" << " O " << endl;
      cout << "\t \t \t" << "/|\\" << endl; 
    }
    else if (no_errors == 4)
    {
      cout << "\t \t \t" << " O " << endl;
      cout << "\t \t \t" << "/|\\" << endl;
      cout << "\t \t \t" << " | " << endl;
    }
    else if (no_errors == 5)
    {
      cout << "\t \t \t" << " O " << endl;
      cout << "\t \t \t" << "/|\\" << endl;
      cout << "\t \t \t" << " | " << endl;
      cout << "\t \t \t" << " | " << endl;
    }
    else if (no_errors == 6)
    {
      cout << "\t \t \t" << " O " << endl;
      cout << "\t \t \t" << "/|\\" << endl;
      cout << "\t \t \t" << " | " << endl;
      cout << "\t \t \t" << " | " << endl;
      cout << "\t \t \t" << "/  " << endl; 

    }
    else if (no_errors == 7)
    {
      cout << "\t \t \t" << " O " << endl;
      cout << "\t \t \t" << "/|\\" << endl;
      cout << "\t \t \t" << " | " << endl;
      cout << "\t \t \t" << " | " << endl;
      cout << "\t \t \t" << "/ \\" << endl;
      cout << " YOU ARE HUNG" << endl;
      
    }
  
    return print; 
  }


// --- OUTPUT CODE FOR LOST GAME ---
// ********** WELCOME to KYNDALL'S HANGMAN GAME! **********
// Enter 7 incorrect answers and you'll lose

// Question 1: What relational operator means greater than or equal to?
// A Answer: >
// B Answer: >=
// C Answer: =>
// D Answer: < 
// Enter the capital letter of your answer: A

// INCORRECT!!!
// Correct answer is: B
// You currently have 1 errors

//              O 

// **************************************************************

// Question 2: What two values does a bool variable allow?
// A Answer: 0 and 1
// B Answer: True or false
// C Answer: Yes and no
// D Answer: 1 and 2
// Enter the capital letter of your answer: A

// INCORRECT!!!
// Correct answer is: B
// You currently have 2 errors

//              O 
//              |

// **************************************************************

// Question 3: Which relational expression (where x is 4 and y is 8) is true?
// A Answer: x = y
// B Answer: x > y
// C Answer: x < = y
// D Answer: x >= y
// Enter the capital letter of your answer: A

// INCORRECT!!!
// Correct answer is: C
// You currently have 3 errors

//              O 
//             /|\

// **************************************************************

// Question 4: If we place an if statement within an if statement, we are creating a 
// A Answer: If-Then-Else statement
// B Answer: Multiway branch
// C Answer: If-Then-Else-If statement
// D Answer: Nested control structure
// Enter the capital letter of your answer: A

// INCORRECT!!!
// Correct answer is: D
// You currently have 4 errors

//              O 
//             /|\
//              | 

// **************************************************************

// Question 5: The && and || operators are
// Answer A: Binary operators
// Answer B: Unary operators
// Answer C: Secondary operators
// Answer D: Primary operators
// Enter the capital letter of your answer: A

// CORRECT!!!
// **************************************************************
// You currently have 4 errors.
// **************************************************************

// Question 6: To find out if either the test grade is an A or the quiz grade is an A we would write the expression 
// Answer A: testGrade = 'A' || quizGrade = 'A'
// Answer B: testGrade = 'A' && quizGrade = 'A'
// Answer C: testGrade == 'A' && quizGrade == 'A'
// Answer D: testGrade =='A' || quizGrade == 'A'
// Enter the capital letter of your answer: A

// INCORRECT!!!
// Correct answer is: D
// You currently have 5 errors

//              O 
//             /|\
//              | 
//              | 

// **************************************************************

// Question 7: Which two pairs of expressions are equivalent?
// A Answer: !(a == b) and a != b
// B Answer: !(a == b) and a =! B
// C Answer: (a == b)! and a != b
// D Answer: (a == b)! and a =! B
// Enter the capital letter of your answer: A

// CORRECT!!!
// **************************************************************
// You currently have 5 errors.
// **************************************************************

// Question 8: Which operator has the lowest precedence?
// A Answer: &&
// B Answer: ==
// C Answer: ||
// D Answer: =
// Enter the capital letter of your answer: A

// INCORRECT!!!
// Correct answer is: D
// You currently have 6 errors

//              O 
//             /|\
//              | 
//              | 
//             /  

// **************************************************************

// Question 9: An assertion that must be true before a module is executed for the module to execute correctly is a
// A Answer: Postcondition
// B Answer: Precondition
// C Answer: Priorcondition
// D Answer: Subsequentcondition
// Enter the capital letter of your answer: A

// CORRECT!!!
// **************************************************************
// You currently have 6 errors.
// **************************************************************

// Question 10: The While statement is different from the If statement because
// A Answer: It is a looping structure
// B Answer: It is used to repeat a course of action
// C Answer: The statement is either skipped, executed once, or executed over and over 
// D Answer: All of the above
// Enter the capital letter of your answer: A

// INCORRECT!!!
// Correct answer is: D
// You currently have 7 errors

//              O 
//             /|\
//              | 
//              | 
//             / \
//  YOU ARE HUNG

// **************************************************************