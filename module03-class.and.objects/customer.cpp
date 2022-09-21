#include <iostream>
#include "customer.h"

using banking::customer;
using banking::account;
using namespace std;

const string &customer::getFirstName() const {
    return firstName;
}

const string &customer::getLastName() const {
    return lastName;
}

account &customer::getCustomerAccount() {
    return customerAccount;
}

void customer::setCustomerAccount(account &customerAccount) {
    this->customerAccount = customerAccount;
}

customer::~customer() {
    cout << "customer::~customer()" << endl;
}