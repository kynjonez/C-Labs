#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () { 
string line; 
int sum;
int num1;

ifstream anyFileName ("Lab4in-3.txt"); 
if (anyFileName.is_open()) 
{    while ( getline (anyFileName,line) ) 
{   
        num1 = stoi(line);
        sum += num1;
}   
cout << sum;

anyFileName.close(); 
}
  else cout << "Unable to open file"; 
  return 0;
}


// ----OUTPUT CODE #3----
// 20