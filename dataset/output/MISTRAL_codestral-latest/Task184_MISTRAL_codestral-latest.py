import random
import string

class Robot:
    def __init__(self):
        self.name = self.generate_name()

    def generate_name(self):
        letters = random.choices(string.ascii_uppercase, k=2)
        digits = random.choices(string.digits, k=3)
        return ''.join(letters + digits)

# Test the Robot class
robots = set()
while len(robots) < 1000:  # Create 1000 unique robots
    robot = Robot()
    robots.add(robot.name)

print(len(robots) == 1000)  # Should print: True