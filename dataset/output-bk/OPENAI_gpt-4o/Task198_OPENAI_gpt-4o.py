import random
def rand7():
    return random.randint(1, 7)

def rand10():
    while True:
        x = (rand7() - 1) * 7 + rand7()
        if x <= 40:
            return 1 + (x - 1) % 10

n = 3
result = [rand10() for _ in range(n)]
print(result)