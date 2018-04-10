/*==============================================================================
Zachary Hadjah                    April 4th 2018
Junior Year                       Data Structures/ Algorithm Analysis


 =============================================================================*/
#include<string> 
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <fstream>
using namespace std;

string* namePtr;
double* salaryPtr;
ofstream toFile;

//function declarations
void describeProgram();
string* GetEmployeeNames(int& numEmployees) ;
double* GetSalaries(string* namePtr, int numEmployees, ofstream& outs) ;
void sort(string* namePtr, double* salaryPtr, int numEmployees);
void displayResults(string* namePtr, double* salaryPtr, int numEmployees, ofstream& outs);

int main(int argc, char** argv) 
{
    int employees = 0;
    
    describeProgram();
    
    cout<<"Enter the number of Employees whose salaries you would like to keep "
          "track of: \n";
    cin >> employees;
    
    GetEmployeeNames(employees);
    return 0;
}

void describeProgram()
{
    
}

string* GetEmployeeNames(int& numEmployees) 
{
    cout << "Enter the number of employees: \n";
    cin << numEmployees;
    
    while(numEmployees < 0)
    {
        cout << "Invalid input, number less than zero. \n";
        cin >> numEmployees;
    }
    
    namePtr = new string[numEmployees];   //creating the dynamic array
    
    for (int i = 0; i < numEmployees; i++)
    {
        cout << "Enter the name of the employee";
        cin >> 
    }
    
}

double* GetSalaries(string* namePtr, int numEmployees, ofstream& outs) 
{
    for(int i =0; i<numEmployees; i++)
    {
        
    }
}

void sort(string* namePtr, double* salaryPtr, int numEmployees)
{
    
}

void displayResults(string* namePtr, double* salaryPtr, int numEmployees, ofstream& outs)
{
    toFile.open("results.txt",ios::out);
    
    toFile.close();
            
}
        