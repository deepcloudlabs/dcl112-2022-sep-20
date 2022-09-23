#ifndef MODULE03_CLASS_AND_OBJECTS_ACCOUNT_H
#define MODULE03_CLASS_AND_OBJECTS_ACCOUNT_H

#include <string>

using namespace std;
// declaration
namespace banking {
    // information hiding
    class Account { // abstract class
    private: // default
        // attributes/field/state/data/property
        string iban;
    protected:
        double balance;
    public:
        // methods/function/behaviour
        // overloaded 2 constructors
        explicit Account(const string &iban);
        Account(const string &iban, double balance);

        virtual ~Account();

        // getters -> read-only methods
        const string &getIban() const; // constant method

        double getBalance() const; // constant method

        // business methods -> mutator methods
        virtual bool withdraw(const double amount)=0; // pure virtual method
        virtual bool deposit(const double amount)=0; // pure virtual method
    };

} // banking

#endif //MODULE03_CLASS_AND_OBJECTS_ACCOUNT_H
