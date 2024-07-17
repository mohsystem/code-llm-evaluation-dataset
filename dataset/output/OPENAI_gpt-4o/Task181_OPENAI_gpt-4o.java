import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.locks.ReentrantLock;

class BankAccount {
    private String accountId;
    private double balance;
    private boolean isOpen;
    private ReentrantLock lock;

    public BankAccount(String accountId) {
        this.accountId = accountId;
        this.balance = 0;
        this.isOpen = true;
        this.lock = new ReentrantLock();
    }

    public void deposit(double amount) {
        lock.lock();
        try {
            if (!isOpen) throw new IllegalStateException("Account is closed");
            balance += amount;
        } finally {
            lock.unlock();
        }
    }

    public void withdraw(double amount) {
        lock.lock();
        try {
            if (!isOpen) throw new IllegalStateException("Account is closed");
            if (amount > balance) throw new IllegalArgumentException("Insufficient funds");
            balance -= amount;
        } finally {
            lock.unlock();
        }
    }

    public double getBalance() {
        lock.lock();
        try {
            if (!isOpen) throw new IllegalStateException("Account is closed");
            return balance;
        } finally {
            lock.unlock();
        }
    }

    public void closeAccount() {
        lock.lock();
        try {
            isOpen = false;
        } finally {
            lock.unlock();
        }
    }
}

class Bank {
    private ConcurrentHashMap<String, BankAccount> accounts;
    private ReentrantLock lock;

    public Bank() {
        accounts = new ConcurrentHashMap<>();
        lock = new ReentrantLock();
    }

    public void openAccount(String accountId) {
        lock.lock();
        try {
            if (accounts.containsKey(accountId)) throw new IllegalStateException("Account already exists");
            accounts.put(accountId, new BankAccount(accountId));
        } finally {
            lock.unlock();
        }
    }

    public void closeAccount(String accountId) {
        lock.lock();
        try {
            if (!accounts.containsKey(accountId)) throw new IllegalStateException("Account does not exist");
            accounts.get(accountId).closeAccount();
        } finally {
            lock.unlock();
        }
    }

    public void deposit(String accountId, double amount) {
        lock.lock();
        try {
            if (!accounts.containsKey(accountId)) throw new IllegalStateException("Account does not exist");
            accounts.get(accountId).deposit(amount);
        } finally {
            lock.unlock();
        }
    }

    public void withdraw(String accountId, double amount) {
        lock.lock();
        try {
            if (!accounts.containsKey(accountId)) throw new IllegalStateException("Account does not exist");
            accounts.get(accountId).withdraw(amount);
        } finally {
            lock.unlock();
        }
    }

    public double getBalance(String accountId) {
        lock.lock();
        try {
            if (!accounts.containsKey(accountId)) throw new IllegalStateException("Account does not exist");
            return accounts.get(accountId).getBalance();
        } finally {
            lock.unlock();
        }
    }
}

// Note: Actual usage could involve creating threads and performing operations on bank accounts.