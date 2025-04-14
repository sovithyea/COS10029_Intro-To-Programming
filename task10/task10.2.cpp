#include <iostream>
using namespace std;

void swap_numbers(int *p1, int *p2)
{
    int temp;

    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{
    int x = 10;
    int y = 20;
    // You must figure out how to call the function correctly!
    swap_numbers(&x, &y);
    // Should print out x: 20, y: 10
    cout <<"x: "<< x <<", y: " << y << endl;
}