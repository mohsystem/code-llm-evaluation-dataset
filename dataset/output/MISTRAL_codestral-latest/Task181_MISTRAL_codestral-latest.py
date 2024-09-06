import threading

class BankAccount:
    def __init__(self, initial_balance):
        self.balance = initial_balance
        self.is_open = True
        self.lock = threading.Lock()

    def deposit(self, amount):
        with self.lock:
            if not self.is_open:
                raise RuntimeError("Account is closed")
            if amount < 0:
                raise ValueError("Deposit amount must be positive")
            self.balance += amount

    def withdraw(self, amount):
        with self.lock:
            if not self.is_open:
                raise RuntimeError("Account is closed")
            if amount < 0:
                raise ValueError("Withdraw amount must be positive")
            if self.balance < amount:
                return False
            self.balance -= amount
            return True

    def close(self):
        with self.lock:
            self.is_open = False