#include <iostream>
#include "customer.h"

using banking::customer;
using banking::account;
using namespace std;

const string &customer::getFirstName() const {
    return firstName;
}

const string &customer::getLastName() const {
    return lastName;
}

account *customer::getAccount(const int index) const {
    if (index < 0) return nullptr;
    if (index >= numOfAccounts) return nullptr;
    return accounts[index];
}

void customer::addAccount(account *customerAccount) {
    if (numOfAccounts >= 10) return;
    this->accounts[numOfAccounts++] = customerAccount;
}

double customer::getTotalBalance() const {
    auto total = 0.0;
    for (auto i = 0; i < numOfAccounts; ++i) {
        total += accounts[i]->getBalance();
    }
    return total;
}

double customer::withdrawCost(const double cost) const {
    auto total = 0.0;
    for (auto i = 0; i < numOfAccounts; ++i) {
        if(accounts[i]->withdraw(cost)){
            total += cost;
        }
    }
    return total;
}

customer::~customer() {
    cout << "customer::~customer()" << endl;
    for (auto i = 0; i < numOfAccounts; ++i) {
        delete accounts[i];
    }
    delete[]accounts;
}

int customer::getNumberOfAccounts() const {
    return numOfAccounts;
}