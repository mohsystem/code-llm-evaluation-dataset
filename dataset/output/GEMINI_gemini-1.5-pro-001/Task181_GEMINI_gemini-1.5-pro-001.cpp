#include <iostream>
#include <mutex>

class BankAccount {
private:
    double balance;
    std::mutex mutex;
    bool isOpen;

public:
    BankAccount(double initialBalance = 0) : balance(initialBalance), isOpen(true) {}

    void open() {
        std::lock_guard<std::mutex> lock(mutex);
        if (!isOpen) {
            isOpen = true;
        } else {
            throw std::runtime_error("Account is already open.");
        }
    }

    void close() {
        std::lock_guard<std::mutex> lock(mutex);
        if (isOpen) {
            isOpen = false;
        } else {
            throw std::runtime_error("Account is already closed.");
        }
    }

    void deposit(double amount) {
        std::lock_guard<std::mutex> lock(mutex);
        if (!isOpen) {
            throw std::runtime_error("Cannot deposit to a closed account.");
        }
        if (amount <= 0) {
            throw std::invalid_argument("Deposit amount must be positive.");
        }
        balance += amount;
    }

    void withdraw(double amount) {
        std::lock_guard<std::mutex> lock(mutex);
        if (!isOpen) {
            throw std::runtime_error("Cannot withdraw from a closed account.");
        }
        if (amount <= 0) {
            throw std::invalid_argument("Withdrawal amount must be positive.");
        }
        if (balance < amount) {
            throw std::runtime_error("Insufficient funds.");
        }
        balance -= amount;
    }

    double getBalance() {
        std::lock_guard<std::mutex> lock(mutex);
        if (!isOpen) {
            throw std::runtime_error("Cannot get balance of a closed account.");
        }
        return balance;
    }
};