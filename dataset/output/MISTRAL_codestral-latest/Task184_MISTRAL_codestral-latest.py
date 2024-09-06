import random
import string

class Robot:
    def __init__(self):
        self.name = self.generate_name()

    def generate_name(self):
        letters = ''.join(random.choices(string.ascii_uppercase, k=2))
        digits = ''.join(random.choices(string.digits, k=3))
        return letters + digits

# Test
robots = [Robot() for _ in range(1000)]
assert len(set(robot.name for robot in robots)) == 1000