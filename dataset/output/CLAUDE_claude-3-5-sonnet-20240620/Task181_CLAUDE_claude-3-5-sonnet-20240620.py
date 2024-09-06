
import threading
from typing import Dict

class BankAccount:
    def __init__(self, account_number: str, initial_balance: float = 0):
        self.account_number = account_number
        self.balance = initial_balance
        self.is_open = True
        self.lock = threading.Lock()

    def deposit(self, amount: float) -> bool:
        with self.lock:
            if not self.is_open:
                return False
            if amount <= 0:
                return False
            self.balance += amount
            return True

    def withdraw(self, amount: float) -> bool:
        with self.lock:
            if not self.is_open:
                return False
            if amount <= 0 or amount > self.balance:
                return False
            self.balance -= amount
            return True

    def close(self) -> bool:
        with self.lock:
            if not self.is_open:
                return False
            self.is_open = False
            return True

class Bank:
    def __init__(self):
        self.accounts: Dict[str, BankAccount] = {}
        self.lock = threading.Lock()

    def open_account(self, account_number: str, initial_balance: float = 0) -> bool:
        with self.lock:
            if account_number in self.accounts:
                return False
            self.accounts[account_number] = BankAccount(account_number, initial_balance)
            return True

    def close_account(self, account_number: str) -> bool:
        with self.lock:
            if account_number not in self.accounts:
                return False
            return self.accounts[account_number].close()

    def deposit(self, account_number: str, amount: float) -> bool:
        with self.lock:
            if account_number not in self.accounts:
                return False
            return self.accounts[account_number].deposit(amount)

    def withdraw(self, account_number: str, amount: float) -> bool:
        with self.lock:
            if account_number not in self.accounts:
                return False
            return self.accounts[account_number].withdraw(amount)

# Example usage
bank = Bank()
bank.open_account("123", 1000)
bank.open_account("456", 500)

def transaction1():
    bank.deposit("123", 200)
    bank.withdraw("456", 100)

def transaction2():
    bank.withdraw("123", 300)
    bank.deposit("456", 150)

thread1 = threading.Thread(target=transaction1)
thread2 = threading.Thread(target=transaction2)

thread1.start()
thread2.start()

thread1.join()
thread2.join()

print(f"Account 123 balance: {bank.accounts['123'].balance}")
print(f"Account 456 balance: {bank.accounts['456'].balance}")
