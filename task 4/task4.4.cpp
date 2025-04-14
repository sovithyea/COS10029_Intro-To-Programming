#include <iostream>
using namespace std;

int main()
{
    int score;
    
    cout<<"Enter a score: ";
    cin>>score;

    switch(score)
    {
        case 80 ... 100:
             cout<<"HD"<<endl;
            break;
        case 70 ... 79:
            cout<<"D"<<endl;
            break;
        case 60 ... 69:
            cout<<"C"<<endl;
            break;
        case 50 ... 59:
            cout<<"P"<<endl;
            break;
        case 0 ... 49:
            cout<<"F"<<endl;
            break;
    }
}