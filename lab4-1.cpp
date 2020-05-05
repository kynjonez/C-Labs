#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main () { 
string line; 
ifstream anyFileName ("Lab4in.txt"); 
if (anyFileName.is_open()) 
{    while ( getline (anyFileName,line) )   
{      cout << line << '\n';   
}   
anyFileName.close(); 
}
  else cout << "Unable to open file"; 
  return 0;
}

// ----OUTPUT CODE # 1----

// Hello from the other side
// I must've called a thousand times
// To tell you I'm sorry