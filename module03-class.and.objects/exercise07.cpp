#include "bank.h"
#include "customer.h"
#include "standard_account.h"
#include <iostream>

using banking::bank;
using banking::Customer;
using banking::StandardAccount;
using namespace std;

int main() {
    auto garantiBbva = new bank(); // heap object
    auto jack = garantiBbva->addCustomer("jack", "bauer", "tr1");
    jack->addAccount(new StandardAccount("tr1",1'000));
    auto kate = garantiBbva->addCustomer("kate", "austen", "tr2");
    kate->addAccount(new StandardAccount("tr2",2'000));
    for (auto i = 0; i < garantiBbva->getNumberOfCustomers(); ++i) {
        auto customer = garantiBbva->getCustomer(i);
        auto acc = customer->getAccount(0);
        acc->deposit(i * 10'000 + 5'000);
        // Print out the final Account balance
        cout << endl
             << "Customer ["
             << customer->getLastName()
             << ", "
             << customer->getFirstName()
             << "] has a balance of "
             << acc->getBalance()
             << endl;
    }
    delete garantiBbva;
    return 0; // triggers bank's destructors 2x
}