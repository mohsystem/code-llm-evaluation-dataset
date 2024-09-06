import random
import string

class Robot:
    def __init__(self):
        self.name = self.generate_name()

    def generate_name(self):
        while True:
            name = ''.join(random.choice(string.ascii_uppercase) for _ in range(2)) + str(random.randint(0, 999)).zfill(3)
            if not hasattr(self, 'used_names') or name not in self.used_names:
                if not hasattr(self, 'used_names'):
                    self.used_names = set()
                self.used_names.add(name)
                return name

    def reset(self):
        self.name = self.generate_name()