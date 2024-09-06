#include <stdio.h>
#include <pthread.h>

typedef struct {
    int id;
    int balance;
    pthread_mutex_t lock;
    int closed;
} BankAccount;

void init_account(BankAccount *account, int id, int initial_balance) {
    account->id = id;
    account->balance = initial_balance;
    pthread_mutex_init(&account->lock, NULL);
    account->closed = 0;
}

char* deposit(BankAccount *account, int amount) {
    pthread_mutex_lock(&account->lock);
    if (account->closed) {
        pthread_mutex_unlock(&account->lock);
        return "Account is closed";
    }
    account->balance += amount;
    pthread_mutex_unlock(&account->lock);
    return "Deposit successful";
}

char* withdraw(BankAccount *account, int amount) {
    pthread_mutex_lock(&account->lock);
    if (account->closed) {
        pthread_mutex_unlock(&account->lock);
        return "Account is closed";
    }
    if (account->balance >= amount) {
        account->balance -= amount;
        pthread_mutex_unlock(&account->lock);
        return "Withdrawal successful";
    } else {
        pthread_mutex_unlock(&account->lock);
        return "Insufficient funds";
    }
}

char* close_account(BankAccount *account) {
    pthread_mutex_lock(&account->lock);
    account->closed = 1;
    pthread_mutex_unlock(&account->lock);
    return "Account closed";
}

int main() {
    // Example usage
    BankAccount account;
    init_account(&account, 1, 100);
    printf("%s\n", deposit(&account, 50));
    printf("%s\n", withdraw(&account, 30));
    printf("%s\n", close_account(&account));

    return 0;
}