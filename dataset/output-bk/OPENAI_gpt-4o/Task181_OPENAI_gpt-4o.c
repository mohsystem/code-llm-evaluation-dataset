#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct {
    char account_id[50];
    double balance;
    int is_open;
    pthread_mutex_t lock;
} BankAccount;

typedef struct {
    BankAccount** accounts;
    int size;
    int capacity;
    pthread_mutex_t lock;
} Bank;

BankAccount* create_account(const char* account_id) {
    BankAccount* account = (BankAccount*)malloc(sizeof(BankAccount));
    strcpy(account->account_id, account_id);
    account->balance = 0;
    account->is_open = 1;
    pthread_mutex_init(&account->lock, NULL);
    return account;
}

Bank* create_bank(int capacity) {
    Bank* bank = (Bank*)malloc(sizeof(Bank));
    bank->accounts = (BankAccount**)malloc(capacity * sizeof(BankAccount*));
    bank->size = 0;
    bank->capacity = capacity;
    pthread_mutex_init(&bank->lock, NULL);
    return bank;
}

BankAccount* find_account(Bank* bank, const char* account_id) {
    for (int i = 0; i < bank->size; i++) {
        if (strcmp(bank->accounts[i]->account_id, account_id) == 0) {
            return bank->accounts[i];
        }
    }
    return NULL;
}

void open_account(Bank* bank, const char* account_id) {
    pthread_mutex_lock(&bank->lock);
    if (find_account(bank, account_id) != NULL) {
        pthread_mutex_unlock(&bank->lock);
        fprintf(stderr, "Account already exists
");
        return;
    }
    if (bank->size >= bank->capacity) {
        pthread_mutex_unlock(&bank->lock);
        fprintf(stderr, "Bank capacity full
");
        return;
    }
    bank->accounts[bank->size++] = create_account(account_id);
    pthread_mutex_unlock(&bank->lock);
}

void close_account(Bank* bank, const char* account_id) {
    pthread_mutex_lock(&bank->lock);
    BankAccount* account = find_account(bank, account_id);
    if (account == NULL) {
        pthread_mutex_unlock(&bank->lock);
        fprintf(stderr, "Account does not exist
");
        return;
    }
    pthread_mutex_lock(&account->lock);
    account->is_open = 0;
    pthread_mutex_unlock(&account->lock);
    pthread_mutex_unlock(&bank->lock);
}

void deposit(Bank* bank, const char* account_id, double amount) {
    pthread_mutex_lock(&bank->lock);
    BankAccount* account = find_account(bank, account_id);
    if (account == NULL) {
        pthread_mutex_unlock(&bank->lock);
        fprintf(stderr, "Account does not exist
");
        return;
    }
    pthread_mutex_lock(&account->lock);
    if (!account->is_open) {
        pthread_mutex_unlock(&account->lock);
        pthread_mutex_unlock(&bank->lock);
        fprintf(stderr, "Account is closed
");
        return;
    }
    account->balance += amount;
    pthread_mutex_unlock(&account->lock);
    pthread_mutex_unlock(&bank->lock);
}

void withdraw(Bank* bank, const char* account_id, double amount) {
    pthread_mutex_lock(&bank->lock);
    BankAccount* account = find_account(bank, account_id);
    if (account == NULL) {
        pthread_mutex_unlock(&bank->lock);
        fprintf(stderr, "Account does not exist
");
        return;
    }
    pthread_mutex_lock(&account->lock);
    if (!account->is_open) {
        pthread_mutex_unlock(&account->lock);
        pthread_mutex_unlock(&bank->lock);
        fprintf(stderr, "Account is closed
");
        return;
    }
    if (amount > account->balance) {
        pthread_mutex_unlock(&account->lock);
        pthread_mutex_unlock(&bank->lock);
        fprintf(stderr, "Insufficient funds
");
        return;
    }
    account->balance -= amount;
    pthread_mutex_unlock(&account->lock);
    pthread_mutex_unlock(&bank->lock);
}

double get_balance(Bank* bank, const char* account_id) {
    pthread_mutex_lock(&bank->lock);
    BankAccount* account = find_account(bank, account_id);
    if (account == NULL) {
        pthread_mutex_unlock(&bank->lock);
        fprintf(stderr, "Account does not exist
");
        exit(EXIT_FAILURE);
    }
    pthread_mutex_lock(&account->lock);
    if (!account->is_open) {
        pthread_mutex_unlock(&account->lock);
        pthread_mutex_unlock(&bank->lock);
        fprintf(stderr, "Account is closed
");
        exit(EXIT_FAILURE);
    }
    double balance = account->balance;
    pthread_mutex_unlock(&account->lock);
    pthread_mutex_unlock(&bank->lock);
    return balance;
}

// Note: Actual usage could involve creating threads and performing operations on bank accounts.