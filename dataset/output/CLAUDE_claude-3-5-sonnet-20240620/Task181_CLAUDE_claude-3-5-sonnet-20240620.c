
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>

#define MAX_ACCOUNTS 100

typedef struct {
    char account_number[20];
    double balance;
    bool is_open;
    pthread_mutex_t mutex;
} BankAccount;

typedef struct {
    BankAccount accounts[MAX_ACCOUNTS];
    int account_count;
    pthread_mutex_t mutex;
} Bank;

BankAccount* find_account(Bank* bank, const char* account_number) {
    for (int i = 0; i < bank->account_count; i++) {
        if (strcmp(bank->accounts[i].account_number, account_number) == 0) {
            return &bank->accounts[i];
        }
    }
    return NULL;
}

bool open_account(Bank* bank, const char* account_number, double initial_balance) {
    pthread_mutex_lock(&bank->mutex);
    if (bank->account_count >= MAX_ACCOUNTS || find_account(bank, account_number) != NULL) {
        pthread_mutex_unlock(&bank->mutex);
        return false;
    }
    
    BankAccount* account = &bank->accounts[bank->account_count++];
    strncpy(account->account_number, account_number, sizeof(account->account_number) - 1);
    account->balance = initial_balance;
    account->is_open = true;
    pthread_mutex_init(&account->mutex, NULL);
    
    pthread_mutex_unlock(&bank->mutex);
    return true;
}

bool close_account(Bank* bank, const char* account_number) {
    pthread_mutex_lock(&bank->mutex);
    BankAccount* account = find_account(bank, account_number);
    if (account == NULL) {
        pthread_mutex_unlock(&bank->mutex);
        return false;
    }
    
    pthread_mutex_lock(&account->mutex);
    if (!account->is_open) {
        pthread_mutex_unlock(&account->mutex);
        pthread_mutex_unlock(&bank->mutex);
        return false;
    }
    account->is_open = false;
    pthread_mutex_unlock(&account->mutex);
    
    pthread_mutex_unlock(&bank->mutex);
    return true;
}

bool deposit(Bank* bank, const char* account_number, double amount) {
    pthread_mutex_lock(&bank->mutex);
    BankAccount* account = find_account(bank, account_number);
    if (account == NULL) {
        pthread_mutex_unlock(&bank->mutex);
        return false;
    }
    
    pthread_mutex_lock(&account->mutex);
    if (!account->is_open || amount <= 0) {
        pthread_mutex_unlock(&account->mutex);
        pthread_mutex_unlock(&bank->mutex);
        return false;
    }
    account->balance += amount;
    pthread_mutex_unlock(&account->mutex);
    
    pthread_mutex_unlock(&bank->mutex);
    return true;
}

bool withdraw(Bank* bank, const char* account_number, double amount) {
    pthread_mutex_lock(&bank->mutex);
    BankAccount* account = find_account(bank, account_number);
    if (account == NULL) {
        pthread_mutex_unlock(&bank->mutex);
        return false;
    }
    
    pthread_mutex_lock(&account->mutex);
    if (!account->is_open || amount <= 0 || amount > account->balance) {
        pthread_mutex_unlock(&account->mutex);
        pthread_mutex_unlock(&bank->mutex);
        return false;
    }
    account->balance -= amount;
    pthread_mutex_unlock(&account->mutex);
    
    pthread_mutex_unlock(&bank->mutex);
    return true;
}

void* transaction1(void* arg) {
    Bank* bank = (Bank*)arg;
    deposit(bank, "123", 200);
    withdraw(bank, "456", 100);
    return NULL;
}

void* transaction2(void* arg) {
    Bank* bank = (Bank*)arg;
    withdraw(bank, "123", 300);
    deposit(bank, "456", 150);
    return NULL;
}

int main() {
    Bank bank = {0};
    pthread_mutex_init(&bank.mutex, NULL);
    
    open_account(&bank, "123", 1000);
    open_account(&bank, "456", 500);
    
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, transaction1, &bank);
    pthread_create(&thread2, NULL, transaction2, &bank);
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    BankAccount* account123 = find_account(&bank, "123");
    BankAccount* account456 = find_account(&bank, "456");
    
    if (account123 && account456) {
        printf("Account 123 balance: %.2f\\n", account123->balance);
        printf("Account 456 balance: %.2f\\n", account456->balance);
    }
    
    return 0;
}
