import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class BankAccount {
    private double balance;
    private boolean isOpen;
    private Lock lock;

    public BankAccount(double initialBalance) {
        this.balance = initialBalance;
        this.isOpen = true;
        this.lock = new ReentrantLock();
    }

    public boolean deposit(double amount) {
        lock.lock();
        try {
            if (!isOpen) return false;
            balance += amount;
            return true;
        } finally {
            lock.unlock();
        }
    }

    public boolean withdraw(double amount) {
        lock.lock();
        try {
            if (!isOpen || balance < amount) return false;
            balance -= amount;
            return true;
        } finally {
            lock.unlock();
        }
    }

    public boolean close() {
        lock.lock();
        try {
            if (!isOpen) return false;
            isOpen = false;
            return true;
        } finally {
            lock.unlock();
        }
    }
}

class Bank {
    private ConcurrentHashMap<String, BankAccount> accounts = new ConcurrentHashMap<>();

    public boolean openAccount(String accountId, double initialBalance) {
        return accounts.putIfAbsent(accountId, new BankAccount(initialBalance)) == null;
    }

    public boolean deposit(String accountId, double amount) {
        BankAccount account = accounts.get(accountId);
        return account != null && account.deposit(amount);
    }

    public boolean withdraw(String accountId, double amount) {
        BankAccount account = accounts.get(accountId);
        return account != null && account.withdraw(amount);
    }

    public boolean closeAccount(String accountId) {
        BankAccount account = accounts.get(accountId);
        return account != null && account.close();
    }
}