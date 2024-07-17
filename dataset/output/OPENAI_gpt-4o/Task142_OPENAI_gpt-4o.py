def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

if __name__ == "__main__":
    import sys
    input = map(int, sys.stdin.read().split())
    a, b = input
    print(gcd(a, b))