#ifndef MODULE03_CLASS_AND_OBJECTS_CHECKING_ACCOUNT_H
#define MODULE03_CLASS_AND_OBJECTS_CHECKING_ACCOUNT_H

#include "account.h"
#include <iostream>

using namespace std;

namespace banking {

    class CheckingAccount : public Account { // public/private inheritance
        double overdraftAmount;
    public:
        // constructor
        CheckingAccount(const string &iban, const double balance, const double overdraftAmount)
                : Account(iban, balance), overdraftAmount(overdraftAmount) {
            cout << "CheckingAccount::CheckingAccount(...)" << endl;
        }

        // getter
        double getOverdraftAmount() const {
            return overdraftAmount;
        }

        // business method
        // overriding: same method name & same signature
        bool withdraw(const double amount) override;

        bool deposit(const double amount) override;

        ~CheckingAccount() {
            cout << "CheckingAccount::~CheckingAccount()" << endl;
        }
    };

} // banking

#endif //MODULE03_CLASS_AND_OBJECTS_CHECKING_ACCOUNT_H
