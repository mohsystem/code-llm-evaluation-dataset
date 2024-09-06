// C does not have built-in support for threading, so a more complex solution is required.
// This example uses POSIX threads (pthreads) and mutexes.

#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double balance;
    bool isOpen;
    pthread_mutex_t lock;
} BankAccount;

void BankAccount_init(BankAccount *account, double initialBalance) {
    account->balance = initialBalance;
    account->isOpen = true;
    pthread_mutex_init(&account->lock, NULL);
}

void BankAccount_deposit(BankAccount *account, double amount) {
    pthread_mutex_lock(&account->lock);
    if (!account->isOpen) {
        fprintf(stderr, "Account is closed\n");
        exit(EXIT_FAILURE);
    }
    if (amount < 0) {
        fprintf(stderr, "Deposit amount must be positive\n");
        exit(EXIT_FAILURE);
    }
    account->balance += amount;
    pthread_mutex_unlock(&account->lock);
}

bool BankAccount_withdraw(BankAccount *account, double amount) {
    pthread_mutex_lock(&account->lock);
    if (!account->isOpen) {
        fprintf(stderr, "Account is closed\n");
        exit(EXIT_FAILURE);
    }
    if (amount < 0) {
        fprintf(stderr, "Withdraw amount must be positive\n");
        exit(EXIT_FAILURE);
    }
    if (account->balance < amount) {
        pthread_mutex_unlock(&account->lock);
        return false;
    }
    account->balance -= amount;
    pthread_mutex_unlock(&account->lock);
    return true;
}

void BankAccount_close(BankAccount *account) {
    pthread_mutex_lock(&account->lock);
    account->isOpen = false;
    pthread_mutex_unlock(&account->lock);
}