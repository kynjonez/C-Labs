#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std; 

struct CarType getCarData(ifstream&);                           //Function Prototypes
void Lookup_Car_data(char, CarType[]);
void Modify_Car_data(float, int, CarType[]);
void Output_car_data(CarType[], ofstream&);
void Print_Car_report(CarType[]);
void Write_Car_Output(CarType[], ofstream&);
struct CarType getCarData(ifstream& infile) 

enum CarMakeType {Audi, Chrysler, Ford, Honda, Lexus, Mercedes, Nissan, Porche, Volvo};

struct DateType {               //Make a date struct that contains information about day, month, and year.
    int day;                    //Declare struct variables (ALL INT).
    int month;
    int year;
};
struct CarType{                  //Make struct that contains information about the customer, delivery date of the car, cost, and car model.
    string fname;                //Declare struct variables.
    string lname;
    float cost;
    DateType date_delivery;
    CarMakeType car_make;
};

struct CarType getCarData(ifstream& infile)
{
    struct CarType car;
    char in_make;

    infile >> car.fname;
    infile >> car.lname;
    infile >> car.cost;
    infile >> car.date_delivery.day;
    infile >> car.date_delivery.month;
    infile >> car.date_delivery.year;
    infile >> in_make;

    switch(in_make) {
        case 'F':
            car.in_make = Ford;
            break;
        case 'L':
            car.in_make = Lexus;
            break;
        case 'N':
            car.in_make = Nissan;
            break;
        case 'M':
            car.in_make = Mercedes;
            break;
        case 'H':
            car.in_make = Honda;
            break;
        case 'A': 
            car.in_make = Audi;
            break;
        case 'C':
            car.in_make = Chrysler;
            break;
        case 'V':
            car.in_make = Volvo;
            break;
        case 'P':
            car.in_make = Porche;
            break;
        
    }
    return car;
}
void Modify_car_data(struct CarType* car, float disc)

int main () 
{
    ifstream myfile; 
    myfile.open("infile9.txt")
    
    int count;
    count = 1;

    while(myfile) // EOF test
    {
       carList[count] = getCarData(myfile)
       count++;
    }

}

void Lookup_Car_data(char c, CarType cars[]) 
{
    carMakeType cmake,
    switch (c)
}