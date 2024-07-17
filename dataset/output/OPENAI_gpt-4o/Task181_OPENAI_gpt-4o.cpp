#include <iostream>
#include <unordered_map>
#include <mutex>
#include <stdexcept>

class BankAccount {
public:
    BankAccount(const std::string& id) : account_id(id), balance(0), is_open(true) {}

    void deposit(double amount) {
        std::lock_guard<std::mutex> guard(mtx);
        if (!is_open) throw std::runtime_error("Account is closed");
        balance += amount;
    }

    void withdraw(double amount) {
        std::lock_guard<std::mutex> guard(mtx);
        if (!is_open) throw std::runtime_error("Account is closed");
        if (amount > balance) throw std::runtime_error("Insufficient funds");
        balance -= amount;
    }

    double get_balance() {
        std::lock_guard<std::mutex> guard(mtx);
        if (!is_open) throw std::runtime_error("Account is closed");
        return balance;
    }

    void close_account() {
        std::lock_guard<std::mutex> guard(mtx);
        is_open = false;
    }

private:
    std::string account_id;
    double balance;
    bool is_open;
    std::mutex mtx;
};

class Bank {
public:
    void open_account(const std::string& account_id) {
        std::lock_guard<std::mutex> guard(mtx);
        if (accounts.find(account_id) != accounts.end()) 
            throw std::runtime_error("Account already exists");
        accounts[account_id] = new BankAccount(account_id);
    }

    void close_account(const std::string& account_id) {
        std::lock_guard<std::mutex> guard(mtx);
        if (accounts.find(account_id) == accounts.end()) 
            throw std::runtime_error("Account does not exist");
        accounts[account_id]->close_account();
    }

    void deposit(const std::string& account_id, double amount) {
        std::lock_guard<std::mutex> guard(mtx);
        if (accounts.find(account_id) == accounts.end()) 
            throw std::runtime_error("Account does not exist");
        accounts[account_id]->deposit(amount);
    }

    void withdraw(const std::string& account_id, double amount) {
        std::lock_guard<std::mutex> guard(mtx);
        if (accounts.find(account_id) == accounts.end()) 
            throw std::runtime_error("Account does not exist");
        accounts[account_id]->withdraw(amount);
    }

    double get_balance(const std::string& account_id) {
        std::lock_guard<std::mutex> guard(mtx);
        if (accounts.find(account_id) == accounts.end())
            throw std::runtime_error("Account does not exist");
        return accounts[account_id]->get_balance();
    }

private:
    std::unordered_map<std::string, BankAccount*> accounts;
    std::mutex mtx;
};

// Note: Actual usage could involve creating threads and performing operations on bank accounts.