import random
import string

class Robot:
    used_names = set()

    def __init__(self):
        self.name = self._generate_name()

    def reset(self):
        self.name = self._generate_name()

    def _generate_name(self):
        while True:
            name = ''.join(random.choices(string.ascii_uppercase, k=2)) + ''.join(random.choices(string.digits, k=3))
            if name not in Robot.used_names:
                Robot.used_names.add(name)
                return name

# Example of using the Robot class
robot = Robot()
print(robot.name)
robot.reset()
print(robot.name)