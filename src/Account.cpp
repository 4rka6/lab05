#include "Account.h"

Account::Account(double initial) : balance(initial) {}

void Account::deposit(double amount) {
    if (amount > 0) balance += amount;
}

bool Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}

double Account::getBalance() const {
    return balance;
}
