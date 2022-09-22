#ifndef MODULE03_CLASS_AND_OBJECTS_ACCOUNT_H
#define MODULE03_CLASS_AND_OBJECTS_ACCOUNT_H

#include <string>

using namespace std;
// declaration
namespace banking {
    // information hiding
    class account {
    private: // default
        // attributes/field/state/data/property
        string iban;
        double balance;
    public:
        // methods/function/behaviour
        // overloaded 2 constructors
        explicit account(const string &iban);

        account(const string &iban, double balance);

        ~account();

        // getters -> read-only methods
        const string &getIban() const; // constant method

        double getBalance() const; // constant method

        // business methods -> mutator methods
        bool withdraw(const double amount);

        bool deposit(const double amount);
    };

} // banking

#endif //MODULE03_CLASS_AND_OBJECTS_ACCOUNT_H
