#include <iostream>
#include <memory>
#include "customer.h"
#include "account.h"
#include "savings_account.h"
#include "checking_account.h"
#include "standard_account.h"

using banking::Customer;
using banking::Account;
using banking::SavingsAccount;
using banking::CheckingAccount;
using banking::StandardAccount;
using namespace std;

int main() {
    cout << "Creating the Customer Jack Bauer." << endl;
    auto jack = new Customer("11111111110", "jack", "bauer"); // pointer points the object at the heap

    jack->addAccount(SavingsAccount("tr1", 1'000'000, 12));
    jack->addAccount(CheckingAccount("tr2", 2'000'000, 5'000));
    jack->addAccount(StandardAccount("tr3", 3'000'000));

    // Print out the final Account balance
    cout << "Customer ["
         << jack->getLastName()
         << ", "
         << jack->getFirstName()
         << "] has a balance of "
         << jack->getTotalBalance()
         << endl;

    jack->withdrawCost(800);

    // Print out the final Account balance
    cout << endl
         << "Customer ["
         << jack->getLastName()
         << ", "
         << jack->getFirstName()
         << "] has a balance of "
         << jack->getTotalBalance()
         << endl;
    cout << jack->groupByAccountType().begin()->first << endl;
    cout << jack->groupByAccountType().begin()->second << endl;
    delete jack; // destroys the Customer object! -> calls destructor
    return 0;
}