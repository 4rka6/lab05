#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
private:
    double balance;
public:
    Account(double initial = 0.0);
    void deposit(double amount);
    bool withdraw(double amount);
    double getBalance() const;
};

#endif
