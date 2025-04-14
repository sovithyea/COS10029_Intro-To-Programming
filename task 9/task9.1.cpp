#include <iostream>
#include <fstream>
#define SIZE 10    // Define the maximum number of employees

using namespace std;

// Structure to represent an employee
struct employee 
{
    string name;     // Name of the employee
    int emp_id;      // Employee ID
    float salary;    // Salary of the employee
};

// Function to read a single employee's data from the file
employee read_employee(ifstream &InFile)
{
    employee temp;
    InFile >> temp.name >> temp.emp_id >> temp.salary;
    return temp;
}

// Function to read all employees' data from the file and store in an array
void read_all_employee(ifstream &InFile, employee emp_array[], int size) 
{
    for (int i = 0; i < size; i++) {
        emp_array[i] = read_employee(InFile);
    }
}

// Function to print details of a single employee
void print_employee(const employee &emp) 
{
    // Print employee details
    cout << emp.name << " (" << emp.emp_id << "): " << emp.salary;
    
    // Determine employee level based on salary
    if (emp.salary < 4000) 
    {
        cout << " Level A\n";
    } else {
        cout << " Level B\n";
    }
}

// Function to print details of all employees
void print_all_employee(const employee emp_array[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        print_employee(emp_array[i]); // Print each employee's details
    }
}

// Function to calculate the total salary of all employees
float employee_total_salary(const employee emp_array[], int size) 
{
    float total = 0.0;
    
    // Accumulate total salary
    for (int i = 0; i < size; i++) 
    {
        total += emp_array[i].salary;
    }

    return total;
}

// Search for the largest index out of all employees
int search_largest_salary_index(const employee emp_array[], int size)
{
    int largestIndex = 0;

    for (int i = 1; i < size; i++) // Start from 1 because index 0 is initial largest
    {
        if (emp_array[i].salary > emp_array[largestIndex].salary)
        {
            largestIndex = i; // Update largestIndex if current salary is higher
        }
    }

    return largestIndex;
}

// Search for an employee by name and return their index
int search_an_employee_salary(const employee emp_array[], int size, const string &name)
{
    for (int i = 0; i < size; i++)
    {
        if (emp_array[i].name == name)
        {
            return i;
        }
    }

    return -1; // Employee not found
}

int main() {
    employee emp_array[SIZE]; // Array to hold employee data
    ifstream InFile;          // Input file stream for reading employee data
    string str;
    int i;

    InFile.open("employees.txt"); // Open the file containing employee data
    
    // Check if the file was opened successfully
    if (InFile.fail()) 
    {
        cout << "Error opening file\n";
        return 1; // Exit with an error code
    }

    // Read all employee data from the file into the array
    read_all_employee(InFile, emp_array, SIZE);
    
    // Close the file after reading
    InFile.close();

    // Print the details of all employees
    cout << "Employee details are:\n";
    print_all_employee(emp_array, SIZE);

    // Print out the total salaries of the employees
    cout << "Total salary of all employees is: " << employee_total_salary(emp_array, SIZE) << endl;

    // Print the employee with the largest salary
    cout << "Employee with the largest salary is: ";
    i = search_largest_salary_index(emp_array, SIZE);
    print_employee(emp_array[i]);

    // Search for an employee by name and print their salary
    cout << "Enter employee name for the search: ";
    cin >> str;
    
    i = search_an_employee_salary(emp_array, SIZE, str);
    
    if (i != -1)
        cout << "The salary of " << str << " is " << emp_array[i].salary << endl;
    else
        cout << "There is no such employee in the database\n";

    // Print employee details in reverse order
    cout << "Employee details in reverse order are:\n";
    for (int i = SIZE - 1; i >= 0; i--)
    {
        print_employee(emp_array[i]);
    }

    return 0;
}
