#include <iostream>
#include "customer.h"

using banking::Customer;
using banking::Account;
using namespace std;

const string &Customer::getFirstName() const {
    return firstName;
}

const string &Customer::getLastName() const {
    return lastName;
}

Account *Customer::getAccount(const int index) const {
    if (index < 0) return nullptr;
    if (index >= numOfAccounts) return nullptr;
    return accounts[index];
}

void Customer::addAccount(Account *customerAccount) {
    if (numOfAccounts >= 10) return;
    this->accounts[numOfAccounts++] = customerAccount;
}

double Customer::getTotalBalance() const {
    auto total = 0.0;
    for (auto i = 0; i < numOfAccounts; ++i) {
        total += accounts[i]->getBalance();
    }
    return total;
}

double Customer::withdrawCost(const double cost) const {
    auto total = 0.0;
    for (auto i = 0; i < numOfAccounts; ++i) {
        if(accounts[i]->withdraw(cost)){
            total += cost;
        }
    }
    return total;
}

Customer::~Customer() {
    cout << "Customer::~Customer()" << endl;
    for (auto i = 0; i < numOfAccounts; ++i) {
        delete accounts[i];
    }
    delete[]accounts;
}

int Customer::getNumberOfAccounts() const {
    return numOfAccounts;
}