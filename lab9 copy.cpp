#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

myfile ifstream; 

enum CarMake{ Audi, Chrysler, Honda, Ford, Porche, Nissan, Lexus, Volvo, Mercedes};

struct Date

{
    int day;
    int month;
    int year;

};

struct Car

{
    string fname;
    string lname;
    double cost;
    struct Date date_delivery;
    CarMake make;

};

struct Car Get_car_data(ifstream &infile)

{

    struct Car c;

    char cmake;

    infile >> c.first_name;

    infile >> c.last_name;

    infile >> c.cost;

    infile >> c.date_delivery.day;

    infile >> c.date_delivery.month;

    infile >> c.date_delivery.year;

    infile >> cmake;

    switch(cmake)

    {

    case 'F':

         c.make = Ford;

         break;

    case 'L':

         c.make = Lexus;

         break;

    case 'N':

         c.make = Nissan;

         break;

    case 'M':

         c.make = Mercedes;

         break;

    case 'H':

         c.make = Honda;

         break;

    case 'A':

         c.make = Audi;

         break;

    case 'C':

         c.make = Chrysler;

         break;

    case 'V':

         c.make = Volvo;

         break;

    case 'P':

         c.make = Porche;

         break;

    }

    return c;

}

void Modify_Car_data(struct Car* c, float disc)

{

    cout<<"\nOld Price: $"<<c->cost<<endl;

    float discount = c->cost*disc;

    c->cost = c->cost- discount;

    cout<<"New Price: $"<<c->cost<<endl;

    cout<<disc*100<<"% Discount has been applied"<<endl<<endl;

}

void Lookup_car(struct Car* cl, int cars_cnt, char cmake)

{

    string cms[10]={"Audi", "Chrysler", "Honda","Ford", "Porche",

         "Nissan","Lexus", "Volvo", "Mercedes"};

    CarMake cm;

    switch(cmake)

    {

    case 'F':

         cm = Ford;

         break;

    case 'L':

         cm = Lexus;

         break;

    case 'N':

         cm = Nissan;

         break;

    case 'M':

         cm = Mercedes;

         break;

    case 'H':

         cm = Honda;

         break;

    case 'A':

         cm = Audi;

         break;

    case 'C':

         cm = Chrysler;

         break;

    case 'V':

         cm = Volvo;

         break;

    case 'P':

         cm = Porche;

         break;

    }

    cout<<"\n\nYou are modifying: ";

    for(int i=0; i<cars_cnt; i++, cl++)

    {

         if( cl->make == cm)

         {

             float disc;

             cout<<"\n\tCustomer Name: "<< cl->first_name<<" "<< cl->last_name;

             cout<<"\n\tCar Price:     $"<<cl->cost;

             cout<<"\n\tPurchase Date: "<<cl->dod.day<<"/"

                 <<cl->dod.month<<"/"<<cl->dod.year;

             cout<<"\n\tCar Model:     "<<cms[(int)cl->make]<<endl;

             cout<<"Enter the disocunt (e.g 0.10 = 10%): ";

             cin>>disc;

             Modify_Car_data(cl, disc);

             break;

         }

    }

}

void Print_Car_Report(struct Car *cl, int c_count)

{

    string cm[10]={ "Audi", "Chrysler", "Honda","Ford", "Porche",

         "Nissan","Lexus", "Volvo", "Mercedes"};

    cout<<"\n====== Cars Detail ======="<<endl;

    cout<<"\nCustomer \t Price \t\t Purchase \t Model\n";

    cout<<" Name     \t       \t\t   Date    \t       "<<endl;

    cout<<"-----------------------------------------------------------\n";

    for( int i=0; i<c_count; i++, cl++)

    {

         cout<<cl->first_name<<" "<< cl->last_name;

         cout<<"\t"<<setw(7)<<cl->cost;

         cout<<setw(10)<<cl->dod.day<<"/"<<cl->dod.month<<"/"<<cl->dod.year;

         cout<<setw(15)<<cm[(int)cl->make]<<endl;

    }

}

void Write_Car_Output(struct Car *cl, int c_count, string fn)

{

    string cm[10]={ "Audi", "Chrysler", "Honda",    "Ford", "Porche",

         "Nissan","Lexus", "Volvo", "Mercedes"};

    ofstream of(fn);

    of<<"\nCustomer \t Price \t\t Purchase \t Model\n";

    of<<" Name     \t       \t\t   Date    \t       "<<endl;

    of<<"-----------------------------------------------------------\n";

    for( int i=0; i<c_count; i++, cl++)

    {

         of<<cl->first_name<<" "<< cl->last_name;

         of<<"\t"<<setw(7)<<cl->cost;

         of<<setw(10)<<cl->dod.day<<"/"<<cl->dod.month<<"/"<<cl->dod.year;

         of<<setw(15)<<cm[(int)cl->make]<<endl;

    }

    of.close();

}

void Output_car_data(struct Car *cl, int c_count, string fn)

{

    Print_Car_Report(cl, c_count);

    Write_Car_Output(cl, c_count, fn);

}

int main()

{

    struct Car cars[20];

    int cars_cnt=0;

    ifstream car_data_file("Car_data.txt");

    int i=0;

    char ch = 'Y';

    char cmake;

    string Codes[9]={"F - Ford"," L - Lexus"," N - Nissan",

         " M - Mercedes","H - Honda"," A - Audi","C - Chrysler"," V - Volvo"," P - Porche"};

    while( !car_data_file.eof())

    {

         cars[cars_cnt] = Get_car_data(car_data_file);

         cars_cnt++;

    }

    while(ch!='N' && ch!='n')

    {

         cout<<"Choose form the list of car manufacturers below."<<endl;

         cout<<"\t(";

         for(int i=0;i<9;i++)

         {           

             if(i%3==0)

                 cout<<endl<<"\t";

             if(i==8)

                 cout<<Codes[i]<<")"<<endl;

             else

             {

                 cout<<Codes[i]<<", ";         

             }

         }

         cout<<endl;

         cout<<"\nEnter the make of the car you wish to discount: ";

         cin>>cmake;

         Lookup_car(cars, cars_cnt-1, cmake);

         cout<<"Do you want to modify another car: ";

         cin>>ch;

    }

    Output_car_data(cars, cars_cnt-1, "Car_Discount_Data.txt");

    system("pause");

    return 0;

}