#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    int mark1, mark2;
    int total_mark;
    float average;
    string grade;

    //asking for students name
    cout<<"Enter name of the student: ";
    cin>>name;

    //asking for mark 1 and 2
    cout<<"Please enter student's mark1: ";
    cin>>mark1;
    cout<<"Please enter student's mark2: ";
    cin>>mark2;
    
    //asking for students grade
    cout<<"What is the grade? ";
    cin>>grade;
    
    //finding average
    total_mark = mark1 + mark2;
    average = total_mark/2.0;

    //output
    cout<< "The student " <<name<< " has an average score of " <<average<< " and got a " <<grade<< " grade " <<endl;
    return 0;
}

