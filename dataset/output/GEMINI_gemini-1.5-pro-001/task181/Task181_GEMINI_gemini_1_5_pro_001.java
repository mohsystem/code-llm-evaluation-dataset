import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Task181_GEMINI_gemini_1_5_pro_001 {
    private double balance;
    private final Lock lock;
    private boolean isOpen;

    public Task181_GEMINI_gemini_1_5_pro_001(double initialBalance) {
        this.balance = initialBalance;
        this.lock = new ReentrantLock();
        this.isOpen = true;
    }

    public void open() {
        lock.lock();
        try {
            if (!isOpen) {
                isOpen = true;
            } else {
                throw new IllegalStateException("Account is already open.");
            }
        } finally {
            lock.unlock();
        }
    }

    public void close() {
        lock.lock();
        try {
            if (isOpen) {
                isOpen = false;
            } else {
                throw new IllegalStateException("Account is already closed.");
            }
        } finally {
            lock.unlock();
        }
    }

    public void deposit(double amount) {
        lock.lock();
        try {
            if (!isOpen) {
                throw new IllegalStateException("Cannot deposit to a closed account.");
            }
            if (amount <= 0) {
                throw new IllegalArgumentException("Deposit amount must be positive.");
            }
            balance += amount;
        } finally {
            lock.unlock();
        }
    }

    public void withdraw(double amount) {
        lock.lock();
        try {
            if (!isOpen) {
                throw new IllegalStateException("Cannot withdraw from a closed account.");
            }
            if (amount <= 0) {
                throw new IllegalArgumentException("Withdrawal amount must be positive.");
            }
            if (balance < amount) {
                throw new IllegalArgumentException("Insufficient funds.");
            }
            balance -= amount;
        } finally {
            lock.unlock();
        }
    }

    public double getBalance() {
        lock.lock();
        try {
            if (!isOpen) {
                throw new IllegalStateException("Cannot get balance of a closed account.");
            }
            return balance;
        } finally {
            lock.unlock();
        }
    }
}