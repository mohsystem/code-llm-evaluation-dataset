import threading

class BankAccount:
    def __init__(self, initial_balance=0):
        self.balance = initial_balance
        self.lock = threading.Lock()
        self.is_open = True

    def open(self):
        if self.is_open:
            raise ValueError("Account already open")
        self.is_open = True

    def close(self):
        if not self.is_open:
            raise ValueError("Account already closed")
        self.is_open = False

    def deposit(self, amount):
        if not self.is_open:
            raise ValueError("Account closed")
        if amount <= 0:
            raise ValueError("Deposit amount must be positive")
        with self.lock:
            self.balance += amount

    def withdraw(self, amount):
        if not self.is_open:
            raise ValueError("Account closed")
        if amount <= 0:
            raise ValueError("Withdrawal amount must be positive")
        with self.lock:
            if self.balance < amount:
                raise ValueError("Insufficient funds")
            self.balance -= amount