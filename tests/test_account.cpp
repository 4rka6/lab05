#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Account.h"

TEST(AccountTest, InitialBalance) {
    Account acc(100.0);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 100.0);
}

TEST(AccountTest, Deposit) {
    Account acc(50.0);
    acc.deposit(30.0);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 80.0);
}

TEST(AccountTest, Withdraw) {
    Account acc(100.0);
    EXPECT_TRUE(acc.withdraw(40.0));
    EXPECT_DOUBLE_EQ(acc.getBalance(), 60.0);
}

TEST(AccountTest, WithdrawInsufficient) {
    Account acc(30.0);
    EXPECT_FALSE(acc.withdraw(50.0));
    EXPECT_DOUBLE_EQ(acc.getBalance(), 30.0);
}
