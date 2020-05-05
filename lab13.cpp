#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student
{
	string first_name; // first twenty first-names
	string second_name; // first twenty middle-names
	string last_name; // first twenty middle-names
	double points; 
};

int main()

{
  // GRADE SCALE
  int A, B, C, D, E, F;

  // initialize grades at 0
	A = 0;
	B = 0;
  C = 0;
	D = 0;
	F = 0;

  double total; // total of grades to compute average
	double pointsNew; // total points, switch from int to double

	ofstream file;
	file.open("file.txt", ios::out);
	Student students[35];
	int n; // number of students
	cout << "Number of students: ";
	cin >> n;
  cout << endl; // add an extra line to keep code clear and concise

  // create for loop to get to get each students 
	for (int i = 0; i < n; i++) // loops for the number of students the user inputs
	{
		cout << "Name: ";
		cin >> students[i].first_name;
		cout << "Middle: ";
		cin >> students[i].second_name;
		cout << "Last: ";
		cin >> students[i].last_name;
		cout << "Points: ";
		cin >> students[i].points;
    cout << endl;

    pointsNew = students[i].points; // updates total each time a user's points are inputted
    total += pointsNew; // adds pointsNew into total to create average at the end

		file << students[1].first_name; // remove struct
	

  // if, else, and else if statements to demonstrate letter-grade standing
	if (pointsNew < 60)
  {
    F++;
  }		
	else
	{
		if (60 <= pointsNew && 70 > pointsNew)
				D++;
		else if (70 <= pointsNew && 80 > pointsNew)
				C++;
		else if (80 <= pointsNew && 90 > pointsNew)
				B++;
		else if (90 <= pointsNew && 100 >= pointsNew)
					A++;
  } // end else
    
} // end if

  cout << "# of students in group is " << n << endl;
	cout << "# of students with A degree is " << A << endl;
	cout << "# of students with B degree is " << B << endl;
	cout << "# of students with C degree is " << C << endl;
	cout << "# of students with D degree is " << D << endl;
	cout << "# of students with F degree is " << F;

  // all passing grades, excluding F's
	int passed = A + B + C + D; // add all of the grades together
	int avg = double(total / n); // average of all the grades by dividing by nymber of students in group

  cout << endl; // separate line to make it clean concise

  // display number of students who passed and the average of their scores
  cout << "Number of Students who passed: " << passed << endl;
  cout << "Average Score: " << avg << endl;


  // end of program closing the file
	file.close();
	return 0;
	system("pause");
}

// --- OUTPUT CODE COMMENTED ---
// Number of students: 5

// Name: Jaiden
// Middle: Alan
// Last: Hurt
// Points: 84

// Name: Kyndall 
// Middle: Nichole
// Last: Jones
// Points: 95

// Name: Jayda
// Middle: Mikel 
// Last: Heflin
// Points: 72

// Name: Dynasti 
// Middle: Erian
// Last: Collins
// Points: 80

// Name: Mariah
// Middle: Leah
// Last: Spencer
// Points: 76

// # of students in group is 5
// # of students with A degree is 1
// # of students with B degree is 2
// # of students with C degree is 2
// # of students with D degree is 0
// # of students with F degree is 0
// Number of Students who passed: 5
// Average Score: 81