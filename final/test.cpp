#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Person
{
    string Name;
    float Weight;
    float Height;
    double BMI;
};

int fill_persons(ifstream &inFile, Person p[])
{
    int i=0;
    inFile.open("BMI.txt");
    
    if(inFile.fail())
    {
        cout<<"File is not opened"<<endl;
    }

    while(!inFile.eof())
    {
        inFile>>p[i].Name;
        inFile>>p[i].Weight;
        inFile>>p[i].Height;
        inFile>>p[i].BMI;
        i++;
    }
    inFile.close();
    return i;
}

void print_each_person(Person temp)
{
    cout<<"\nName: "<<temp.Name<<endl;
    cout<<"Weight: "<<temp.Weight<<endl;
    cout<<"Height: "<<temp.Height<<endl;
    cout<<"BMI: "<<temp.BMI<<endl;
}

void print_persons(Person p[], int size)
{
    for(int i=0; i<size; i++)
    {
        print_each_person(p[i]);
    }
}

void calculate_BMI(Person p[], int size)
{    
    for(int i=0; i<size; i++)
    {
        p[i].BMI = (p[i].Weight/(p[i].Height*p[i].Height));
    }
}

int find_min_weight(Person p[], int size)
{
    int lowestIndex = 0;

    for(int i=0; i<size; i++)
    {
        if(p[i].Weight < p[lowestIndex].Weight)
        {
            lowestIndex = i;
        }
    }
    return lowestIndex;
}

void menu(Person p[], int size)
{
    int choice, i;

    do
    {
        cout<<"=============================================="<<endl;
        cout<<"Enter 1 to print the persons details"<<endl;
        cout<<"Enter 2 to calculate anf fill in the BMI values"<<endl;
        cout<<"Enter 3 to find the Person with the minimum weight"<<endl;
        cout<<"Enter -1 to exit the program"<<endl;
        cout<<"=============================================="<<endl;
        cin>>choice;

        if(choice == 1)
        {
            cout<<"Person Details: "<<endl;
            print_persons(p, size);
        }
        else if(choice == 2)
        {
            cout<<"BMI values have been calculated and filled"<<endl;
            calculate_BMI(p, size);
        }
        else if(choice == 3)
        {
            cout<<"Person with the minimum weight: "<<endl;
            i = find_min_weight(p, size);
            print_each_person(p[i]);
        }
        else if(choice == -1)
        {
            cout<<"Exiting the program."<<endl;
            break;
        }
        else 
        {
            cout<<"Invalid number."<<endl;
        }
    }while(-1); 
}

int main()
{
    Person p[5];
    int size;
    ifstream inFile;
    size = fill_persons(inFile, p);
    menu(p, size);
    
    return 0;
}