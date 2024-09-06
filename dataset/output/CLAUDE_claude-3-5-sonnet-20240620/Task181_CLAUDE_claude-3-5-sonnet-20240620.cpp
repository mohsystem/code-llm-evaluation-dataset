
#include <iostream>
#include <unordered_map>
#include <mutex>
#include <thread>

class BankAccount {
private:
    std::string accountNumber;
    double balance;
    bool isOpen;
    std::mutex mutex;

public:
    BankAccount(const std::string& accNumber, double initialBalance)
        : accountNumber(accNumber), balance(initialBalance), isOpen(true) {}

    bool deposit(double amount) {
        std::lock_guard<std::mutex> lock(mutex);
        if (!isOpen) {
            return false;
        }
        if (amount <= 0) {
            return false;
        }
        balance += amount;
        return true;
    }

    bool withdraw(double amount) {
        std::lock_guard<std::mutex> lock(mutex);
        if (!isOpen) {
            return false;
        }
        if (amount <= 0 || amount > balance) {
            return false;
        }
        balance -= amount;
        return true;
    }

    bool close() {
        std::lock_guard<std::mutex> lock(mutex);
        if (!isOpen) {
            return false;
        }
        isOpen = false;
        return true;
    }

    double getBalance() const {
        return balance;
    }
};

class Bank {
private:
    std::unordered_map<std::string, BankAccount> accounts;
    std::mutex mutex;

public:
    bool openAccount(const std::string& accountNumber, double initialBalance) {
        std::lock_guard<std::mutex> lock(mutex);
        if (accounts.find(accountNumber) != accounts.end()) {
            return false;
        }
        accounts.emplace(accountNumber, BankAccount(accountNumber, initialBalance));
        return true;
    }

    bool closeAccount(const std::string& accountNumber) {
        std::lock_guard<std::mutex> lock(mutex);
        auto it = accounts.find(accountNumber);
        if (it == accounts.end()) {
            return false;
        }
        return it->second.close();
    }

    bool deposit(const std::string& accountNumber, double amount) {
        std::lock_guard<std::mutex> lock(mutex);
        auto it = accounts.find(accountNumber);
        if (it == accounts.end()) {
            return false;
        }
        return it->second.deposit(amount);
    }

    bool withdraw(const std::string& accountNumber, double amount) {
        std::lock_guard<std::mutex> lock(mutex);
        auto it = accounts.find(accountNumber);
        if (it == accounts.end()) {
            return false;
        }
        return it->second.withdraw(amount);
    }

    BankAccount* getAccount(const std::string& accountNumber) {
        auto it = accounts.find(accountNumber);
        if (it == accounts.end()) {
            return nullptr;
        }
        return &it->second;
    }
};

int main() {
    Bank bank;
    bank.openAccount("123", 1000);
    bank.openAccount("456", 500);

    std::thread thread1([&bank]() {
        bank.deposit("123", 200);
        bank.withdraw("456", 100);
    });

    std::thread thread2([&bank]() {
        bank.withdraw("123", 300);
        bank.deposit("456", 150);
    });

    thread1.join();
    thread2.join();

    BankAccount* account123 = bank.getAccount("123");
    BankAccount* account456 = bank.getAccount("456");

    if (account123 && account456) {
        std::cout << "Account 123 balance: " << account123->getBalance() << std::endl;
        std::cout << "Account 456 balance: " << account456->getBalance() << std::endl;
    }

    return 0;
}
