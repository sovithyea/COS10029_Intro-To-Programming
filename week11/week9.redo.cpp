#include <iostream>
#include <fstream>
#include <string>
#define SIZE 10
using namespace std;

struct employee
{
    string name;
    int emp_id;
    float salary;   
};

employee read_employee(ifstream &inFile)
{
    employee temp;

    inFile>>temp.name>>temp.emp_id>>temp.salary;

    return temp;
}

void read_all_employee(ifstream &inFile, employee emp_array[], int size)
{
    for(int i=0; i<size; i++)
    {
        emp_array[i] = read_employee(inFile);
    }
}

void print_employee(employee temp)
{
    cout<<temp.name<<" ("<<temp.emp_id<<") "<<temp.salary;

    if(temp.salary < 4000)
        cout<<" Level A\n";
    else cout<<" Level B\n";
}

void print_all_employee(employee emp_array[], int size)
{
    for(int i=0; i<size; i++)
    {
        print_employee(emp_array[i]);
    }
}

float employee_total_salary(employee emp_array[], int size)
{
    float total = 0.0;

    for(int i=0; i<size; i++)
    {
        total = total + emp_array[i].salary;
    }
    return total;
}

int search_largest_salary_index(employee emp_array[], int size)
{
    int largestIndex = 0;

    for(int i=1; i<size; i++)
    {
        if(emp_array[i].salary > emp_array[largestIndex].salary)

        largestIndex = i;
    }
    return largestIndex;
}

int search_an_employee_salary(employee emp_array[], int size, string str)
{
    for(int i=0; i<size; i++)
    {
        if(emp_array[i].name == str)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    employee emp_array[SIZE];
    int i;
    ifstream inFile;
    string str;

    inFile.open("employees.txt");
    if(inFile.fail())
    {
        cout<<"File not opened"<<endl;
    }
    read_all_employee(inFile, emp_array, SIZE);
    cout<<"Employees details are: "<<endl;
    print_all_employee(emp_array, SIZE);
    cout<<"Total: "<<employee_total_salary(emp_array, SIZE)<<endl;
    cout<<"Employee with the largest salary is: ";
    i = search_largest_salary_index(emp_array, SIZE);
    print_employee(emp_array[i]);
    cout<<"— Enter employee name for the search--"<<endl;
    cin>>str;
    i = search_an_employee_salary(emp_array, SIZE, str);

    if(i != -1)
        cout<<"The salary of "<<str<<" is "<<emp_array[i].salary<<endl;
    else cout<<"Array does not contain an employee named "<<str<<endl;
    
    for(int i=SIZE-1; i >=0; i--)
    print_employee(emp_array[i]);

    return 0;
}