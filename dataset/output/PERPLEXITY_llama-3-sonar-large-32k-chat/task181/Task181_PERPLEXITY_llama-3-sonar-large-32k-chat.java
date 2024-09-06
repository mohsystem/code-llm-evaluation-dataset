code here:
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class BankAccount {
    private double balance;
    private boolean closed;
    private final Lock lock = new ReentrantLock();

    public BankAccount(double initialBalance) {
        this.balance = initialBalance;
        this.closed = false;
    }

    public void openAccount() {
        this.closed = false;
    }

    public void closeAccount() {
        this.closed = true;
    }

    public boolean deposit(double amount) {
        if (this.closed) {
            return false;
        }
        lock.lock();
        try {
            this.balance += amount;
            return true;
        } finally {
            lock.unlock();
        }
    }

    public boolean withdraw(double amount) {
        if (this.closed) {
            return false;
        }
        lock.lock();
        try {
            if (amount > this.balance) {
                return false;
            }
            this.balance -= amount;
            return true;
        } finally {
            lock.unlock();
        }
    }

    public double getBalance() {
        lock.lock();
        try {
            return this.balance;
        } finally {
            lock.unlock();
        }
    }
}