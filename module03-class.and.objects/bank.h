#ifndef MODULE03_CLASS_AND_OBJECTS_BANK_H
#define MODULE03_CLASS_AND_OBJECTS_BANK_H

#include "customer.h"
#include <vector>
#include <memory>
#include <optional>

using namespace std;

namespace banking {

    class bank {
        vector<shared_ptr<Customer>> customers;
        map<string,shared_ptr<Customer>> customersMap;
    public:
        bank(); // Default constructor

        bank(const bank &other); // Copy constructor

        void operator=(const bank &other); // assignment operator

        ~bank(); // destructor

        shared_ptr<Customer> addCustomer(const string &identity,const string &firstName, const string &lastName, const string &iban);

        int getNumberOfCustomers() const;

        optional<shared_ptr<Customer>> getCustomer(const int index) const;
        optional<shared_ptr<Customer>> getCustomer(const string &identity) const;

        double getTotalBalance() const;
        int getTotalAccounts() const;
    };

} // banking

#endif //MODULE03_CLASS_AND_OBJECTS_BANK_H
