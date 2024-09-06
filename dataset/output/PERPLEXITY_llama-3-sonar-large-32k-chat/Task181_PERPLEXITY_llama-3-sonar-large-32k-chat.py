code here:
import threading

class BankAccount:
    def __init__(self, initial_balance=0):
        self.balance = initial_balance
        self.lock = threading.Lock()
        self.closed = False

    def open_account(self):
        self.closed = False

    def close_account(self):
        self.closed = True

    def deposit(self, amount):
        if self.closed:
            return False
        with self.lock:
            self.balance += amount
        return True

    def withdraw(self, amount):
        if self.closed:
            return False
        with self.lock:
            if amount > self.balance:
                return False
            self.balance -= amount
        return True

    def get_balance(self):
        with self.lock:
            return self.balance