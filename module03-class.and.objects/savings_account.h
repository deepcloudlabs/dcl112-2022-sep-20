//
// Created by dcl on 9/22/2022.
//

#ifndef MODULE03_CLASS_AND_OBJECTS_SAVINGS_ACCOUNT_H
#define MODULE03_CLASS_AND_OBJECTS_SAVINGS_ACCOUNT_H

#include "account.h"
#include <iostream>

namespace banking {

    class SavingsAccount : public Account {
        const double interestRate;
    public:
        SavingsAccount(const string &iban= "", const double balance=0.0, const double interestRate=1.0)
                : Account(iban, balance), interestRate(interestRate) {
            std::cout << "SavingsAccount::SavingsAccount(...)" << std::endl;
        }
        bool withdraw(const double amount) override;

        bool deposit(const double amount) override;

        double getInterestRate() const {
            return interestRate;
        }

        ~SavingsAccount() {
            std::cout << "SavingsAccount::~SavingsAccount()" << std::endl;
        }
    };

} // banking

#endif //MODULE03_CLASS_AND_OBJECTS_SAVINGS_ACCOUNT_H
