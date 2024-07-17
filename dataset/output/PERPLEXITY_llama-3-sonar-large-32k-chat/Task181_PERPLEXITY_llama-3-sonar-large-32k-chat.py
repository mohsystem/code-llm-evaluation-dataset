import threading

class BankAccount:
    def __init__(self, initial_balance=0):
        self.balance = initial_balance
        self.lock = threading.Lock()
        self.closed = False

    def open_account(self):
        if self.closed:
            raise ValueError("Account is already closed")
        self.closed = False

    def close_account(self):
        if self.closed:
            raise ValueError("Account is already closed")
        self.closed = True

    def deposit(self, amount):
        if self.closed:
            raise ValueError("Account is closed")
        with self.lock:
            self.balance += amount

    def withdraw(self, amount):
        if self.closed:
            raise ValueError("Account is closed")
        with self.lock:
            if amount > self.balance:
                raise ValueError("Insufficient balance")
            self.balance -= amount

    def get_balance(self):
        if self.closed:
            raise ValueError("Account is closed")
        with self.lock:
            return self.balance