#include <iostream>
// 1. Class & Object -> Encapsulation + Information Hiding
// 2. Inheritance    -> Re-usability ?
// 3. Polymorphism   -> Agility

// Class -> Modeling/Abstraction
// Domain Problems -> Abstraction -> Domain Class          -> Account, Customer, Bank, ...
// Technologies    -> Solution    -> Solution/Design Class -> AccountRepository

#include "account.h"

using banking::account;

int main() {
    {
        // stack object -> automatically destroys stack object
        account acc1("tr1", 100000.50);
        acc1.withdraw(50000);
        std::cout << "balance: " << acc1.getBalance() << endl;
    } // triggers class destructor for acc1

    // heap object
    account *pAcc; // stack pointer, there is NO object created YET!
    pAcc = new account("tr2", 200000); // triggers class constructor
    pAcc->deposit(5000);
    std::cout << "balance: " << pAcc->getBalance() << endl;
    delete pAcc; // triggers class destructor

    // constant object -> you can call ONLY constant methods?
    const account acc2("tr1", 100000.50);
    acc2.getBalance();
    acc2.getIban();
    // acc2.deposit(5'000); Error: cannot call mutator method through constant object
    // account acc3; Error: No-argument/Default constructor does not exist!
    return 0;
}
