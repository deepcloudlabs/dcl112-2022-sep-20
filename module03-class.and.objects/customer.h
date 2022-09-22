#ifndef MODULE03_CLASS_AND_OBJECTS_CUSTOMER_H
#define MODULE03_CLASS_AND_OBJECTS_CUSTOMER_H

#include <string>
#include "account.h"
#include "checking_account.h"

using namespace std;

namespace banking {
    class Customer {
        string firstName;
        string lastName;
        Account **accounts; // one-to-many
        int numOfAccounts;
    public:
        Customer(const string &firstName, const string &lastName) : firstName(firstName), lastName(lastName),
                                                                    accounts(new Account *[10]), numOfAccounts(0) {}

        const string &getFirstName() const;

        const string &getLastName() const;

        Account *getAccount(const int index) const;

        int getNumberOfAccounts() const;

        void addAccount(Account *customerAccount);

        double getTotalBalance() const;

        double withdrawCost(const double cost) const;

        ~Customer();
    };
}
#endif //MODULE03_CLASS_AND_OBJECTS_CUSTOMER_H
