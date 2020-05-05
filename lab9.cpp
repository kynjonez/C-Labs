#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

struct CarType getCarData(ifstream&); //Prototype
void Lookup_Car_data(char, CarType[]); //Prototype
float Modify_Car_data(float, int, CarType[]); //Prototype
void Output_Car_data(CarType[], ofstream&); //Prototype
void Print_Car_report(CarType[]); //Prototype
void Write_Car_Output(CarType[], ofstream&); //Prototype

enum CarMakeType {Audi, Chrysler, Ford, Honda, Lexus, Mercedes, Nissan, Porche, Volvo};

struct DateType //struct for delivery dates
{
   int month;
   int day;
   int year;
};

struct CarType // info
{
   string fname;
   string lname;
   float cost;
   DateType date_delivery;
   CarMakeType make;
};

int main()
{
   char askAgain, make;
   CarType cars[10];
   ifstream myFile;
   ofstream outFile;
   myFile.open("infile9.txt");
   outFile.open("outfile9.txt");
   //Counter for elements in Car array
   int count = 1;
   cars[0] = getCarData(myFile);
   while (myFile && (count <= 9)) {
       cars[count] = getCarData(myFile);
       count++;
   }
   do
   {
       cout << "Choose from the list of car manufacturers below." << endl
           << "F - Ford, L - Lexus, N- Nissan, M - Mercedes, H - Honda," << endl
           << "A - Audi, C - Chrysler, V - Volvo, P - Porche>" << endl << endl;
       
       cout << "Enter the make of the car you wish to discount: ";
       //Take user's input
       cin >> make;
       //Call look up car data function
       Lookup_Car_data(make, cars);
       //Prompt user to find out if (s)he would like to continue modifying car files
       cout << "Do you want to discount any more cars? ";
       //Record user's answer
       cin >> askAgain;
   } while (askAgain != 'N');
   Output_Car_data(cars, outFile);
}
CarType getCarData(ifstream& infile)
{
   CarType car;
   char carMake;
   infile >> car.fname >> car.lname >> car.cost >> car.date_delivery.month
       >> car.date_delivery.day >> car.date_delivery.year >> carMake;
   //Switch statement to store car make
   switch (carMake)
   {
       case 'F':
           car.make = Ford; break;
       case 'L':
           car.make = Lexus; break;
       case 'N':
           car.make = Nissan; break;
       case 'M':
           car.make = Mercedes; break;
       case 'H':
           car.make = Honda; break;
       case 'A':
           car.make = Audi; break;
       case 'C':
           car.make = Chrysler; break;
       case 'V':
           car.make = Volvo; break;
       case 'P':
           car.make = Porche; break;
   }
   //Return car struct to main
   return car;
}

void Lookup_Car_data(char carComp, CarType car[])
{
   CarType cars;
   string carManufact;
   float disc;
   int count;

   switch (carComp)
   {
       case 'F':
           cars.make = Ford; carManufact = "Ford"; break;
       case 'L':
           cars.make = Lexus; carManufact = "Lexus"; break;
       case 'N':
           cars.make = Nissan; carManufact = "Nissan"; break;
       case 'M':
           cars.make = Mercedes; carManufact = "Mercedes"; break;
       case 'H':
           cars.make = Honda; carManufact = "Honda"; break;
       case 'A':
           cars.make = Audi; carManufact = "Audi"; break;
       case 'C':
           cars.make = Chrysler; carManufact = "Chrysler"; break;
       case 'V':
           cars.make = Volvo; carManufact = "Volvo"; break;
       case 'P':
           cars.make = Porche; carManufact = "Porche"; break;
   }

   for (count = 0; count <= 9; count++)
   {
       if (cars.make == car[count].make)
       {
           break;
       }
   }
   cout << "\n\nYou are modifying : " << endl;
   cout << "\tCustomer Name: " << car[count].fname << " " << car[count].lname << endl;
   cout << "\tCar Price:\t$" << fixed << setprecision(2) << car[count].cost << endl;
   cout << "\tPurchase Date: " << car[count].date_delivery.month << "/" << car[count].date_delivery.day
       << "/" << car[count].date_delivery.year << endl;
   cout << "\tCar Model:\t" << carManufact;

   //Ask user to enter discount
   cout << "Enter the discount <e.g. 0.10 = 10%>: ";
   
   //Store discount
   cin >> disc;
   cout << endl << endl;

   cout << "Old Price : $" << fixed << setprecision(2) << car[count].cost << endl;
   car[count].cost = Modify_Car_data(disc, count, car);
   cout << "New Price: $" << fixed << setprecision(2) << car[count].cost << endl;
   count = 0;
   float percent = 100 * disc;
   cout << percent << "% Discount has been applied" << endl;
}

float Modify_Car_data(float discount, int index, CarType car[])
{
   float price = car[index].cost - (car[index].cost * discount);
   //Return price
   return price;
}

void Output_Car_data(CarType car[], ofstream& outFile)
{
   Print_Car_report(car);
   Write_Car_Output(car, outFile);
}

void Print_Car_report(CarType car[])
{
   string carManufact;
   cout << "Customer\tPrice\t\tPurchase\tModel" << endl;
   cout << setw(6) << " Name\t\t\t\t   Date" << endl << endl;

   for (int count = 0; count <= 9; count++)
   {
       cout << car[count].fname << " " << car[count].lname << "\t" << fixed << setw(8) <<
           setprecision(2) << car[count].cost << "\t" << car[count].date_delivery.month << "/"
           << car[count].date_delivery.day << "/" << car[count].date_delivery.year << "\t";

       switch (car[count].make)
       {
           case Ford:
               carManufact = "Ford"; break;
           case Lexus:
               carManufact = "Lexus"; break;
           case Nissan:
               carManufact = "Nissan"; break;
           case Mercedes:
               carManufact = "Mercedes"; break;
           case Honda:
               carManufact = "Honda"; break;
           case Audi:
               carManufact = "Audi"; break;
           case Chrysler:
               carManufact = "Chrysler"; break;
           case Volvo:
               carManufact = "Volvo"; break;
           case Porche:
               carManufact = "Porche"; break;
       }
       cout << carManufact << endl;
   }
}

void Write_Car_Output(CarType car[], ofstream& outFile)
{
   string carManufact;

   for (int count = 0; count <= 9; count++)
   {
       outFile << car[count].fname << " " << car[count].lname << " " << car[count].cost
           << " " << car[count].date_delivery.month << " " << car[count].date_delivery.day << " "
           << car[count].date_delivery.year << " ";

       switch (car[count].make)
       {
           case Ford:
               carManufact = "Ford"; break;
           case Lexus:
               carManufact = "Lexus"; break;
           case Nissan:
               carManufact = "Nissan"; break;
           case Mercedes:
               carManufact = "Mercedes"; break;
           case Honda:
               carManufact = "Honda"; break;
           case Audi:
               carManufact = "Audi"; break;
           case Chrysler:
               carManufact = "Chrysler"; break;
           case Volvo:
               carManufact = "Volvo"; break;
           case Porche:
               carManufact = "Porche"; break;
       }
       outFile << carManufact << endl;
   }
}