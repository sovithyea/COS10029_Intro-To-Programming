#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
    int count, id;
    float price, min, max, avg, total=0.0;

    ifstream inFile;

    inFile.open("price.dat.txt");
    inFile >> count;

    for(int i=0; i<count; i++)
    {
        inFile>>id>>price;
        if(i==0)
            max = min = price;
        if(price > max)
            max = price;
        if(price < min)
            min = price;
        total+=price;
    }

    avg = total / count;
    
    ofstream outFile;
    outFile.open("output.dat.txt");

    cout<<"Number of price readings: "<< count <<endl;
    cout<<"Maximum price: "<< max<<endl;
    cout<<"Minimum price: "<<min<<endl;
    cout<<"Average price: "<<avg<<endl;

    inFile.close();

    return 0;
}