#include <iostream>
#include <string>

class BankAccount{
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;
public:
    BankAccount(const std::string& accnum, const std::string& holderName, double initialBalance)
        : accountNumber(accnum), accountHolderName(holderName), balance(initialBalance) {
        if (initialBalance < 0) {
            throw std::invalid_argument("初始余额不能为负数");
        }
    }
    void deposit(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("存款金额必须大于零");
        }
        balance += amount;
    }
    void withdraw(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("取款金额必须大于零");
        }
        if (amount > balance) {
            throw std::out_of_range("余额不足");
        }
        balance -= amount;
    }
    double getBalance() const {
        return balance;
    }
};