//
// Created by dcl on 9/22/2022.
//

#include "savings_account.h"

namespace banking {
    bool SavingsAccount::withdraw(const double amount) {
        // validation
        if (amount <= 0.0) return false;
        // business rule
        if (amount > this->balance) return false;
        // business logic
        this->balance -= amount;
        return true;
    }

    bool SavingsAccount::deposit(const double amount) {
        // validation
        if (amount <= 0.0) return false;
        // business logic
        this->balance += amount;
        return true;
    }
} // banking