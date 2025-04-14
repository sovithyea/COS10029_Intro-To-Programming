#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum Difficulty
{
    Normal,
    Hard,
    Insane
};

struct targetAnimal
{
    string name;
    int hit_id, value;
    Difficulty kind;
};

void menu()
{
    cout<<"\nEnter your choice\n"
        <<"1. Add target_animal\n"
        <<"2. Print all target animals\n"
        <<"3. Print the highest value for a kind\n"
        <<"4. Quit\n";
}

Difficulty readDifficulty()
{
    int selection;

    cout<<"Enter difficulty kind 0->Normal, 1->Hard, 2->Insane: ";
    cin>>selection;
    Difficulty temp = static_cast<Difficulty>(selection);
    return temp;
}

targetAnimal readTargetAnimal()
{
    targetAnimal temp;
    cout<<"Enter target animal: ";
    cin>>temp.name;
    cout<<"Enter animal ID: ";
    cin>>temp.hit_id;
    temp.kind = readDifficulty();
    cout<<"Enter the value of the animal: ";
    cin>>temp.value;
    while(temp.value < 0)
    {
        cout<<"Not a valid value, re-enter the correct value: ";
        cin>>temp.value;
    }

    return temp;
}

void addTargetAnimal(vector <targetAnimal> &animals)
{
    targetAnimal animal;
    animal = readTargetAnimal();
    animals.push_back(animal);
}

void printTargetAnimal(targetAnimal temp)
{
    switch(temp.kind)
    {
        case Normal:
            cout<<"Normal: ";
            break;
        case Hard:
            cout<<"Hard: ";
        case Insane: 
            cout<<"Insane: ";
    }
    cout<<temp.name<<" ("<<temp.hit_id<<") "<<temp.value;
    if(temp.value < 1000)
        cout<<" Small Animal\n";
    else cout<<" Large Animal\n";
}

void mostValuebleTarget(vector <targetAnimal> &animals)
{
    Difficulty diff;
    diff = readDifficulty();
    int max = 0; 
    int index = 0;
    int i;
    for(int i=0; i<animals.size(); i++)
    {
        if(animals[i].kind == diff and animals[i].value > max)
        {
            max = animals[i].value;
            index = i;
        }
    }
    cout<<"The details of the animal with the largest price for the kind "<<diff<<" is \n";
    printTargetAnimal(animals[i]);
}

int main()
{
    vector <targetAnimal> animals;
    int choice, i;
    do{
        menu();
        cin>>choice;
        switch(choice)
        {
            case 1:
                addTargetAnimal(animals);
                break;
            case 2:
                for(int i=0; i<animals.size(); i++)
                {
                    printTargetAnimal(animals[i]);
                }
                break;
            case 3:
                mostValuebleTarget(animals);
                break;
            case 4:
                cout<<"Bye bye"<<endl;
                break;
            default: 
                cout<<"Invalid choice."<<endl;

        }

    }while(choice != 4);
}