import random

def rand7():
    return random.randint(1, 7)

def rand10():
    while True:
        num = (rand7() - 1) * 7 + rand7()
        if num <= 40:
            return num % 10 + 1

def main(n):
    return [rand10() for _ in range(n)]

n = 1  # change this to test with different inputs
print(main(n))