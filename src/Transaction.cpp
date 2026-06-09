#include "Transaction.h"

bool Transaction::transfer(Account& from, Account& to, double amount, IValidator* validator) {
    if (validator && !validator->validate(amount)) {
        return false;
    }
    if (from.withdraw(amount)) {
        to.deposit(amount);
        return true;
    }
    return false;
}
