/*==============================================================================
Zachary Hadjah                    April 4th 2018
Junior Year                       Data Structures/ Algorithm Analysis
 
 describeProgram() - 
  Gives th user incite into the program
 
 GetEmployeeNames(int &numEmployees) -
  Passes back through the  argument numEmployees, the number of employees for 
  the company and returns through its name a pointer to the dynamic array of 
  employee names that is created within the body of the function.
 
 GetSalaries(string* namePtr, int numEmployees, ofstream& toFile) -
   Takes in the pointer to the array of employee names and the number of employees 
   as arguments and returns through its name a pointer to the array of salaries.
   The body of the function prompts for the salary of each employee by name.
   Once the salaries have been obtained, the function reports to both the
   screen and the external text file, “results.txt”, the list of names of the 
   employees and their corresponding salaries in unsorted order and in tabular 
   format. The salaries are then sent to two digits of precision to the right of
   the decimal point. 
 
 sort(string *namePtr, double *salaryPtr, int numEmployees) -
  a function that takes in as arguments pointers to the array of names and the 
  array of salaries along with the number of employees and properly sorts the
  two arrays using a selection sort algorithm 
 
 displayResults(string *namePtr, double *salaryPtr, int numEmployees, ofstream 
 &toFile) - 
  Takes in through its arguments the pointer to the array of employee names, the
  pointer to the corresponding sorted list of salaries, and the number of employees, 
  and sends to both the screen and to the external file, “results.txt”, the list
  of names and salaries in ascending order of salaries in tabular format along 
  with the average salary, the lowest salary along with the name of the 
  corresponding employee, and the largest salary along with the name of the
  corresponding employee. All salaries and the average salary are two digits of
  precision to the right of the decimal point. 
 =============================================================================*/
#include<string> 
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <fstream>
using namespace std;

void describeProgram();
string* GetEmployeeNames(int& numEmployees) ;
double* GetSalaries(string* namePtr, int numEmployees, ofstream& toFile) ;
void sort(string* namePtr, double* salaryPtr, int numEmployees);
void displayResults(string* namePtr, double* salaryPtr, int numEmployees, ofstream& toFile);

int main(int argc, char** argv) 
{
    int employees = 0;
    ofstream toFile;
    double *salaryPtr;
    string *namePtr; 
    
    describeProgram();
    
    cout<<"Enter the number of Employees whose salaries you would like to keep "
          "track of: \n";
    cin >> employees;
    while(  (employees < 0) || (isdigit(employees))  )
    {
        cout << "Invalid input. \n";
        cin >> employees;
    }   
    
    namePtr = GetEmployeeNames(employees);
    salaryPtr = GetSalaries(namePtr, employees, toFile);
    sort(namePtr, salaryPtr, employees);
    displayResults(namePtr, salaryPtr, employees, toFile);
    system("PAUSE");
    return 0;
}

void describeProgram()
{
    cout << "This program prompts the user for how many employee salaries they "
            "want to keep track of.\n Next the user will enter the names, and then "
            "the salaries of the employees. The program will \n then display the "
            "employee names and salaries in a tabular format, aswell as the average"
            " of salaries.";
}

string* GetEmployeeNames(int &numEmployees) 
{    
    string* namePtr;
    namePtr = new string[numEmployees];   //creating the dynamic array
    cin.ignore();
    for (int i = 0; i < numEmployees; i++)
    {
        cout << "Enter the name of employee number "<< i+1 << ":";
        getline(cin, namePtr[i]);
    }
    return namePtr;
}

double* GetSalaries(string* namePtr, int numEmployees, ofstream& toFile) 
{
    const int width1 = 12;
    double* salaryPtr;
    
    salaryPtr = new double[numEmployees];  //creating the dynamic array
            
    for(int i =0; i<numEmployees; i++)
    {
        cout << "Enter the salary for employee number " << i+1 << ": \n";  
        cin >> salaryPtr[i];
        
        while(salaryPtr[i] < 0)
        {
            cout << "Invalid input, Enter numbers above zero: \n";
            cin >> salaryPtr[i];
        }
    }
    cout << "Here is the list of employee salaries unsorted: \n";
    cout << "Employee" << setw(width1) << "Salary \n";
    cout << "-------------------------------- \n";
    for(int j = 0; j<numEmployees; j++)
    {
        cout << namePtr[j] << setw(width1) << salaryPtr[j] << "\n";
    }

    toFile.open("result.txt",ios::app);
    toFile << "Here is the list of employee salaries unsorted: \n";
    toFile << "Employee" << setw(width1) << "Salary \n";
    toFile << "------------------------------- \n";
    for(int j = 0; j<numEmployees; j++)
    {
        toFile << namePtr[j] << setw(width1) << salaryPtr[j] << "\n";
    }
    toFile.close();
    
    return salaryPtr;
}

void sort(string *namePtr, double *salaryPtr, int numEmployees)
{
    int minIndex, start;
    double minValue;
    string minName;
    
    for (start = 0; start < (numEmployees - 1); start++) 
    {
        minIndex = start;
        minValue = salaryPtr[start];
        minName = namePtr[start];

        for (int index = start + 1; index < numEmployees; index++) 
        {
            if (salaryPtr[index] < minValue) 
            {
                minValue = salaryPtr[index];
                minName = namePtr[index];
                minIndex = index;
            }
        }

        salaryPtr[minIndex] = salaryPtr[start];
        namePtr[minIndex] = namePtr[start];
        salaryPtr[start] = minValue;
        namePtr[start] = minName;
        return;
    }
}

void displayResults(string *namePtr, double *salaryPtr, int numEmployees, ofstream &toFile)
{
    double sum, salaryAvg = 0;
    const int width1 = 12;  
    
    cout << "\n Below are the employee names and salaries in ascending order, "
            "and the average of the salaries:\n";
    cout << "\n Employee's Name" << setw(width1) << " Salary" << "\n";
    cout << "----------------------------------------------" << "\n";
    cout << setprecision(2) << fixed << showpoint;

    toFile.open("results.txt",ios::out);
    toFile << "\n Below are the employee names, salaries, and the average of the salaries: \n";
    toFile << " \n Employee's Name" << setw(width1) << " Salary" << "\n";
    toFile << "----------------------------------------------" << "\n";
    toFile << setprecision(2) << fixed << showpoint;
 
    for (int i = 0; i < numEmployees; i++)
    {
        cout << namePtr[i] << setw(width1) << salaryPtr[i] << "\n";
        
        toFile << namePtr[i] << setw(width1) << salaryPtr[i] << "\n";
    }
     
    //Calculating the average of the employees 
    for(int i = 0; i < numEmployees; i++)
    {
        sum += salaryPtr[i];
    }
    salaryAvg = sum / numEmployees;
    
    cout << " \n The average of the salaries is: " << salaryAvg << "\n";
    toFile << "\n The average of the salaries is: " << salaryAvg << "\n"; 
    toFile.close();        
}        