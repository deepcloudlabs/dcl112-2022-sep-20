#include "account.h"

// definition
namespace banking {
    // definition
    bool account::withdraw(const double amount) {
        // validation
        if (amount <= 0.0) return false;
        // business rule
        if (amount > this->balance) return false;
        // business logic
        this->balance -= amount;
        return true;
    }

    bool account::deposit(const double amount) {
        // validation
        if (amount <= 0.0) return false;
        // business logic
        this->balance += amount;
        return true;
    }

    account::account(const string &iban) : account(iban, 10.0) {}

    account::account(const string &iban, double balance) : iban(iban) {
        this->balance = balance;
    }

    const string &account::getIban() const {
        return iban;
    }

    double account::getBalance() const {
        return balance;
    }
} // banking