
import random

def rand7():
    return random.randint(1, 7)

def rand10():
    while True:
        result = (rand7() - 1) * 7 + (rand7() - 1)
        if result < 40:
            return result % 10 + 1

def main():
    n = int(input("Enter the number of times to call rand10(): "))
    result = [rand10() for _ in range(n)]
    print(result)

if __name__ == "__main__":
    main()
