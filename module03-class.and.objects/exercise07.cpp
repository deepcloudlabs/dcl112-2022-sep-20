#include "bank.h"
#include "customer.h"
#include "standard_account.h"
#include "savings_account.h"
#include "checking_account.h"
#include <iostream>

using banking::bank;
using banking::Customer;
using banking::StandardAccount;
using banking::SavingsAccount;
using banking::CheckingAccount;
using namespace std;

int main() {
    auto garantiBbva = new bank(); // heap object
    auto jack = garantiBbva->addCustomer("1", "jack", "bauer");
    jack->addAccount(StandardAccount("tr1", 1'000));
    jack->addAccount(CheckingAccount("tr2", 2'000, 500));
    jack->addAccount(SavingsAccount("tr3", 3'000, 12));
    auto kate = garantiBbva->addCustomer("2", "kate", "austen");
    kate->addAccount(StandardAccount("tr4", 4'000));
    kate->addAccount(CheckingAccount("tr5", 5'000, 500));
    kate->addAccount(SavingsAccount("tr6", 6'000, 12));
    cout << "# of accounts in the bank: " << garantiBbva->getTotalAccounts() << endl;
    cout << "total balance in customers' accounts: " << garantiBbva->getTotalBalance() << endl;
    for (auto i = 0; i < garantiBbva->getNumberOfCustomers(); ++i) {
        auto customer = garantiBbva->getCustomer(i);
        if (customer.has_value()) { // guard
            auto acc = customer->get()->getAccount(0);
            if (acc.has_value()) { // guard
                acc->get()->deposit(i * 10'000 + 5'000);
                // Print out the final Account balance
                cout << endl
                     << "Customer ["
                     << customer->get()->getLastName()
                     << ", "
                     << customer->get()->getFirstName()
                     << "] has a balance of "
                     << acc->get()->getBalance()
                     << endl;
            }
        }
    }
    garantiBbva->report();
    delete garantiBbva;
    return 0; // triggers bank's destructors 2x
}