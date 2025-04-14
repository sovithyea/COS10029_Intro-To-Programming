#include <iostream>
using namespace std;

int main()
{
    double a, b , c;
    float ave;
    //students scores
    cout<<"Enter score for M1: ";
    cin>>a;
    cout<<"Enter score for M2: ";
    cin>>b;
    cout<<"Enter score of M3: ";
    cin>>c;
    ave = (a+b+c)/3.0;

    if (a>=60 and b>=60 && c>=60 and ave>=65)
    {
        cout<<"Passed"<<endl;
    }
    else
    {
        cout<<"Failed"<<endl;
    }
}