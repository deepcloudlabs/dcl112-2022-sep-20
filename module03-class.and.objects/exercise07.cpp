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
    auto jack = garantiBbva->addCustomer("1","jack", "bauer", "tr1");
    jack->addAccount(StandardAccount("tr1",1'000));
    auto kate = garantiBbva->addCustomer("2","kate", "austen", "tr2");
    kate->addAccount(StandardAccount("tr2",2'000));
    for (auto i = 0; i < garantiBbva->getNumberOfCustomers(); ++i) {
        auto customer = garantiBbva->getCustomer(i);
        if (customer.has_value()){
            auto acc = customer->get()->getAccount(0);
            if (acc.has_value()){
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
    delete garantiBbva;
    return 0; // triggers bank's destructors 2x
}