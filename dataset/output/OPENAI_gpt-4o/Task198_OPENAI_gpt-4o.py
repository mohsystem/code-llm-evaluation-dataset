import random

def rand7():
    return random.randint(1, 7)

def rand10():
    while True:
        num = (rand7() - 1) * 7 + rand7()
        if num <= 40:
            return (num - 1) % 10 + 1

n = int(input())
results = [rand10() for _ in range(n)]
print(results)