#ifndef MODULE03_CLASS_AND_OBJECTS_CUSTOMER_H
#define MODULE03_CLASS_AND_OBJECTS_CUSTOMER_H

#include <string>
#include <deque>
#include <vector>
#include <map>
#include <memory>
#include <optional>
#include "account.h"
#include "checking_account.h"

using namespace std;

namespace banking {
    class Customer {
        string identity;
        string firstName;
        string lastName;
        deque<shared_ptr<Account>> accounts; // one-to-many
    public:
        Customer(const string &identity,const string &firstName, const string &lastName)
               : identity(identity),firstName(firstName), lastName(lastName) {
            cerr << "Customer::Customer(const string &firstName, const string &lastName)" << endl;
        }

        Customer(const Customer &other)
                    : firstName(other.firstName),
                      lastName(other.lastName),
                      accounts(other.accounts){
            cerr << "Customer::Customer(const Customer &other)" << endl;
        }

        const string &getFirstName() const;

        const string &getLastName() const;

        const string &getIdentity() const;

        optional<shared_ptr<Account>> getAccount(const int index) const;

        int getNumberOfAccounts() const;

        double getTotalBalance() const;

        double withdrawCost(const double cost) const;

        template <typename T>
        void addAccount(T && acc) {
            this->accounts.push_back(make_shared<T>(acc));
        }

        map<string,double> groupByAccountType() const ;
        ~Customer();
    };
}
#endif //MODULE03_CLASS_AND_OBJECTS_CUSTOMER_H
