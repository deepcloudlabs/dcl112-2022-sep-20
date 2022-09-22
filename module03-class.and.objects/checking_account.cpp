#include "checking_account.h"

namespace banking {
    bool CheckingAccount::withdraw(const double amount)  {
        // validation
        if (amount <= 0.0) return false;
        // business rule
        if (amount > (this->balance+overdraftAmount)) return false;
        // business logic
        this->balance -= amount;
        return true;
    }

    bool CheckingAccount::deposit(const double amount) {
        // validation
        if (amount <= 0.0) return false;
        // business logic
        this->balance += amount;
        return true;
    }
} // banking