import threading

class BankAccount:
    def __init__(self, initial_balance):
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

class Bank:
    def __init__(self):
        self.accounts = {}

    def open_account(self, account_id, initial_balance):
        if account_id in self.accounts:
            return False
        self.accounts[account_id] = BankAccount(initial_balance)
        return True

    def deposit(self, account_id, amount):
        account = self.accounts.get(account_id)
        return account is not None and account.deposit(amount)

    def withdraw(self, account_id, amount):
        account = self.accounts.get(account_id)
        return account is not None and account.withdraw(amount)

    def close_account(self, account_id):
        account = self.accounts.get(account_id)
        return account is not None and account.close()