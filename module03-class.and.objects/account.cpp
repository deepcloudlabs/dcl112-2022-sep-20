#include "account.h"
#include <iostream>

using namespace std;

// definition
namespace banking {

    Account::Account(const string &iban) : Account(iban, 10.0) {}

    Account::Account(const string &iban, double balance) : iban(iban), balance(balance) {
        cout << "Account::Account(...)" << endl;
    }

    const string &Account::getIban() const {
        return iban;
    }

    double Account::getBalance() const {
        return balance;
    }

    Account::~Account() {
        cout << "Account::~Account()" << endl;
    }
} // banking