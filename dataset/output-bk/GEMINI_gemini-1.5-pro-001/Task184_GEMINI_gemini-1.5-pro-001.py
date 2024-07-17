import random
import string

class Robot:
    used_names = set()

    def __init__(self):
        self.name = self.generate_unique_name()

    def generate_unique_name(self):
        while True:
            new_name = ''.join(random.choices(string.ascii_uppercase, k=2) + random.choices(string.digits, k=3))
            if new_name not in Robot.used_names:
                Robot.used_names.add(new_name)
                return new_name

    def reset(self):
        old_name = self.name
        Robot.used_names.remove(old_name)
        self.name = self.generate_unique_name()