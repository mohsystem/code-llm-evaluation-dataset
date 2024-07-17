#include <stdio.h>
#include <pthread.h>

typedef struct {
    double balance;
    pthread_mutex_t lock;
    int is_open;
} BankAccount;

BankAccount* bank_account_create(double initial_balance) {
    BankAccount* account = (BankAccount*)malloc(sizeof(BankAccount));
    if (account == NULL) {
        return NULL;
    }
    account->balance = initial_balance;
    pthread_mutex_init(&account->lock, NULL);
    account->is_open = 1;
    return account;
}

void bank_account_destroy(BankAccount* account) {
    if (account != NULL) {
        pthread_mutex_destroy(&account->lock);
        free(account);
    }
}

int bank_account_open(BankAccount* account) {
    if (account == NULL) {
        return -1;
    }
    if (account->is_open) {
        return -1;
    }
    account->is_open = 1;
    return 0;
}

int bank_account_close(BankAccount* account) {
    if (account == NULL) {
        return -1;
    }
    if (!account->is_open) {
        return -1;
    }
    account->is_open = 0;
    return 0;
}

int bank_account_deposit(BankAccount* account, double amount) {
    if (account == NULL) {
        return -1;
    }
    if (!account->is_open) {
        return -1;
    }
    if (amount <= 0) {
        return -1;
    }
    pthread_mutex_lock(&account->lock);
    account->balance += amount;
    pthread_mutex_unlock(&account->lock);
    return 0;
}

int bank_account_withdraw(BankAccount* account, double amount) {
    if (account == NULL) {
        return -1;
    }
    if (!account->is_open) {
        return -1;
    }
    if (amount <= 0) {
        return -1;
    }
    pthread_mutex_lock(&account->lock);
    if (account->balance < amount) {
        pthread_mutex_unlock(&account->lock);
        return -1;
    }
    account->balance -= amount;
    pthread_mutex_unlock(&account->lock);
    return 0;
}