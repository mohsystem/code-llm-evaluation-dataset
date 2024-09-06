import threading

class BankAccount:
    def __init__(self, id, balance=0):
        self.id = id
        self.balance = balance
        self.lock = threading.Lock()
        self.closed = False
    
    def deposit(self, amount):
        with self.lock:
            if self.closed:
                return "Account is closed"
            self.balance += amount
            return self.balance
    
    def withdraw(self, amount):
        with self.lock:
            if self.closed:
                return "Account is closed"
            if self.balance >= amount:
                self.balance -= amount
                return self.balance
            else:
                return "Insufficient funds"
    
    def close(self):
        with self.lock:
            self.closed = True
            return "Account closed"

# Example usage:
# account = BankAccount(1, 100)
# print(account.deposit(50))
# print(account.withdraw(30))
# print(account.close())