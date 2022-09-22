//
// Created by dcl on 9/22/2022.
//

#ifndef MODULE03_CLASS_AND_OBJECTS_SAVINGS_ACCOUNT_H
#define MODULE03_CLASS_AND_OBJECTS_SAVINGS_ACCOUNT_H
#include "account.h"
#include <iostream>

namespace banking {

    class SavingsAccount : public account {
        const double interestRate;
    public:
        SavingsAccount(const string &iban,const double balance,const double interestRate)
           : account(iban,balance), interestRate(interestRate) {
           std::cout << "SavingsAccount::SavingsAccount(...)" << std::endl;
        }

        double getInterestRate() const {
            return interestRate;
        }

        ~SavingsAccount(){
           std::cout << "SavingsAccount::~SavingsAccount()" << std::endl;
        }
    };

} // banking

#endif //MODULE03_CLASS_AND_OBJECTS_SAVINGS_ACCOUNT_H
