#ifndef MODULE03_CLASS_AND_OBJECTS_CUSTOMER_H
#define MODULE03_CLASS_AND_OBJECTS_CUSTOMER_H
#include <string>
#include "account.h"

using namespace std;

namespace banking {
    class customer {
        string firstName;
        string lastName;
        account customerAccount;
        int *p;
    public:
        customer(const string &firstName,const string &lastName,const string &iban)
               : firstName(firstName), lastName(lastName),
                 customerAccount(iban)
               {}
        const string& getFirstName() const;
        const string& getLastName() const;
        account &getCustomerAccount();
        void setCustomerAccount(account &customerAccount);
        ~customer();
    };
}
#endif //MODULE03_CLASS_AND_OBJECTS_CUSTOMER_H
