#include <iostream>
using namespace std;

void reorder(int *a,int *b,int *c)
{
    int temp;

    if (*a > *b) 
    {
        temp = *a;
        *a = *b;
        *b = temp;
    }
    
    if (*b > *c) 
    {
        temp = *b;
        *b = *c;
        *c = temp;
    }
    
    if (*a > *b) 
    {
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main()
{
    int a, b ,c;
    
    cout << "Enter a value for A: ";
    cin >> a;
    cout << "\nEnter a value for B: ";
    cin >> b;
    cout << "\nEnter a value for C: ";
    cin >> c;

    reorder(&a, &b, &c);
    cout <<"a: "<<a<<", b: "<<b<<", c: "<<c;
}
