#include <iostream>
#include <fstream>
using namespace std;

struct s
{
    int data;
    float price[5];
};

int fill_array(ifstream &inFile, s sample[])
{
    int i = 0;
    inFile.open("sample2.txt");
    if(inFile.fail())
    {
        cout<<"file not opened"<<endl;
    }
    
    while(inFile>>sample[i].data)
        for(int j=0; j<sample[i].data; j++)
        {
            inFile>>sample[i].price[j];
        }
        i++;
    inFile.close();
    return i;
}

void display(s sample[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<sample[i].data<<endl;
        
        for(int j=0; j<sample[i].data; j++)
        {
            cout<<sample[i].price[j]<<endl;
        }
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