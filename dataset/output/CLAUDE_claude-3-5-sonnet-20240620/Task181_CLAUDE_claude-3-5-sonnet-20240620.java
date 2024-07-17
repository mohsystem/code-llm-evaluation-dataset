
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

    public Double getBalance() {
        lock.lock();
        try {
            if (!isOpen) return null;
            return balance;
        } finally {
            lock.unlock();
        }
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
            if (accounts.containsKey(accountNumber)) return false;
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
            if (account == null) return false;
            return account.close();
        } finally {
            lock.unlock();
        }
    }

    public boolean deposit(String accountNumber, double amount) {
        lock.lock();
        try {
            BankAccount account = accounts.get(accountNumber);
            if (account == null) return false;
            return account.deposit(amount);
        } finally {
            lock.unlock();
        }
    }

    public boolean withdraw(String accountNumber, double amount) {
        lock.lock();
        try {
            BankAccount account = accounts.get(accountNumber);
            if (account == null) return false;
            return account.withdraw(amount);
        } finally {
            lock.unlock();
        }
    }

    public Double getBalance(String accountNumber) {
        lock.lock();
        try {
            BankAccount account = accounts.get(accountNumber);
            if (account == null) return null;
            return account.getBalance();
        } finally {
            lock.unlock();
        }
    }
}

class AccountOperations implements Runnable {
    private final Bank bank;
    private final String accountNumber;

    public AccountOperations(Bank bank, String accountNumber) {
        this.bank = bank;
        this.accountNumber = accountNumber;
    }

    @Override
    public void run() {
        bank.deposit(accountNumber, 100);
        try {
            Thread.sleep(100);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        bank.withdraw(accountNumber, 50);
        try {
            Thread.sleep(100);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Account " + accountNumber + " balance: " + bank.getBalance(accountNumber));
    }
}

public class BankingSystem {
    public static void main(String[] args) throws InterruptedException {
        Bank bank = new Bank();
        bank.openAccount("123", 1000);
        bank.openAccount("456", 2000);

        Thread[] threads = new Thread[10];
        for (int i = 0; i < 5; i++) {
            threads[i * 2] = new Thread(new AccountOperations(bank, "123"));
            threads[i * 2 + 1] = new Thread(new AccountOperations(bank, "456"));
            threads[i * 2].start();
            threads[i * 2 + 1].start();
        }

        for (Thread thread : threads) {
            thread.join();
        }

        System.out.println("Final balances:");
        System.out.println("Account 123: " + bank.getBalance("123"));
        System.out.println("Account 456: " + bank.getBalance("456"));

        bank.closeAccount("123");
        System.out.println("Closed account 123 balance: " + bank.getBalance("123"));
    }
}
