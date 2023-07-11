#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_CUSTOMERS = 5;

struct Customer {
    int accountNumber;
    string firstName;
    string lastName;
    double balance;
};

void writeCustomerFile() {
    ofstream outFile("customers.txt");
    if (!outFile) {
        cerr << "Error: could not open file" << endl;
        return;
    }

    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        Customer customer;

        customer.accountNumber = 1000 + i;
        cout << "Enter first name for account " << customer.accountNumber << ": ";
        cin >> customer.firstName;
        cout << "Enter last name for account " << customer.accountNumber << ": ";
        cin >> customer.lastName;
        cout << "Enter balance for account " << customer.accountNumber << ": ";
        cin >> customer.balance;

        outFile << customer.accountNumber << " "
                << customer.firstName << " "
                << customer.lastName << " "
                << customer.balance << endl;
    }

    outFile.close();
}

void readCustomerFile(Customer* customers) {
    ifstream inFile("customers.txt");
    if (!inFile) {
        cerr << "Error: could not open file" << endl;
        return;
    }

    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        inFile >> customers[i].accountNumber
               >> customers[i].firstName
               >> customers[i].lastName
               >> customers[i].balance;
    }

    inFile.close();
}

int findCustomer(Customer* customers, int accountNumber) {
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        if (customers[i].accountNumber == accountNumber) {
            return i;
        }
    }

    return -1;
}

int main() {
    Customer customers[MAX_CUSTOMERS];

    writeCustomerFile();
    readCustomerFile(customers);

    int accountNumber;
    cout << "Enter account number to search for: ";
    cin >> accountNumber;

    int index = findCustomer(customers, accountNumber);
    if (index == -1) {
        cout << "Account not found." << endl;
    } else {
        cout << "Name: " << customers[index].firstName
             << " " << customers[index].lastName
             << ", Balance: $" << customers[index].balance
             << endl;
    }

    return 0;
}
