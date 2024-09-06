import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class BankAccount {
    private final int id;
    private int balance;
    private final Lock lock = new ReentrantLock();
    private boolean closed = false;

    public BankAccount(int id, int initialBalance) {
        this.id = id;
        this.balance = initialBalance;
    }

    public String deposit(int amount) {
        lock.lock();
        try {
            if (closed) {
                return "Account is closed";
            }
            balance += amount;
            return "Balance: " + balance;
        } finally {
            lock.unlock();
        }
    }

    public String withdraw(int amount) {
        lock.lock();
        try {
            if (closed) {
                return "Account is closed";
            }
            if (balance >= amount) {
                balance -= amount;
                return "Balance: " + balance;
            } else {
                return "Insufficient funds";
            }
        } finally {
            lock.unlock();
        }
    }

    public String close() {
        lock.lock();
        try {
            closed = true;
            return "Account closed";
        } finally {
            lock.unlock();
        }
    }

    public static void main(String[] args) {
        // Example usage
        BankAccount account = new BankAccount(1, 100);
        System.out.println(account.deposit(50));
        System.out.println(account.withdraw(30));
        System.out.println(account.close());
    }
}