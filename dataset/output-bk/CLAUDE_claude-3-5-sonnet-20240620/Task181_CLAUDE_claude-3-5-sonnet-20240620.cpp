
#include <iostream>
#include <unordered_map>
#include <mutex>
#include <thread>
#include <chrono>

class BankAccount {
private:
    std::string accountNumber;
    double balance;
    bool isOpen;
    std::mutex mtx;

public:
    BankAccount(const std::string& accNum, double initialBalance)
        : accountNumber(accNum), balance(initialBalance), isOpen(true) {}

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

    double getBalance() {
        std::lock_guard<std::mutex> lock(mtx);
        if (!isOpen) return -1;
        return balance;
    }
};

class Bank {
private:
    std::unordered_map<std::string, BankAccount> accounts;
    std::mutex mtx;

public:
    bool openAccount(const std::string& accountNumber, double initialBalance) {
        std::lock_guard<std::mutex> lock(mtx);
        if (accounts.find(accountNumber) != accounts.end()) return false;
        accounts.emplace(accountNumber, BankAccount(accountNumber, initialBalance));
        return true;
    }

    bool closeAccount(const std::string& accountNumber) {
        std::lock_guard<std::mutex> lock(mtx);
        auto it = accounts.find(accountNumber);
        if (it == accounts.end()) return false;
        return it->second.close();
    }

    bool deposit(const std::string& accountNumber, double amount) {
        std::lock_guard<std::mutex> lock(mtx);
        auto it = accounts.find(accountNumber);
        if (it == accounts.end()) return false;
        return it->second.deposit(amount);
    }

    bool withdraw(const std::string& accountNumber, double amount) {
        std::lock_guard<std::mutex> lock(mtx);
        auto it = accounts.find(accountNumber);
        if (it == accounts.end()) return false;
        return it->second.withdraw(amount);
    }

    double getBalance(const std::string& accountNumber) {
        std::lock_guard<std::mutex> lock(mtx);
        auto it = accounts.find(accountNumber);
        if (it == accounts.end()) return -1;
        return it->second.getBalance();
    }
};

void accountOperations(Bank& bank, const std::string& accountNumber) {
    bank.deposit(accountNumber, 100);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    bank.withdraw(accountNumber, 50);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Account " << accountNumber << " balance: " << bank.getBalance(accountNumber) << std::endl;
}

int main() {
    Bank bank;
    bank.openAccount("123", 1000);
    bank.openAccount("456", 2000);

    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(accountOperations, std::ref(bank), "123");
        threads.emplace_back(accountOperations, std::ref(bank), "456");
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Final balances:" << std::endl;
    std::cout << "Account 123: " << bank.getBalance("123") << std::endl;
    std::cout << "Account 456: " << bank.getBalance("456") << std::endl;

    bank.closeAccount("123");
    std::cout << "Closed account 123 balance: " << bank.getBalance("123") << std::endl;

    return 0;
}
