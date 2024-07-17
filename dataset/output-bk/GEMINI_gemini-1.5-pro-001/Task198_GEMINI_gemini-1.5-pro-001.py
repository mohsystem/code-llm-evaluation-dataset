import random
class Solution:
    def rand10(self):
        while True:
            row = rand7()
            col = rand7()
            idx = col + (row - 1) * 7
            if idx <= 40:
                return 1 + (idx - 1) % 10