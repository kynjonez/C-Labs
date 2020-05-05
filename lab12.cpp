#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

ifstream myfile("infile-12.txt");

class Student
{
  private:
    string fname; // first name of student
    string lname; // last name of student
    int G1, G2, G3, G4, G5, G6, G7; // grades for labs 1-7
    int total;


  public:
    string Constructor = "Construtor works\n";
    string Deconstructor = "Deconstructor works \n";
    Student();
    Student(string);
    ~Student(); // deconstructor
  

    void computeGrade(); // computes student grade
    void getGrade();

}; 

int main ()
{
  // Declare students
  Student stu1;
  Student stu2;
  Student stu3;
  Student stu4;
  
  // Grades for Students 1
  stu1.getGrade();
  stu1.computeGrade();
  // Grades for Students 2
  stu2.getGrade();
  stu2.computeGrade();
  // Grades for Students 3
  stu3.getGrade();
  stu3.computeGrade();
  // Grades for Students 4
  stu4.getGrade();
  stu4.computeGrade();
  
  return 0;
}

// Constructor
Student::Student()
{
  G1 = 0;
  G2 = 0;
  G3 = 0;
  G4 = 0;
  G5 = 0; 
  G6 = 0;
  G7 = 0;

  fname = "null";
  lname = "null";

}

Student::Student(string Constructor)
{
  cout << Constructor;
}
Student::~Student()
{
  cout << Deconstructor;
}

void Student::getGrade()
{
  myfile >> fname >> lname >> G1 >> G2 >> G3 >> G4 >> G5 >> G6 >> G7; 
  
  // Header
  cout << "STUDENT: " << fname << " " << lname << endl;
  // Display student grades
  cout << "Lab Grades: " << G1 << " " << G2 << " " << G3 << " " << G4 << " " << G5 << " " << G6 << " " << G7 << endl;
}

void Student::computeGrade()
{
  int total;
  float gradeAverage;
  
  for(int index = 0; index < 4; index++)
    for(int index = 0; index < 7; index++)
    {
      total = G1 + G2 + G3 + G4 + G5 + G6 + G7;
      gradeAverage = float(total)/7; // divide all grades by 7
    }
  cout << fixed << showpoint << setprecision(2);
  cout << "Total Grade for " << fname << ": " << total << endl;
  cout << "Grade Average for " << fname << ": " << gradeAverage << endl;
  cout << endl;
}


