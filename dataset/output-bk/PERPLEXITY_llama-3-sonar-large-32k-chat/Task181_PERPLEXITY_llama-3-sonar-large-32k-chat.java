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
        if (this.closed) {
            throw new RuntimeException("Account is already closed");
        }
        this.closed = false;
    }

    public void closeAccount() {
        if (this.closed) {
            throw new RuntimeException("Account is already closed");
        }
        this.closed = true;
    }

    public void deposit(double amount) {
        if (this.closed) {
            throw new RuntimeException("Account is closed");
        }
        lock.lock();
        try {
            this.balance += amount;
        } finally {
            lock.unlock();
        }
    }

    public void withdraw(double amount) {
        if (this.closed) {
            throw new RuntimeException("Account is closed");
        }
        lock.lock();
        try {
            if (amount > this.balance) {
                throw new RuntimeException("Insufficient balance");
            }
            this.balance -= amount;
        } finally {
            lock.unlock();
        }
    }

    public double getBalance() {
        if (this.closed) {
            throw new RuntimeException("Account is closed");
        }
        lock.lock();
        try {
            return this.balance;
        } finally {
            lock.unlock();
        }
    }
}