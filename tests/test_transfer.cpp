#include <gtest/gtest.h>
#include "Account.h"
#include "Transaction.h"

TEST(TransactionTest, TransferSuccess) {
    Account from(100.0);
    Account to(50.0);
    
    EXPECT_TRUE(Transaction::transfer(from, to, 60.0));
    EXPECT_DOUBLE_EQ(from.getBalance(), 40.0);
    EXPECT_DOUBLE_EQ(to.getBalance(), 110.0);
}

TEST(TransactionTest, TransferInsufficientFunds) {
    Account from(30.0);
    Account to(100.0);
    
    EXPECT_FALSE(Transaction::transfer(from, to, 50.0));
    EXPECT_DOUBLE_EQ(from.getBalance(), 30.0);
    EXPECT_DOUBLE_EQ(to.getBalance(), 100.0);
}
