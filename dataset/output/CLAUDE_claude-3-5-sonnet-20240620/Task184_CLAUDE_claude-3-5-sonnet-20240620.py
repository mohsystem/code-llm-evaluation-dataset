
import random
import string

class Robot:
    used_names = set()

    def __init__(self):
        self.name = self.generate_name()

    def reset(self):
        self.name = self.generate_name()

    def generate_name(self):
        while True:
            name = ''.join(random.choices(string.ascii_uppercase, k=2) + 
                           random.choices(string.digits, k=3))
            if name not in self.used_names:
                self.used_names.add(name)
                return name

# Example usage
robot = Robot()
print(robot.name)
robot.reset()
print(robot.name)
