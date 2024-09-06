#include <mutex>
#include <stdexcept>

class BankAccount {
    double balance;
    bool isOpen;
    std::mutex mtx;

public:
    BankAccount(double initialBalance) : balance(initialBalance), isOpen(true) {}

    void deposit(double amount) {
        std::lock_guard<std::mutex> lock(mtx);
        if (!isOpen) {
            throw std::runtime_error("Account is closed");
        }
        if (amount < 0) {
            throw std::invalid_argument("Deposit amount must be positive");
        }
        balance += amount;
    }

    bool withdraw(double amount) {
        std::lock_guard<std::mutex> lock(mtx);
        if (!isOpen) {
            throw std::runtime_error("Account is closed");
        }
        if (amount < 0) {
            throw std::invalid_argument("Withdraw amount must be positive");
        }
        if (balance < amount) {
            return false;
        }
        balance -= amount;
        return true;
    }

    void close() {
        std::lock_guard<std::mutex> lock(mtx);
        isOpen = false;
    }
};