#include <iostream>
using namespace std;

// Function prototypes
void performAddition();
void performSubtraction();
void performMultiplication();
void performDivision();

int main() {
    int choice;

    do {
        // Display the menu
        cout << "Enter your choice (1-5):" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        // Perform the chosen operation
        switch (choice) {
            case 1:
                performAddition();
                break;
            case 2:
                performSubtraction();
                break;
            case 3:
                performMultiplication();
                break;
            case 4:
                performDivision();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
                break;
        }

    } while (choice != 5);

    return 0;
}

// Function to perform addition
void performAddition() {
    double num1, num2;
    cout << "Enter two numbers for addition: ";
    cin >> num1 >> num2;
    cout << "Result: " << num1 + num2 << endl;
}

// Function to perform subtraction
void performSubtraction() {
    double num1, num2;
    cout << "Enter two numbers for subtraction: ";
    cin >> num1 >> num2;
    cout << "Result: " << num1 - num2 << endl;
}

// Function to perform multiplication
void performMultiplication() {
    double num1, num2;
    cout << "Enter two numbers for multiplication: ";
    cin >> num1 >> num2;
    cout << "Result: " << num1 * num2 << endl;
}

// Function to perform division
void performDivision() {
    double num1, num2;
    cout << "Enter two numbers for division: ";
    cin >> num1 >> num2;
    if (num2 != 0) {
        cout << "Result: " << num1 / num2 << endl;
    } else {
        cout << "Error: Division by zero is not allowed." << endl;
    }
}
