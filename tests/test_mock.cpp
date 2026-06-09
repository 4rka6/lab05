#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Account.h"
#include "Transaction.h"
#include "IValidator.h"

using ::testing::_;
using ::testing::Return;

class MockValidator : public IValidator {
public:
    MOCK_METHOD(bool, validate, (double amount), (override));
};

TEST(TransactionMockTest, ValidatorCalledWhenAmountValid) {
    Account from(100.0);
    Account to(50.0);
    MockValidator validator;
    
    EXPECT_CALL(validator, validate(60.0))
        .Times(1)
        .WillOnce(Return(true));
    
    EXPECT_TRUE(Transaction::transfer(from, to, 60.0, &validator));
}

TEST(TransactionMockTest, ValidatorNotCalledWhenValidatorNull) {
    Account from(100.0);
    Account to(50.0);
    
    EXPECT_TRUE(Transaction::transfer(from, to, 60.0, nullptr));
}

TEST(TransactionMockTest, TransferFailsWhenValidatorReturnsFalse) {
    Account from(100.0);
    Account to(50.0);
    MockValidator validator;
    
    EXPECT_CALL(validator, validate(60.0))
        .Times(1)
        .WillOnce(Return(false));
    
    EXPECT_FALSE(Transaction::transfer(from, to, 60.0, &validator));
}
