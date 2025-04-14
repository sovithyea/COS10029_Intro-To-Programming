#include <iostream>
using namespace std;
#define SIZE 10

int total_array(int data[], int size)
{
    int total=0, i;
    
    for(i=0; i<size; i++)
    {
        total = total + data[i];
    }
    return total;
}
bool check_total(int total)
{
    if(total>100)
        return true;
    else
        return false;
}
int negative_count(int data[], int size)
{
    int neg=0, i;
    
    for(i=0; i<size; i++)
    {
        if(data[i]<0)
        {
            neg++;
        }
    }
    return neg;
}
int main()
{
    int data_array[SIZE], i, key, total, neg;
    cout<<"Enter values in the array:\n";
    
    for(i=0; i<SIZE; i++)
    {
        cin >> data_array[i];
    }
    total = total_array(data_array, SIZE);
    cout << "The total of the array is "<< total <<endl;
    
    if (check_total(total))
    {
        cout << "The total is greater than 100\n";
    }
    
    else
    {
        cout << "The total is less than 100\n";
    }
    neg = negative_count(data_array, SIZE);
    cout << "The array contains " << neg << " negative numbers" << endl;
    
    return 0;
}