import random
import string

class Robot:
    used_names = set()

    def __init__(self):
        self.reset()

    def reset(self):
        self.name = self._generate_unique_name()

    def _generate_unique_name(self):
        while True:
            name = self._generate_random_name()
            if name not in self.used_names:
                self.used_names.add(name)
                return name

    def _generate_random_name(self):
        letters = ''.join(random.choices(string.ascii_uppercase, k=2))
        numbers = ''.join(random.choices(string.digits, k=3))
        return letters + numbers

# Example usage
r1 = Robot()
print(r1.name)
r1.reset()
print(r1.name)