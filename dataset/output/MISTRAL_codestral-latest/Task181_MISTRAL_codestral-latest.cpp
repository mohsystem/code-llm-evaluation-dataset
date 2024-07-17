#include <map>
#include <mutex>
#include <atomic>

class BankAccount {
    double balance;
    std::atomic<bool> isOpen;
    std::mutex mtx;

public:
    BankAccount(double initialBalance) : balance(initialBalance), isOpen(true) {}

    bool deposit(double amount) {
        std::lock_guard<std::mutex> lock(mtx);
        if (!isOpen) return false;
        balance += amount;
        return true;
    }

    bool withdraw(double amount) {
        std::lock_guard<std::mutex> lock(mtx);
        if (!isOpen || balance < amount) return false;
        balance -= amount;
        return true;
    }

    bool close() {
        std::lock_guard<std::mutex> lock(mtx);
        if (!isOpen) return false;
        isOpen = false;
        return true;
    }
};

class Bank {
    std::map<std::string, BankAccount> accounts;

public:
    bool openAccount(const std::string& accountId, double initialBalance) {
        return accounts.emplace(accountId, initialBalance).second;
    }

    bool deposit(const std::string& accountId, double amount) {
        auto it = accounts.find(accountId);
        return it != accounts.end() && it->second.deposit(amount);
    }

    bool withdraw(const std::string& accountId, double amount) {
        auto it = accounts.find(accountId);
        return it != accounts.end() && it->second.withdraw(amount);
    }

    bool closeAccount(const std::string& accountId) {
        auto it = accounts.find(accountId);
        return it != accounts.end() && it->second.close();
    }
};