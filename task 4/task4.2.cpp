#include <iostream>
using namespace std;

int main()
{
    int a, b;

    cout<<"Enter a variable for a: "<<endl;
    cin>>a;

    cout<<"Enter a variable for b: "<<endl;
    cin>>b;

    if (a>b)
    {
        cout<<"Variable A is larger than variable B "<<endl;
    }
    else if (b>a)
    {
        cout<<"Variable B is larger than variable A "<<endl;
    }
    else
    {
        cout<<" A and B are equal "<<endl;
    }
}