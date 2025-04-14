#include <iostream>
#include <fstream>
using namespace std;

struct s
{
    string name;
    int id;
    int price;
};

int fill_array(ifstream &inFile, s sample[])
{
    int i=0;
    inFile.open("sample1.txt");
    if(inFile.fail())
    {
        cout<<"File not opened"<<endl;
    }
    while(!inFile.eof())
    {
        inFile>>sample[i].name;
        inFile>>sample[i].id;
        inFile>>sample[i].price;
        i++;
    }

    inFile.close();
    return i;
}

void display(s sample[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<sample[i].name<<" ";
        cout<<sample[i].id<<" ";
        cout<<sample[i].price<<endl;
    }
}

int main()
{
    s sample[100];
    int size;
    ifstream inFile;
    
    size = fill_array(inFile, sample);
    display(sample, size);
    return 0;
}