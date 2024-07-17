import random
import math

class Solution:
    def __init__(self, radius: float, x_center: float, y_center: float):
        self.radius = radius
        self.x_center = x_center
        self.y_center = y_center

    def randPoint(self):
        angle = random.uniform(0, 2 * math.pi)
        hyp = math.sqrt(random.uniform(0, 1)) * self.radius
        x = self.x_center + hyp * math.cos(angle)
        y = self.y_center + hyp * math.sin(angle)
        return [x, y]