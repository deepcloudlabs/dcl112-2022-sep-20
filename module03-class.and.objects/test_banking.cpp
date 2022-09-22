#include <iostream>
#include "customer.h"
#include "account.h"
#include "savings_account.h"
#include "checking_account.h"

using banking::customer;
using banking::account;
using banking::SavingsAccount;
using banking::CheckingAccount;
using namespace std;

int main() {
    cout << "Creating the customer Jack Bauer." << endl;
    auto jack = new customer("jack", "bauer"); // pointer points the object at the heap

    jack->addAccount(new SavingsAccount("tr1", 1'000'000, 12));
    jack->addAccount(new CheckingAccount("tr2", 2'000'000, 5'000));
    jack->addAccount(new account("tr3", 3'000'000));

    // Print out the final account balance
    cout << "Customer ["
         << jack->getLastName()
         << ", "
         << jack->getFirstName()
         << "] has a balance of "
         << jack->getTotalBalance()
         << endl;

    jack->withdrawCost(800);

    // Print out the final account balance
    cout << endl
         << "Customer ["
         << jack->getLastName()
         << ", "
         << jack->getFirstName()
         << "] has a balance of "
         << jack->getTotalBalance()
         << endl;

    delete jack; // destroys the customer object! -> calls destructor
    return 0;
}