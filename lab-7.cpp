#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

ifstream myfile; 

// C = current patient
// N = new patient
// F = referral
// R = returning patient

void evaluate_cholesterol(int, int, string&, string&);
    // int HDL_Read                 (patient's high-density lipoprotein level)
    // string& HDL_Eval             interpretation   
    // int LDL_Read                 (patient's low-density lipoprotein level)
    // string& LDL_Eval             interpretation
void evaluate_blood_pressure(int, int, string&, string&);
    // int SYS_Read                 (patient's systolic blood pressure values)
    // string& sys_eval             interpretation
    // int DIA_Read                 (patient's diastolic blood pressure value)
    // string diast_eval            interpretation


int main (int argc, const char*argv[]) {
    
    ifstream myfile;
    myfile.open("infile-7.txt"); // opens file of patient info

    // variables for counter to go through patient data
    int count;
    float ratio; 
    count = 0;
    int x;
    x = 0; 

    string name;
    char status;
    int doc_visit;
    int HDL_Read, LDL_Read, SYS_Read, DIA_Read;
    string HDL_Eval, LDL_Eval, sys_eval, diast_eval; // delcaring variables above for blood pressure 
    int patient_record_num;                          // and cholesterol evaluations
    
    cout << "Enter the number of patient records: "; // user prompt to enter num of patient records
    cin >> patient_record_num; // user input
    cout << endl;

    for (count = 0; count < patient_record_num; count++) // loop to iterate through each patient's data 
    {
        myfile >> name >> status >> doc_visit; // reads patient's name, status, and doc visit in infile
        cout << "Current Patient's Name: " << name << endl << endl; // outputs the patient's name

        for (x = 1; x <= doc_visit; x++) // this loop reads patient's readings/results
        {
            cout << "DATA SET " << x << endl;
            myfile >> HDL_Read >> LDL_Read >> SYS_Read >> DIA_Read; // reads infile info 
            ratio = (float(HDL_Read)/float(LDL_Read)); // (hdl/ldl) = ratio interpretation

            // display for patient's cholesterol profile
            cout << "Cholesterol Profile:" << endl;
            evaluate_cholesterol(HDL_Read, LDL_Read, HDL_Eval, LDL_Eval);
            cout << " HDL: " << HDL_Read << " LDL: " << LDL_Read << endl;
            cout << " Ratio: " << fixed << showpoint << setprecision(4) << ratio << endl; // round ratio to 4 decimal places
            cout << " HDL is " << HDL_Eval << endl;
            cout << " LDL is " << LDL_Eval << endl;
            cout << " Blood Pressure Profile: " << endl;

            // display for patient's blood pressure profile
            evaluate_blood_pressure(SYS_Read, DIA_Read, sys_eval, diast_eval);
            cout << " Systolic: " << SYS_Read << " Diastolic: " << DIA_Read << endl;
            cout << " Systolic reading is " << sys_eval << endl;
            cout << " Diastolic reading is " << diast_eval << endl;
            cout << endl;
        }
        // loop will call the two void functions above

       
    }
    myfile.close(); // close the file
    return 0;
}

void evaluate_cholesterol(int HDL_Read, int LDL_Read, string& HDL_Eval, string& LDL_Eval) 
{
// these values are according to the chart given
    if (HDL_Read <40)
        HDL_Eval = "Too Low";
    else
    if (HDL_Read < 60 )
        HDL_Eval = "Is Okay";
    else
        HDL_Eval = "Excellent";

    if (LDL_Read <100)

        LDL_Eval = "Optimal";
    else
    if (LDL_Read < 130)
        LDL_Eval = "Near Optimal";
    else
    if (LDL_Read < 160)
        LDL_Eval = "Borderline High";
    else
    if (LDL_Read < 190)
        LDL_Eval = "High";
    else
        LDL_Eval = "Very High";

}
int SYS_Read;
int DIA_Read;
string sys_eval;
string diast_eval;

// nested if statements to evaluate blood pressure
void evaluate_blood_pressure(int SYS_Read, int DIA_Read, string& sys_eval, string& diast_eval) 
{
// these values are according to the chart given
  if (SYS_Read < 120) 
        sys_eval = "Optimal";
    else
    if (SYS_Read < 130 )
        sys_eval = "Normal";
    else
    if (SYS_Read < 140)
        sys_eval = "Normal High";
    else
    if (SYS_Read < 160)
        sys_eval = "Stage 1 Hypertension";
    else
    if (SYS_Read < 180)
        sys_eval = "Stage 2 Hypertension";
    else
        sys_eval = "Stage 3 Hypertension";

    if (DIA_Read < 80)
        diast_eval = "Optimal";
    else
    if (DIA_Read < 85 )
        diast_eval = "Normal";
    else
    if (DIA_Read < 90)
        diast_eval = "Normal High";
    else
    if (DIA_Read < 100)
        diast_eval = "Stage 1 Hypertension";
    else
    if (DIA_Read < 110)
        diast_eval = "Stage 2 Hypertension";
    else
        diast_eval = "Stage 3 Hypertension";
}

// --- OUTPUT CODE ---:

// Enter the number of patient records: 3

// Current Patient's Name: Jones

// DATA SET 1
// Cholesterol Profile:
//  HDL: 60 LDL: 124
//  Ratio: 0.4839
//  HDL is Excellent
//  LDL is Near Optimal
//  Blood Pressure Profile:
//  Systolic: 130 Diastolic: 84
//  Systolic reading is Normal High
//  Diastolic reading is Normal

// DATA SET 2
// Cholesterol Profile:
//  HDL: 65 LDL: 121
//  Ratio: 0.5372
//  HDL is Excellent
//  LDL is Near Optimal
//  Blood Pressure Profile:
//  Systolic: 133 Diastolic: 80
//  Systolic reading is Normal High
//  Diastolic reading is Normal

// DATA SET 3
// Cholesterol Profile:
//  HDL: 70 LDL: 120
//  Ratio: 0.5833
//  HDL is Excellent
//  LDL is Near Optimal
//  Blood Pressure Profile:
//  Systolic: 130 Diastolic: 81
//  Systolic reading is Normal High
//  Diastolic reading is Normal

// Current Patient's Name: Smith

// DATA SET 1
// Cholesterol Profile:
//  HDL: 30 LDL: 195
//  Ratio: 0.1538
//  HDL is Too low
//  LDL is Very High
//  Blood Pressure Profile:
//  Systolic: 120 Diastolic: 85
//  Systolic reading is Normal
//  Diastolic reading is Normal High

// Current Patient's Name: Williams

// DATA SET 1
// Cholesterol Profile:
//  HDL: 45 LDL: 185
//  Ratio: 0.2432
//  HDL is Is Okay
//  LDL is High
//  Blood Pressure Profile:
//  Systolic: 190 Diastolic: 112
//  Systolic reading is Stage 3 Hypertension
//  Diastolic reading is Stage 3 Hypertension

// DATA SET 2
// Cholesterol Profile:
//  HDL: 50 LDL: 181
//  Ratio: 0.2762
//  HDL is Is Okay
//  LDL is High
//  Blood Pressure Profile:
//  Systolic: 193 Diastolic: 115
//  Systolic reading is Stage 3 Hypertension
//  Diastolic reading is Stage 3 Hypertension
