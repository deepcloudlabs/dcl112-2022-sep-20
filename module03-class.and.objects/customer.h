#ifndef MODULE03_CLASS_AND_OBJECTS_CUSTOMER_H
#define MODULE03_CLASS_AND_OBJECTS_CUSTOMER_H

#include <string>
#include "account.h"
#include "checking_account.h"

using namespace std;

namespace banking {
    class customer {
        string firstName;
        string lastName;
        account **accounts; // one-to-many
        int numOfAccounts;
    public:
        customer(const string &firstName, const string &lastName)
                : firstName(firstName), lastName(lastName),
                  accounts(new account *[10]),
                  numOfAccounts(0) {}

        const string &getFirstName() const;

        const string &getLastName() const;

        account *getAccount(const int index) const;

        int getNumberOfAccounts() const;

        void addAccount(account *customerAccount);

        double getTotalBalance() const;

        double withdrawCost(const double cost) const;

        ~customer();
    };
}
#endif //MODULE03_CLASS_AND_OBJECTS_CUSTOMER_H
