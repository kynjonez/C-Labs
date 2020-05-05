#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main () {  
  string firstN, lastN; 
  ifstream anyFileName; 
  anyFileName.open("lab4in-2.txt"); 
{   
int a = 0;   
while ( a<3 )   
{     
anyFileName >> firstN >> lastN;     
cout << "full name is " << firstN << " " << lastN << '\n';     
a++;   

}   
{
 anyFileName.close();  
  
  return 0; 
}}}

// ----OUTPUT CODE #2----
// full name is Kyndall Jones
// full name is Jayda Heflin
// full name is Jaiden Hurt