#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// parameters are commented
// string read_month_name(string); // month name
// int print_month(string, string, int, int); // first day, last day, no of days, month name
// void print_heading(int); // year
// int get_starting_day(); // start date
// int get_year(); // year
// int read_num_days(); // num day

ifstream myfile;


int get_year() {
    // prompting user to enter year
    int Fyear;

    cout << "ENTER YEAR -- " << endl;
    cin >> Fyear;
    return Fyear;
}

int get_starting_day() {
    int start_date;
    // prompt user to enter start day
    cout << "ENTER START DATE <0 = Sun, 1 = Mon, 2 = Tues, 3 = Wednesday, 4 = Thur, 5 = Fri, 6 = Sat>: ";
    cin >> start_date;

    return start_date;
}

void print_heading(int Fyear) {
    cout << setw(19) << "   YEAR    " << Fyear << endl;
    cout << "Sun: " << "Mon: " << "Tue: " << "Wed: " << "Thu: " << "Fri: " << "Sat: \n";
}

string read_month_name() {
    string month_name;
    myfile >> month_name;

    return month_name;
}

int read_num_days() {
    int num_day;
    myfile >> num_day;

    return num_day;

}

int print_month(string month_name, int num_day, int start_date) {
    cout << setw(20) << month_name;
    cout << "\nSun: Mon: Tue: Wed: Thu: Fri: Sat: \n";
    string space = "";

    // int first_day = 1;

    // cout << no_of_days;

    if (start_date > 0) {

        if (start_date == 1) {
            space = "               ";
            }
        if (start_date == 2) {
            space = "                       ";
            }
        if (start_date == 3) {
            space = "                               ";
            }
        if (start_date == 4) {
            space = "                                       ";
            }
        if (start_date == 5) {
            space = "                                               ";
            }
        if (start_date == 6) {
            space = "                                                       ";
            }   
        cout << space;
    }
    for (int x = 1; x <= num_day; ++x) {
        if (x < 10) {
            cout << " " << x << "   ";
            }
        if (x > 9) {
            cout << " " << x << "  ";
            }
        if (start_date == 6) {
            start_date = -1;
            cout << "\n";
            }
        ++start_date;
    }
    cout << "\n" << endl;
    return start_date;
}



int main() {
    
    myfile.open("lab-6infile.txt"); // open infile
    
    int year = get_year();
    int start_date = get_starting_day();
    print_heading(year);

    for (int x = 1; x < 13; x++) {
        string month_name = read_month_name();
        int num_day = read_num_days();
        start_date = print_month(month_name, num_day, start_date);
    }

    myfile.close();  
    return 0;
}


