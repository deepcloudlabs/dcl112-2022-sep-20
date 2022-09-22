#include <iostream>
#include "customer.h"
#include "account.h"

using banking::customer;
using banking::account;
using namespace std;

int main() {
    customer *cust; // pointer is at the stack
    account acc1("tr1", 500.0); // stack object

    // Create an account that can has a 500.00 balance.
    cout << endl << "Creating the customer Jane Smith.";
    cust = new customer("Jane", "Smith", "tr1"); // pointer points the object at the heap
    cout << endl << "Creating her account with a 500.00 balance.";

    cust->setCustomerAccount(acc1);
    acc1 = cust->getCustomerAccount();

    cout << endl << "Withdraw 150.00";
    acc1.withdraw(150.00);

    cout << endl << "Deposit 22.50";
    acc1.deposit(22.50);

    cout << endl << "Withdraw 47.62";
    acc1.withdraw(47.62);

    // Print out the final account balance
    cout << endl
         << "Customer ["
         << cust->getLastName()
         << ", "
         << cust->getFirstName()
         << "] has a balance of "
         << acc1.getBalance()
         << endl;
    delete cust; // destroys the customer object! -> calls destructor
    return 0;
}