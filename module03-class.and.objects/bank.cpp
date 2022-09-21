#include "bank.h"
#include <iostream>

using namespace std;

namespace banking {
    bank::bank() : numOfCustomers(0){
        cout << "bank::bank()" << endl;
        customers = new customer*[5]; // (1)
    }

    bank::bank(const bank& other) : bank() {
        cout << "bank::bank(const bank& other)" << endl;
       for (auto i=0;i<other.numOfCustomers;++i){
           customers[i] = new customer(*other.customers[i]); // triggers customer's copy constructor
       }
       numOfCustomers = other.numOfCustomers;
    }

    void bank::operator=(const bank& other) {
        cout << "bank::operator=(const bank& other)" << endl;
        // from destructor
        for (auto i=0;i<numOfCustomers;++i){
            delete customers[i];
        }
        // from copy constructor
        for (auto i=0;i<other.numOfCustomers;++i){
            customers[i] = new customer(*other.customers[i]); // triggers customer's copy constructor
        }
        numOfCustomers = other.numOfCustomers;

    }

    bank::~bank(){
        cout << "bank::~bank()" << endl;
        for (auto i=0;i<numOfCustomers;++i){
            delete customers[i];
        }
        delete [] customers; // dis-allocates the memory space allocated at (1)
    }

    customer* bank::addCustomer(const string &firstName,const string &lastName,const string& iban){
        if (numOfCustomers == 5){
            return nullptr;
        }
        auto pCustomer = new customer(firstName, lastName, iban);
        customers[numOfCustomers] = pCustomer;
        numOfCustomers++;
        return pCustomer;
    }

    int bank::getNumberOfCustomers() const {
        return numOfCustomers;
    }

    customer* bank::getCustomer(const int index) const {
        if (index < 0) return nullptr;
        if (index >= numOfCustomers) return nullptr;
        return customers[index];
    }
} // banking