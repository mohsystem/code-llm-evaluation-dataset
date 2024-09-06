import threading

class BankAccount:
    def __init__(self, initial_balance=0):
        self.balance = initial_balance
        self.lock = threading.Lock()
        self.is_open = True

    def open(self):
        with self.lock:
            if not self.is_open:
                self.is_open = True
            else:
                raise ValueError("Account is already open.")

    def close(self):
        with self.lock:
            if self.is_open:
                self.is_open = False
            else:
                raise ValueError("Account is already closed.")

    def deposit(self, amount):
        with self.lock:
            if not self.is_open:
                raise ValueError("Cannot deposit to a closed account.")
            if amount <= 0:
                raise ValueError("Deposit amount must be positive.")
            self.balance += amount

    def withdraw(self, amount):
        with self.lock:
            if not self.is_open:
                raise ValueError("Cannot withdraw from a closed account.")
            if amount <= 0:
                raise ValueError("Withdrawal amount must be positive.")
            if self.balance < amount:
                raise ValueError("Insufficient funds.")
            self.balance -= amount

    def get_balance(self):
        with self.lock:
            if not self.is_open:
                raise ValueError("Cannot get balance of a closed account.")
            return self.balance