#include <mutex>

class BankAccount {
private:
    double balance;
    bool closed;
    std::mutex lock;

public:
    BankAccount(double initialBalance = 0) : balance(initialBalance), closed(false) {}

    void openAccount() {
        if (closed) {
            throw std::runtime_error("Account is already closed");
        }
        closed = false;
    }

    void closeAccount() {
        if (closed) {
            throw std::runtime_error("Account is already closed");
        }
        closed = true;
    }

    void deposit(double amount) {
        if (closed) {
            throw std::runtime_error("Account is closed");
        }
        std::lock_guard<std::mutex> guard(lock);
        balance += amount;
    }

    void withdraw(double amount) {
        if (closed) {
            throw std::runtime_error("Account is closed");
        }
        std::lock_guard<std::mutex> guard(lock);
        if (amount > balance) {
            throw std::runtime_error("Insufficient balance");
        }
        balance -= amount;
    }

    double getBalance() {
        if (closed) {
            throw std::runtime_error("Account is closed");
        }
        std::lock_guard<std::mutex> guard(lock);
        return balance;
    }
};