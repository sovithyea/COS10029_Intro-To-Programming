#include <iostream>
using namespace std;

#define SIZE1 3
#define SIZE2 2

struct employee
{
    string name;
    int emp_id;
    float salary;
};

employee read_employee()
{
    employee temp;
    cout <<"Enter employee name: ";
    cin >> temp.name;
    cout <<"Enter employee id: ";
    cin >> temp.emp_id;
    cout << "Enter salary: ";
    cin >> temp.salary;
    return temp;
}

void print_employee(employee emp)
{
    cout << emp.name <<" (" <<emp.emp_id << "): "<<emp.salary;
    if(emp.salary<4000)
        cout <<"Level A\n";
    else
        cout <<"Level B\n";
}

float employee_total_salary(employee array[], int size)
{
    float total = 0;
    for(int i=0; i<size; i++)
    {
        total += array[i].salary;
    }
    return total;
}

int employee_index_search(employee array[], int id, int size)
{
    for (int i=0; i<size; i++)
    {
        if(array[i].emp_id==id)
            return i;
    }
    return -1;
}

int main()
{
    employee test_array1[SIZE1];
    employee test_array2[SIZE2];
    int i;
    
    cout <<"---Enter array 1 Employee Data---\n";
    for(i=0; i<SIZE1; i++)
    {
        test_array1[i] = read_employee();
    }
    
    cout <<"---Enter array 2 Employee Data---\n";
    for(i=0; i<SIZE2; i++)
    {
        test_array2[i] = read_employee();
    }

    cout <<"---Test Array 1---\n";
    for(i=0; i<SIZE1; i++)
    {
        print_employee(test_array1[i]);
    }
    cout <<"The total salary of array 1 is: " <<employee_total_salary(test_array1, SIZE1)<<endl;
   
   
    cout <<"---Test Array 2---\n";
    for(i=0; i<SIZE2; i++)
    {
        print_employee(test_array2[i]);
    }
  
  cout <<"The total salary of array 2 is: " <<employee_total_salary(test_array2, SIZE2)<<endl;
  
  i = employee_index_search(test_array1, 123, SIZE1);

  if(i!=-1)
  {
    print_employee(test_array1[i]);
  }
  else
    {
        cout <<"Array 1 does not contain an employee with id 123\n";
    }
    return 0;
}
