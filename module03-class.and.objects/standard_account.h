#ifndef MODULE03_CLASS_AND_OBJECTS_STANDARD_ACCOUNT_H
#define MODULE03_CLASS_AND_OBJECTS_STANDARD_ACCOUNT_H

#include "account.h"
#include <iostream>

using namespace std;

namespace banking {

    class StandardAccount : public Account {
    public:
        StandardAccount(const string &iban, const double balance) : Account(iban, balance) {
            std::cout << "StandardAccount::StandardAccount(...)" << std::endl;
        }

        bool withdraw(const double amount) override;

        bool deposit(const double amount) override;

        ~StandardAccount() {
            cout << "StandardAccount::~StandardAccount()" << endl;
        }
    };

} // banking

#endif //MODULE03_CLASS_AND_OBJECTS_STANDARD_ACCOUNT_H
