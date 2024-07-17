import threading

class BankAccount:
    def __init__(self, account_id):
        self.account_id = account_id
        self.balance = 0
        self.is_open = True
        self.lock = threading.Lock()

    def deposit(self, amount):
        with self.lock:
            if not self.is_open:
                raise ValueError("Account is closed")
            self.balance += amount

    def withdraw(self, amount):
        with self.lock:
            if not self.is_open:
                raise ValueError("Account is closed")
            if amount > self.balance:
                raise ValueError("Insufficient funds")
            self.balance -= amount

    def get_balance(self):
        with self.lock:
            if not self.is_open:
                raise ValueError("Account is closed")
            return self.balance

    def close_account(self):
        with self.lock:
            self.is_open = False

class Bank:
    def __init__(self):
        self.accounts = {}
        self.lock = threading.Lock()

    def open_account(self, account_id):
        with self.lock:
            if account_id in self.accounts:
                raise ValueError("Account already exists")
            self.accounts[account_id] = BankAccount(account_id)

    def close_account(self, account_id):
        with self.lock:
            if account_id not in self.accounts:
                raise ValueError("Account does not exist")
            self.accounts[account_id].close_account()

    def deposit(self, account_id, amount):
        with self.lock:
            if account_id not in self.accounts:
                raise ValueError("Account does not exist")
            self.accounts[account_id].deposit(amount)

    def withdraw(self, account_id, amount):
        with self.lock:
            if account_id not in self.accounts:
                raise ValueError("Account does not exist")
            self.accounts[account_id].withdraw(amount)

    def get_balance(self, account_id):
        with self.lock:
            if account_id not in self.accounts:
                raise ValueError("Account does not exist")
            return self.accounts[account_id].get_balance()

# Note: Actual usage could involve creating threads and performing operations on bank accounts.