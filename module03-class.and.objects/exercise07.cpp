#include "bank.h"
#include "customer.h"
#include <iostream>
using banking::bank;
using banking::customer;
using namespace std;

int main(){
    auto garantiBbva = new bank(); // heap object
    auto jack = garantiBbva->addCustomer("jack","bauer","tr1");
    auto kate = garantiBbva->addCustomer("kate","austen","tr2");
    // stack object
    bank denizBank(*garantiBbva); // copy constructor -> stack object
    for (auto i = 0;i<denizBank.getNumberOfCustomers();++i){
        auto cust = denizBank.getCustomer(i);
        auto acc = cust->getCustomerAccount();
        acc.deposit(i * 10'000 + 5'000);
        // Print out the final account balance
        cout  << endl
              << "Customer ["
              << cust->getLastName()
              << ", "
              << cust->getFirstName()
              << "] has a balance of "
              << acc.getBalance()
              << endl;
    }
    delete garantiBbva;
    return 0; // triggers bank's destructors 2x
}