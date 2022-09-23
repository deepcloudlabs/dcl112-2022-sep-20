#include <iostream>
#include <memory>
#include <algorithm>
#include <numeric>
#include "customer.h"

using banking::Customer;
using banking::Account;
using namespace std;

const string &Customer::getFirstName() const {
    return firstName;
}

const string &Customer::getLastName() const {
    return lastName;
}

optional<shared_ptr<Account>> Customer::getAccount(const int index) const {
    if (index < 0) return nullopt;
    if (index >= accounts.size()) return nullopt;
    return optional<shared_ptr<Account>>{accounts[index]};
}

double Customer::getTotalBalance()  const {
    /*
    auto total = 0.0;
    for (auto acc : accounts) { // for-loop
        total += acc->getBalance();
    }
    return total;
     */
    return accumulate(accounts.begin(),
                      accounts.end(),
                      double(),
                      [](double total, const shared_ptr<Account>& acc){
                        return total + acc->getBalance();
                      }
    );
}

double Customer::withdrawCost(const double cost) const {
    /*
    auto total = 0.0;
    for (auto acc : accounts) {
        if(acc->withdraw(cost)){
            total += cost;
        }
    }
    return total;
     */
    return count_if(accounts.begin(),accounts.end(),[cost](auto &acc){
       return acc->withdraw(cost);
    }) * cost;
}

map<string,double> Customer::groupByAccountType() const {
     return accumulate(
             accounts.begin(),
             accounts.end(),
             map<string,double>(),
             [](map<string,double> group, auto acc)
             {
                 auto key = typeid(*acc).name();
                 auto balance = acc->getBalance();
                 if (group.find(key) != group.end()){
                     balance += group[key];
                 }
                 group[key] = balance;
                 return group;
             }
     );
}

Customer::~Customer() {
    cout << "Customer::~Customer()" << endl;
}

int Customer::getNumberOfAccounts() const {
    return accounts.size();
}