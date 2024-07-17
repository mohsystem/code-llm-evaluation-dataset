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

void openAccount(BankAccount* account) {
    if (account->closed) {
        printf("Account is already closed
");
        return;
    }
    account->closed = false;
}

void closeAccount(BankAccount* account) {
    if (account->closed) {
        printf("Account is already closed
");
        return;
    }
    account->closed = true;
}

void deposit(BankAccount* account, double amount) {
    if (account->closed) {
        printf("Account is closed
");
        return;
    }
    pthread_mutex_lock(&account->lock);
    account->balance += amount;
    pthread_mutex_unlock(&account->lock);
}

void withdraw(BankAccount* account, double amount) {
    if (account->closed) {
        printf("Account is closed
");
        return;
    }
    pthread_mutex_lock(&account->lock);
    if (amount > account->balance) {
        printf("Insufficient balance
");
        pthread_mutex_unlock(&account->lock);
        return;
    }
    account->balance -= amount;
    pthread_mutex_unlock(&account->lock);
}

double getBalance(BankAccount* account) {
    if (account->closed) {
        printf("Account is closed
");
        return 0.0;
    }
    pthread_mutex_lock(&account->lock);
    double balance = account->balance;
    pthread_mutex_unlock(&account->lock);
    return balance;
}