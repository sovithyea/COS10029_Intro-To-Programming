#include <iostream>
using namespace std;

int cubeByValue(int n)
{
    return n * n * n;
}

void cubeByReference(int *nPtr)
{
    *nPtr = *nPtr * *nPtr * *nPtr;
}


int main()
{
    int num;

    cout << "Enter a value for num: ";
    cin >> num;

    int result = cubeByValue(num);
    cubeByReference(&num);
    cout << "cubeByValue answer is: " << result << endl;
    cout << "cubeByReference answer is: " << num << endl;
}