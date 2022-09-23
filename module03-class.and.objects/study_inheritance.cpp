#include "checking_account.h"
#include <iostream>

using banking::CheckingAccount;
using namespace std;

int main() {

    CheckingAccount acc1("tr1", 100'000, 10'000);
    cout << "acc1.getBalance():" << acc1.getBalance() << endl;
    acc1.withdraw(100'000);
    cout << "acc1.getBalance():" << acc1.getBalance() << endl;
    acc1.withdraw(5'000);
    cout << "acc1.getBalance():" << acc1.getBalance() << endl;
    acc1.withdraw(5'000);
    cout << "acc1.getBalance():" << acc1.getBalance() << endl;
    acc1.withdraw(1);
    cout << "acc1.getBalance():" << acc1.getBalance() << endl;
    return 0;
}