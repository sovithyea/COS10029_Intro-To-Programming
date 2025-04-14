#include <iostream>
#define max_size 20
using namespace std;

// function to calculate sum1
int findSum1(int array[], int size) 
{
    int sum1 = 0;
    
    cout << "Numbers for sum1 are ";
  
    for (int i = size - 2; i >= 0; i -= 2) {
        int doubled = array[i] * 2;  // double the value of the digit

        // if the result is a two-digit number, sum its digits
        if (doubled > 9) {
            doubled = (doubled / 10) + (doubled % 10);
        }

        sum1 = sum1 + doubled; 
        cout << array[i] << " "; 
    }

    cout << "\nSum1 is " << sum1 << endl;
    return sum1;  
}

// no doubling in sum2
int findSum2(int array[], int size) 
{
    int sum2 = 0;
    
    cout << "Numbers for sum2 are ";

    for (int i = size - 3; i >= 0; i -= 2) {
        sum2 = sum2 + array[i]; 
        cout << array[i] << " "; 
    }

    cout << "\nSum2 is " << sum2;
    return sum2;  
}

// function to calculate the checksum and validate the credit card
void validateCreditCard(int sum1, int sum2, int lastDigit) {
    int total = sum1 + sum2;
    int checksum = (total * 9) % 10;

    cout << "\nChecksum is " << checksum << endl;

    cout << "Last digit on credit card is " << lastDigit << endl;
    if (checksum == lastDigit) {
        cout << "Check sum " << checksum << " and the last digit " << lastDigit << " are the same: Valid credit card number." << endl;
    } else {
        cout << "Check sum " << checksum << " and the last digit " << lastDigit << " are not the same: Invalid credit card number." << endl;
    }
}

int main() 
{
    int array[max_size];    
    int size = 0;          
    int digit;              

    cout << "Enter a series of one-digit positive numbers (end with -1): " << endl;

    
    while (size < max_size) 
    {
        cin >> digit;  

        if (digit == -1) {
            break;  
        }

        // check if the input is a valid single-digit positive number
        if (digit >= 0 and digit <= 9) 
        {
            array[size++] = digit;  // store the digit in the array and increment the size
        } 
        else 
        {
            cout << "Please enter a valid one-digit positive number." << endl;
        }
    }

    // output the entered digits stored in the array
    cout << "\nCredit card number is: ";
    for (int i = 0; i < size; i++) 
    {
        cout << array[i];
    }
    cout << endl;

    // calculate and print sum1
    int sum1 = findSum1(array, size);

    // calculate and print sum2
    int sum2 = findSum2(array, size);

    // validate the credit card
    validateCreditCard(sum1, sum2, array[size - 1]);

    return 0;
}
