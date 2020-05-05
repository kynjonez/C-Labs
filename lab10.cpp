#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

const int months = 5;
const int stores = 7;


void get_store_data(ifstream &myfile, string [], float [][months]);
float Compute_Store_total(float[][months], int);
void Display_Store_data(string[], float[][months], float[]);

ifstream myfile("infile10.txt");

int main () 
{
    float total[7];

    string name[stores];
    float sales[stores][months];
    get_store_data(myfile, name, sales);

    for (int index = 0; index < 7; index++)
    {
        total[index] = Compute_Store_total(sales, index);
    }
  Display_Store_data(name, sales, total);
    
    return 0;
}

void get_store_data(ifstream &myfile, string name[], float sales_arr[][months])
{
    for (int i = 0; i < 7; i++) 
    {
        myfile >> name[i];
        for (int j=0; j < months; j++) 
        {
            myfile >> sales_arr[i][j];
        } 
    }
} 

float Compute_Store_total(float sales_arr[7][months], int store_index) 
{
    float total = 0.0;
    for (int x=0; x < months; x++)
    {
        total += sales_arr[store_index][x];
    }
  return total;
}

void Display_Store_data(string name[stores], float sales[stores][months], float total[stores])
{
      cout << "   " << "STORE NAME" << " " << setw(9) << "JAN" << setw(9) << "FEB" << setw(9) << "MAR" << setw(9) << "APR" << setw(9) << "MAY" << setw(9) << "TOTAL" << endl;
      cout << endl;
      for(int y = 0; y < stores; y++) 
      {
          cout << setw(14)<<name[y] ;
          for (int z = 0; z < months; z++)
          {
            cout << fixed << showpoint; 
            cout << setw(9) << setprecision(2) << sales[y][z] << setw(9);
          }
          cout << setw(9) << fixed << showpoint << total[y] << setprecision(2) << endl;
      }
 }

// ---- OUTPUT CODE ----

//    STORE NAME       JAN      FEB      MAR      APR      MAY    TOTAL

//   Takoma_store     2.70    71.30    14.70    23.90    51.20   163.80
// Bethesda_store    12.70     8.90    17.80     7.90    18.30    65.60
// Baltimore_store   123.50   134.80   564.60   451.80   521.90  1796.60
//  Distric_store    56.20    26.50   123.40   456.70   789.30  1452.10
//   Prince_store    23.10    28.30    12.90   120.00    45.80   230.10
// Columbia_store    21.50   123.00    80.90    99.00    91.20   415.60
//    Bowie_store   100.00   100.00   100.00   100.00   100.00   500.00
