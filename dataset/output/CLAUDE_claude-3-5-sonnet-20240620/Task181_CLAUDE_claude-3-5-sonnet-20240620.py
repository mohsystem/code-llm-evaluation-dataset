
import threading
import time

class BankAccount:
    def __init__(self, account_number, initial_balance):
        self.account_number = account_number
        self.balance = initial_balance
        self.is_open = True
        self.lock = threading.Lock()

    def deposit(self, amount):
        with self.lock:
            if not self.is_open:
                return False
            self.balance += amount
            return True

    def withdraw(self, amount):
        with self.lock:
            if not self.is_open or self.balance < amount:
                return False
            self.balance -= amount
            return True

    def close(self):
        with self.lock:
            if not self.is_open:
                return False
            self.is_open = False
            return True

    def get_balance(self):
        with self.lock:
            if not self.is_open:
                return None
            return self.balance

class Bank:
    def __init__(self):
        self.accounts = {}
        self.lock = threading.Lock()

    def open_account(self, account_number, initial_balance):
        with self.lock:
            if account_number in self.accounts:
                return False
            self.accounts[account_number] = BankAccount(account_number, initial_balance)
            return True

    def close_account(self, account_number):
        with self.lock:
            if account_number not in self.accounts:
                return False
            return self.accounts[account_number].close()

    def deposit(self, account_number, amount):
        with self.lock:
            if account_number not in self.accounts:
                return False
            return self.accounts[account_number].deposit(amount)

    def withdraw(self, account_number, amount):
        with self.lock:
            if account_number not in self.accounts:
                return False
            return self.accounts[account_number].withdraw(amount)

    def get_balance(self, account_number):
        with self.lock:
            if account_number not in self.accounts:
                return None
            return self.accounts[account_number].get_balance()

def account_operations(bank, account_number):
    bank.deposit(account_number, 100)
    time.sleep(0.1)
    bank.withdraw(account_number, 50)
    time.sleep(0.1)
    print(f"Account {account_number} balance: {bank.get_balance(account_number)}")

if __name__ == "__main__":
    bank = Bank()
    bank.open_account("123", 1000)
    bank.open_account("456", 2000)

    threads = []
    for i in range(5):
        t1 = threading.Thread(target=account_operations, args=(bank, "123"))
        t2 = threading.Thread(target=account_operations, args=(bank, "456"))
        threads.extend([t1, t2])
        t1.start()
        t2.start()

    for t in threads:
        t.join()

    print("Final balances:")
    print(f"Account 123: {bank.get_balance(\'123\')}")
    print(f"Account 456: {bank.get_balance(\'456\')}")

    bank.close_account("123")
    print(f"Closed account 123 balance: {bank.get_balance(\'123\')}")
