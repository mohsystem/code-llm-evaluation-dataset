import java.util.concurrent.locks.ReentrantLock;

class BankAccount {
    private double balance;
    private boolean isOpen;
    private final ReentrantLock lock = new ReentrantLock();

    public BankAccount(double initialBalance) {
        this.balance = initialBalance;
        this.isOpen = true;
    }

    public void deposit(double amount) {
        lock.lock();
        try {
            if (!isOpen) {
                throw new IllegalStateException("Account is closed");
            }
            if (amount < 0) {
                throw new IllegalArgumentException("Deposit amount must be positive");
            }
            balance += amount;
        } finally {
            lock.unlock();
        }
    }

    public boolean withdraw(double amount) {
        lock.lock();
        try {
            if (!isOpen) {
                throw new IllegalStateException("Account is closed");
            }
            if (amount < 0) {
                throw new IllegalArgumentException("Withdraw amount must be positive");
            }
            if (balance < amount) {
                return false;
            }
            balance -= amount;
            return true;
        } finally {
            lock.unlock();
        }
    }

    public void close() {
        lock.lock();
        try {
            isOpen = false;
        } finally {
            lock.unlock();
        }
    }
}