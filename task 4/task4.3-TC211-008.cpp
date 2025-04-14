#include <iostream>
using namespace std;

int main()
{
    int a, b , c;
    float average;

    //students scores
    cout<<"Enter score for M1: ";
    cin>>a;
    cout<<"Enter score for M2: ";
    cin>>b;
    cout<<"Enter score of M3: ";
    cin>>c;
    average=a+b+c/3;

    if (a>=60)
    {
        cout<<"M1 Pass"<<endl;
    }
    else
    {
        cout<<"M1 Failed"<<endl;
    }
    if (b>=60)
    {
        cout<<"M2 Pass"<<endl;
    }
    else
    {
        cout<<"M2 Failed"<<endl;
    }
    if (c >=60)
    {
        cout<<"M3 Pass"<<endl;
    }
    else
    {
        cout<<"M3 Failed"<<endl;
    }
    cout<<"The students average is: "<<average<<endl;
}