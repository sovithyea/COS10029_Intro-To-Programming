#include <iostream>
using namespace std;

//declaring variables

double calculate_cost(int product, int quantity)
{
    switch(product) //for different scenarios (different product codes)
    {
        case 1: 
            return 3.25 * quantity;
        case 2:
            return 1.75 * quantity;
        case 3:
            return 7.85 * quantity;
        case 4:
            return 0.35 * quantity;
        default:
            return 0.0;
    }
}

void display_invoice(double total_cost, int total_quantity) //final result
{
    cout << "Invoice" << endl;
    cout << "Total number of Products: " << total_quantity << endl;
    cout << "Total Invoice Amount: $" << total_cost << endl;
}


int main() 
{
    int product;
    int quantity;
    double total_cost = 0.0;
    int total_quantity = 0;

    while (true)
    {
        cout << "Product Code: "; //asking for product code
        cin >> product;

        if (product == -1) {
            break; 
        }

        if (product < 1 or product > 4) 
        {
            cout << "Error... Invalid Product Code, please enter the code again" << endl; //invalid product code
            continue;
        }

        cout << "Quantity: "; //asking for quantity of products
        cin >> quantity;

        if (quantity <= 0) 
        {
            cout << "Error... Invalid Quantity, please enter the quantity again" << endl; //invalid quantity
            continue;
        }
        
        double cost = calculate_cost(product, quantity); //calculating overall cost and overall quantity
        total_cost += cost;
        total_quantity += quantity;

        cout << "Total - $" << cost << endl;
    }

    display_invoice(total_cost, total_quantity); //displaying final invoice

    return 0;
}

