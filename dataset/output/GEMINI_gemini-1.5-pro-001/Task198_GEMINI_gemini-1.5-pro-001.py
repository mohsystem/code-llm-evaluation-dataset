import random
class Solution:
    def rand10(self):
        while True:
            num = (rand7() - 1) * 7 + rand7()  # Generate a number between 1 and 49
            if num <= 40:
                return (num - 1) % 10 + 1  # Map to 1-10

def rand7():
    return random.randint(1, 7)