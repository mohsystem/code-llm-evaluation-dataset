code here:
#include <mutex>

class BankAccount {
private:
    double balance;
    bool closed;
    std::mutex lock;

public:
    BankAccount(double initialBalance = 0) : balance(initialBalance), closed(false) {}

    void openAccount() {
        closed = false;
    }

    void closeAccount() {
        closed = true;
    }

    bool deposit(double amount) {
        if (closed) {
            return false;
        }
        std::lock_guard<std::mutex> guard(lock);
        balance += amount;
        return true;
    }

    bool withdraw(double amount) {
        if (closed) {
            return false;
        }
        std::lock_guard<std::mutex> guard(lock);
        if (amount > balance) {
            return false;
        }
        balance -= amount;
        return true;
    }

    double getBalance() {
        std::lock_guard<std::mutex> guard(lock);
        return balance;
    }
};