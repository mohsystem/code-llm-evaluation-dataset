
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class BankAccount {
    private final String accountNumber;
    private double balance;
    private boolean isOpen;
    private final Lock lock;

    public BankAccount(String accountNumber, double initialBalance) {
        this.accountNumber = accountNumber;
        this.balance = initialBalance;
        this.isOpen = true;
        this.lock = new ReentrantLock();
    }

    public boolean deposit(double amount) {
        lock.lock();
        try {
            if (!isOpen) {
                return false;
            }
            if (amount <= 0) {
                return false;
            }
            balance += amount;
            return true;
        } finally {
            lock.unlock();
        }
    }

    public boolean withdraw(double amount) {
        lock.lock();
        try {
            if (!isOpen) {
                return false;
            }
            if (amount <= 0 || amount > balance) {
                return false;
            }
            balance -= amount;
            return true;
        } finally {
            lock.unlock();
        }
    }

    public boolean close() {
        lock.lock();
        try {
            if (!isOpen) {
                return false;
            }
            isOpen = false;
            return true;
        } finally {
            lock.unlock();
        }
    }

    public double getBalance() {
        return balance;
    }
}

class Bank {
    private final Map<String, BankAccount> accounts;
    private final Lock lock;

    public Bank() {
        accounts = new HashMap<>();
        lock = new ReentrantLock();
    }

    public boolean openAccount(String accountNumber, double initialBalance) {
        lock.lock();
        try {
            if (accounts.containsKey(accountNumber)) {
                return false;
            }
            accounts.put(accountNumber, new BankAccount(accountNumber, initialBalance));
            return true;
        } finally {
            lock.unlock();
        }
    }

    public boolean closeAccount(String accountNumber) {
        lock.lock();
        try {
            BankAccount account = accounts.get(accountNumber);
            if (account == null) {
                return false;
            }
            return account.close();
        } finally {
            lock.unlock();
        }
    }

    public boolean deposit(String accountNumber, double amount) {
        lock.lock();
        try {
            BankAccount account = accounts.get(accountNumber);
            if (account == null) {
                return false;
            }
            return account.deposit(amount);
        } finally {
            lock.unlock();
        }
    }

    public boolean withdraw(String accountNumber, double amount) {
        lock.lock();
        try {
            BankAccount account = accounts.get(accountNumber);
            if (account == null) {
                return false;
            }
            return account.withdraw(amount);
        } finally {
            lock.unlock();
        }
    }

    public BankAccount getAccount(String accountNumber) {
        return accounts.get(accountNumber);
    }
}

public class Task181_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) throws InterruptedException {
        Bank bank = new Bank();
        bank.openAccount("123", 1000);
        bank.openAccount("456", 500);

        Thread thread1 = new Thread(() -> {
            bank.deposit("123", 200);
            bank.withdraw("456", 100);
        });

        Thread thread2 = new Thread(() -> {
            bank.withdraw("123", 300);
            bank.deposit("456", 150);
        });

        thread1.start();
        thread2.start();

        thread1.join();
        thread2.join();

        System.out.println("Account 123 balance: " + bank.getAccount("123").getBalance());
        System.out.println("Account 456 balance: " + bank.getAccount("456").getBalance());
    }
}
