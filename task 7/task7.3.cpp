#include <iostream>
using namespace std;

struct person
{
    string name;
    int age;
};

void print_data(person temp)
{
    cout << "Name: " << temp.name << endl;
    cout << "Age: " << temp.age << endl; 
}
int main()
{
    struct person p;

    cout << "Enter a name: ";
    cin >> p.name;
    cout << "Enter an age: ";
    cin >> p.age;

    print_data(p);

    return 0;
}
