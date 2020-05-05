#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
 
float compute_gross_pay(int, float, char); //function prototypes
float compute_taxes(float);
float compute_net_pay(float, float);
void print_pay_check(string, string, string, string, string, string, string, string, int, int, float, float, float);
float compute_federal_tax(float);
float compute_state_tax(float);
float compute_city_tax(float);
 
int main()
{
  string dummy; //declare variables
  char parttime_fulltime; 
  float payRate;
  float grossPay;
  float netPay;
  float totalTax;
  const string date = "02/16/2016";
  string last_name, first_name, street_address, street_name, street_type, city, state;
  int zip, deductions, employee_id, address_num;
  ifstream myfile;

  myfile.open("lab5text.txt"); // open infile;
  
  for (int i = 1; i <= 6; i++)
  {
      myfile >> last_name >> first_name >> deductions >> employee_id >> address_num >> street_name >> street_type >> city >> state >> zip >> payRate >> parttime_fulltime; // get employee information
      float grossPay = compute_gross_pay(deductions, payRate, parttime_fulltime);
      float taxes = compute_taxes(grossPay);
      float netPay = compute_net_pay(grossPay, totalTax);
      print_pay_check(last_name, first_name, street_address, street_name, street_type, date, city, state, zip, address_num, grossPay, totalTax, netPay);
  }
//   myfile >> last_name >> first_name >> deductions >> employee_id >> address_num >> street_name >> street_type >> city >> state >> zip >> payRate >> parttime_fulltime; // get employee information
  
  myfile.close(); // close the file
  compute_gross_pay(deductions, payRate, parttime_fulltime);
  return 0; // return 0 if all works
}
//HERE IS WHERE YOU WRITE THE 7 FUNCTIONS

float compute_gross_pay(int deductions, float payRate, char parttime_fulltime) {
    // let gross pay = 40 times the hourly rate of each employee
    if (parttime_fulltime == 'F')
        return 40 * payRate;
    else 
        return (40 * payRate) + (deductions * 10.50);
}

float compute_federal_tax(float grossPay) {
    float federal_tax;
    float use_fed_tax;

    if (grossPay <= 200)
        use_fed_tax = (grossPay * 0.15);
    
    else if (grossPay <= 500)
        use_fed_tax =  .15 * 200 + (grossPay - 200) * 0.25;

    else if (grossPay > 500) 
        use_fed_tax = .15 * 200 + (300) * 0.25 + (grossPay - 500) * 0.35;
    
    cout << use_fed_tax << endl;
    return 0;
}

float compute_state_tax(float federal_tax) {
    float state_tax;

    if (federal_tax < 80) {
        state_tax = 0; 
    }
        
    else {
        state_tax = federal_tax * 0.10;
    }
    
    return state_tax;
}

float compute_city_tax(float state_tax) {
    float city_tax = 0;
    if (state_tax <= 50)
        city_tax = 0;
    else
        city_tax = state_tax * 0.08;

    return city_tax;
}
float compute_net_pay(float grossPay, float totalTax) {
    return grossPay - totalTax;
}
float compute_taxes(float grossPay) {
    float fed_tax = compute_federal_tax(grossPay);
    float sta_tax = compute_state_tax(fed_tax);
    float cit_tax = compute_city_tax(sta_tax);

    float totalTax = fed_tax + sta_tax + cit_tax;
    return totalTax;
}

void print_pay_check(string last_name, string first_name, string street_address, string street_name, string street_type, string date, string city, string state, int zip, int address_num, float grossPay, float totalTax, float netPay){
    cout << "ABC Flowers" << endl;
    cout << "123 Georgia Ave" << "                          "  <<  date  << endl;
    cout << "Washington, D 20059" << endl;
    cout << "                           " << endl;
    cout << "Payable to: " << last_name << " " << first_name << "              " << "Pay this amount: $" << netPay << endl;
    cout << "            " << address_num << street_address << " " << street_name << " " << street_type << endl;
    cout << "            " << city << " " << state << " " << zip << endl; 
    cout << "Gross Pay: $" << grossPay << endl;
    cout << "Total Taxes: $" << totalTax << endl;
    cout << "                           " << endl;

}