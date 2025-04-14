#include <iostream>


using namespace std;

double getProductPrice(int productCode) {
    switch (productCode) {
        case 1: return 3.25;
        case 2: return 1.75;
        case 3: return 7.85;
        case 4: return 0.99;
        case 5: return 0.35;
        default: return -1; // Invalid product code
    }
}

void printReceiptSummary(double totalCost, int totalProducts) {
    cout << "\nInvoice" << endl;
    cout << "Total number of Products: " << totalProducts << endl;
    cout << "Total Invoice Amount: $" << fixed << setprecision(2) << totalCost << endl;
}

int main() {
    int productCode, quantity;
    double totalCost = 0;
    int totalProducts = 0;

    while (true) {
        cout << "Product Code: ";
        cin >> productCode;

        if (productCode == -1) {
            break;
        }

        double price = getProductPrice(productCode);

        if (price == -1) {
            cout << "Error...Invalid Product Code, please enter the code again" << endl;
            continue;
        }

        cout << "Quantity: ";
        cin >> quantity;

        if (quantity <= 0) {
            cout << "Error...Invalid Quantity, please enter the quantity again" << endl;
            continue;
        }

        double productCost = price * quantity;
        totalCost += productCost;
        totalProducts += quantity;

        cout << "Total - $" << fixed << setprecision(2) << productCost << endl;
    }

    printReceiptSummary(totalCost, totalProducts);

    return 0;
}