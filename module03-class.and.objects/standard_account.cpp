//
// Created by dcl on 9/22/2022.
//

#include "standard_account.h"

namespace banking {
    // definition
    bool StandardAccount::withdraw(const double amount) {
        // validation
        if (amount <= 0.0) return false;
        // business rule
        if (amount > this->balance) return false;
        // business logic
        this->balance -= amount;
        return true;
    }

    bool StandardAccount::deposit(const double amount) {
        // validation
        if (amount <= 0.0) return false;
        // business logic
        this->balance += amount;
        return true;
    }

} // banking