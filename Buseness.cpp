#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Get user input
    string name, phone, address;
    double price, discount;

    cout << " \t\t===== Enter Customer Details =====\t\t \n";
    cout << "Enter name\t\t: ";
    getline(cin, name);

    cout << "Enter phone number\t: ";
    getline(cin, phone);

    cout << "Enter address\t\t: ";
    getline(cin, address);

    cout << "Enter price\t\t: ";
    cin >> price;

    cout << "Enter discount\t\t: ";
    cin >> discount;
    cout << "\n";

    // Calculate price after discount
    double discountAmount = price * discount / 100;
    double totalPrice = price - discountAmount;

    // Print slip details
    cout << "\n=== Product Slip ===" << endl;
    cout << "Name\t\t\t\t: " << name << endl;
    cout << "Phone number\t\t\t: " << phone << endl;
    cout << "Address\t\t\t\t: " << address << endl;
    cout << "Price\t\t\t\t: " << price << endl;
    cout << "Discount\t\t\t: " << discount << "%" << endl;
    cout << "Price after discount\t\t: " << totalPrice << endl;

    // Save slip details to file
    ofstream outFile;
    outFile.open("slips.txt", ios::app); // "ios::app" --> Giving permission to save text with another customer details
    if (outFile.is_open()) {
        outFile << " \n\t\t===== Enter Customer Details =====\t\t \n" << "\n\tName\t\t\t\t\t: " << name << "\n\tPhone Number\t\t\t: " << phone <<
             "\n\tAddress\t\t\t\t\t: " << address << "\n\tProduct Price\t\t\t: " << price << "-/" << "\n\tDiscount Rate\t\t\t: " <<  discount << "%" <<
             "\n\tPrice after discount\t: " << totalPrice << "-/" << endl;
        outFile.close();
        cout << "\nSlip details saved to file." << endl;
    } else {
        cout << "\nError: Could not save slip details to file." << endl;
    }

    return 0;
}
