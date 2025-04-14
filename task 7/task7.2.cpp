#include <iostream>
using namespace std;
 
struct student
{
    string name;
    int roll; 
    float marks;
};

int main()
{
    struct student s[5];

    for(int i = 0; i < 5; i++)
    {
        cout << "Enter the students name: ";
        cin >> s[i].name;
        cout << "Enter the students roll: ";
        cin >> s[i].roll;
        cout << "Enter the students mark: ";
        cin >> s[i].marks;
    }

    for(int i = 0; i < 5; i++)
    {
        cout << "Students name: " << s[i].name << endl;
        cout << "Students roll: " << s[i].roll << endl;
        cout << "Students mark: " << s[i].marks << endl;
    }
    return 0;
}

