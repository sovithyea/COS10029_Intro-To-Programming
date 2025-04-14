#include <iostream>
#include <fstream>
using namespace std;

struct student
{
    string name;
    int marks[4];
};

int main()
{
    int i=0, j=0, sum=0;
    float avg=0.0;

    student s[5];
    ifstream inFile;
    ofstream outFile;

    inFile.open("grades.txt");
    
    if(inFile.fail())
    {
        cout<<"The file was not succcesfully open.";
        exit(1);
    }
    
    while(not inFile.eof())
    {
        inFile>>s[i].name;
        
        for(j=0; j<4; j++)
        {
            inFile>>s[i].marks[j];
        
        }
        i++;
    }
    
    inFile.close();
    outFile.open("gradesoutput.txt");
    for(int i=0;i<5;i++)
    {
        outFile<<s[i].name<<endl;

        for(j=0;j<4;j++)
        {
            outFile<<s[i].marks[j]<<endl;
            sum+=s[i].marks[j];
        }
    avg=sum/4.0;
    outFile<<s[i].name<<" has an average score of "<<avg<<endl;
    }
}