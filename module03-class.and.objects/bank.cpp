#include "bank.h"
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

namespace banking {
    bank::bank() {
        cout << "bank::bank()" << endl;
    }

    bank::bank(const bank &other) : customers(other.customers), customersMap(other.customersMap) {
        cout << "bank::bank(const bank& other)" << endl;
    }

    void bank::operator=(const bank &other) {
        cout << "bank::operator=(const bank& other)" << endl;
        customers.clear();
        customersMap.clear();
        customers.insert(customers.begin(),other.customers.begin(),other.customers.end());
        customersMap.insert(other.customersMap.begin(),other.customersMap.end());
    }

    bank::~bank() {
        cout << "bank::~bank()" << endl;
    }

    shared_ptr<Customer> bank::addCustomer(const string &identity,const string &firstName, const string &lastName, const string &iban) {
        auto customer = make_shared<Customer>(Customer(identity,firstName, lastName));
        customersMap[identity] = customer;
        customers.insert(customers.end(),customer);
        return customer;
    }

    int bank::getNumberOfCustomers() const {
        return customers.size();
    }

    optional<shared_ptr<Customer>> bank::getCustomer(const int index) const {
        if (index < 0) return nullopt;
        if (index >= customers.size()) return nullptr;
        return optional(customers[index]);
    }

    double bank::getTotalBalance() const{
         return accumulate(customers.begin(),customers.end(),double(),[](double sum,auto &customer){
             return sum + customer->getTotalBalance();
         });
    }

    int bank::getTotalAccounts() const{
        return accumulate(customers.begin(),customers.end(),double(),[](double sum,auto &customer){
            return sum + customer->getNumberOfAccounts();
        });
    }

    optional<shared_ptr<Customer>> bank::getCustomer(const string &identity) const {
        /*
        for (auto& customer : customers){
            if (std::equal(customer->getIdentity().begin(), customer->getIdentity().end(),identity.begin(),identity.end()))
                return optional(customer);
        }
        return nullopt;
        */

        auto customer = customersMap.find(identity);
        if (customer == customersMap.end()) return nullopt;
        return optional(customer->second);
    }

} // banking