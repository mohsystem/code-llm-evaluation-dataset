
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_ACCOUNTS 100

typedef struct {
    char account_number[20];
    double balance;
    bool is_open;
    pthread_mutex_t lock;
} BankAccount;

typedef struct {
    BankAccount accounts[MAX_ACCOUNTS];
    int account_count;
    pthread_mutex_t lock;
} Bank;

Bank bank;

void init_bank() {
    bank.account_count = 0;
    pthread_mutex_init(&bank.lock, NULL);
}

bool open_account(const char* account_number, double initial_balance) {
    pthread_mutex_lock(&bank.lock);
    if (bank.account_count >= MAX_ACCOUNTS) {
        pthread_mutex_unlock(&bank.lock);
        return false;
    }
    for (int i = 0; i < bank.account_count; i++) {
        if (strcmp(bank.accounts[i].account_number, account_number) == 0) {
            pthread_mutex_unlock(&bank.lock);
            return false;
        }
    }
    BankAccount* account = &bank.accounts[bank.account_count++];
    strcpy(account->account_number, account_number);
    account->balance = initial_balance;
    account->is_open = true;
    pthread_mutex_init(&account->lock, NULL);
    pthread_mutex_unlock(&bank.lock);
    return true;
}

BankAccount* find_account(const char* account_number) {
    for (int i = 0; i < bank.account_count; i++) {
        if (strcmp(bank.accounts[i].account_number, account_number) == 0) {
            return &bank.accounts[i];
        }
    }
    return NULL;
}

bool close_account(const char* account_number) {
    pthread_mutex_lock(&bank.lock);
    BankAccount* account = find_account(account_number);
    if (account == NULL) {
        pthread_mutex_unlock(&bank.lock);
        return false;
    }
    pthread_mutex_lock(&account->lock);
    if (!account->is_open) {
        pthread_mutex_unlock(&account->lock);
        pthread_mutex_unlock(&bank.lock);
        return false;
    }
    account->is_open = false;
    pthread_mutex_unlock(&account->lock);
    pthread_mutex_unlock(&bank.lock);
    return true;
}

bool deposit(const char* account_number, double amount) {
    pthread_mutex_lock(&bank.lock);
    BankAccount* account = find_account(account_number);
    if (account == NULL) {
        pthread_mutex_unlock(&bank.lock);
        return false;
    }
    pthread_mutex_lock(&account->lock);
    pthread_mutex_unlock(&bank.lock);
    if (!account->is_open) {
        pthread_mutex_unlock(&account->lock);
        return false;
    }
    account->balance += amount;
    pthread_mutex_unlock(&account->lock);
    return true;
}

bool withdraw(const char* account_number, double amount) {
    pthread_mutex_lock(&bank.lock);
    BankAccount* account = find_account(account_number);
    if (account == NULL) {
        pthread_mutex_unlock(&bank.lock);
        return false;
    }
    pthread_mutex_lock(&account->lock);', type='text')