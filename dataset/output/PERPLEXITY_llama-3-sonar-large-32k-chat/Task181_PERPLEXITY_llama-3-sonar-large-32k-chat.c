code here:
// Note: C does not have built-in support for threads or locks. This implementation uses POSIX threads and mutexes.
#include <pthread.h>

typedef struct {
    double balance;
    bool closed;
    pthread_mutex_t lock;
} BankAccount;

BankAccount* bankAccountCreate(double initialBalance) {
    BankAccount* account = malloc(sizeof(BankAccount));
    account->balance = initialBalance;
    account->closed = false;
    pthread_mutex_init(&account->lock, NULL);
    return account;
}

void bankAccountOpen(BankAccount* account) {
    account->closed = false;
}

void bankAccountClose(BankAccount* account) {
    account->closed = true;
}

bool bankAccountDeposit(BankAccount* account, double amount) {
    if (account->closed) {
        return false;
    }
    pthread_mutex_lock(&account->lock);
    account->balance += amount;
    pthread_mutex_unlock(&account->lock);
    return true;
}

bool bankAccountWithdraw(BankAccount* account, double amount) {
    if (account->closed) {
        return false;
    }
    pthread_mutex_lock(&account->lock);
    if (amount > account->balance) {
        pthread_mutex_unlock(&account->lock);
        return false;
    }
    account->balance -= amount;
    pthread_mutex_unlock(&account->lock);
    return true;
}

double bankAccountGetBalance(BankAccount* account) {
    pthread_mutex_lock(&account->lock);
    double balance = account->balance;
    pthread_mutex_unlock(&account->lock);
    return balance;
}