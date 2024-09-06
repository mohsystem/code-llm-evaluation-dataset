#include <stdio.h>
#include <pthread.h>

typedef struct {
    double balance;
    pthread_mutex_t mutex;
    int is_open;
} BankAccount;

BankAccount* createBankAccount(double initial_balance) {
    BankAccount* account = (BankAccount*)malloc(sizeof(BankAccount));
    if (account == NULL) {
        return NULL;
    }
    account->balance = initial_balance;
    pthread_mutex_init(&account->mutex, NULL);
    account->is_open = 1;
    return account;
}

void destroyBankAccount(BankAccount* account) {
    if (account == NULL) {
        return;
    }
    pthread_mutex_destroy(&account->mutex);
    free(account);
}

void openAccount(BankAccount* account) {
    if (account == NULL) {
        return;
    }
    pthread_mutex_lock(&account->mutex);
    if (!account->is_open) {
        account->is_open = 1;
    } else {
        fprintf(stderr, "Error: Account is already open.\n");
    }
    pthread_mutex_unlock(&account->mutex);
}

void closeAccount(BankAccount* account) {
    if (account == NULL) {
        return;
    }
    pthread_mutex_lock(&account->mutex);
    if (account->is_open) {
        account->is_open = 0;
    } else {
        fprintf(stderr, "Error: Account is already closed.\n");
    }
    pthread_mutex_unlock(&account->mutex);
}

void deposit(BankAccount* account, double amount) {
    if (account == NULL) {
        return;
    }
    pthread_mutex_lock(&account->mutex);
    if (!account->is_open) {
        fprintf(stderr, "Error: Cannot deposit to a closed account.\n");
    } else if (amount <= 0) {
        fprintf(stderr, "Error: Deposit amount must be positive.\n");
    } else {
        account->balance += amount;
    }
    pthread_mutex_unlock(&account->mutex);
}

void withdraw(BankAccount* account, double amount) {
    if (account == NULL) {
        return;
    }
    pthread_mutex_lock(&account->mutex);
    if (!account->is_open) {
        fprintf(stderr, "Error: Cannot withdraw from a closed account.\n");
    } else if (amount <= 0) {
        fprintf(stderr, "Error: Withdrawal amount must be positive.\n");
    } else if (account->balance < amount) {
        fprintf(stderr, "Error: Insufficient funds.\n");
    } else {
        account->balance -= amount;
    }
    pthread_mutex_unlock(&account->mutex);
}

double getBalance(BankAccount* account) {
    if (account == NULL) {
        return 0;
    }
    double balance;
    pthread_mutex_lock(&account->mutex);
    if (!account->is_open) {
        fprintf(stderr, "Error: Cannot get balance of a closed account.\n");
        balance = 0;
    } else {
        balance = account->balance;
    }
    pthread_mutex_unlock(&account->mutex);
    return balance;
}