#ifndef MODULE03_CLASS_AND_OBJECTS_BANK_H
#define MODULE03_CLASS_AND_OBJECTS_BANK_H

#include "customer.h"

namespace banking {

    class bank {
        customer* *customers;
        int numOfCustomers;
    public:
        bank(); // Default constructor

        bank(const bank& other); // Copy constructor

        void operator=(const bank& other); // assignment operator

        ~bank(); // destructor

        customer* addCustomer(const string &firstName,const string &lastName,const string &iban);

        int getNumberOfCustomers() const ;

        customer* getCustomer(const int index) const;

    };

} // banking

#endif //MODULE03_CLASS_AND_OBJECTS_BANK_H
