# Python
import random

def rand7():
    return random.randint(1, 7)

def rand10():
    while True:
        a = rand7()
        b = rand7()
        num = (a - 1) * 7 + b
        if num <= 40:
            return 1 + (num - 1) % 10