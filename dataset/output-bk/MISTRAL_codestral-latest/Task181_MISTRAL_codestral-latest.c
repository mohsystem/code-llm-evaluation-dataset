#include <pthread.h>
#include <stdatomic.h>
#include <stdbool.h>

typedef struct {
    double balance;
    atomic_bool isOpen;
    pthread_mutex_t mtx;
} BankAccount;

BankAccount* createAccount(double initialBalance) {
    BankAccount* account = malloc(sizeof(BankAccount));
    account->balance = initialBalance;
    atomic_store(&account->isOpen, true);
    pthread_mutex_init(&account->mtx, NULL);
    return account;
}

bool deposit(BankAccount* account, double amount) {
    pthread_mutex_lock(&account->mtx);
    if (!atomic_load(&account->isOpen)) {
        pthread_mutex_unlock(&account->mtx);
        return false;
    }
    account->balance += amount;
    pthread_mutex_unlock(&account->mtx);
    return true;
}

bool withdraw(BankAccount* account, double amount) {
    pthread_mutex_lock(&account->mtx);
    if (!atomic_load(&account->isOpen) || account->balance < amount) {
        pthread_mutex_unlock(&account->mtx);
        return false;
    }
    account->balance -= amount;
    pthread_mutex_unlock(&account->mtx);
    return true;
}

bool closeAccount(BankAccount* account) {
    pthread_mutex_lock(&account->mtx);
    if (!atomic_load(&account->isOpen)) {
        pthread_mutex_unlock(&account->mtx);
        return false;
    }
    atomic_store(&account->isOpen, false);
    pthread_mutex_unlock(&account->mtx);
    return true;
}

void destroyAccount(BankAccount* account) {
    pthread_mutex_destroy(&account->mtx);
    free(account);
}