#include <mutex>

class BankAccount {
private:
    double balance;
    std::mutex mtx;
    bool isOpen;

public:
    BankAccount(double initialBalance = 0) : balance(initialBalance), isOpen(true) {}

    void open() {
        if (isOpen) {
            throw std::runtime_error("Account already open");
        }
        isOpen = true;
    }

    void close() {
        if (!isOpen) {
            throw std::runtime_error("Account already closed");
        }
        isOpen = false;
    }

    void deposit(double amount) {
        if (!isOpen) {
            throw std::runtime_error("Account closed");
        }
        if (amount <= 0) {
            throw std::invalid_argument("Deposit amount must be positive");
        }
        std::lock_guard<std::mutex> lock(mtx);
        balance += amount;
    }

    void withdraw(double amount) {
        if (!isOpen) {
            throw std::runtime_error("Account closed");
        }
        if (amount <= 0) {
            throw std::invalid_argument("Withdrawal amount must be positive");
        }
        std::lock_guard<std::mutex> lock(mtx);
        if (balance < amount) {
            throw std::runtime_error("Insufficient funds");
        }
        balance -= amount;
    }
};