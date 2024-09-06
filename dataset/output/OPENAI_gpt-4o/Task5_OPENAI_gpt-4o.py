def persistence(num):
    def multiply_digits(n):
        result = 1
        while n:
            result *= n % 10
            n //= 10
        return result

    count = 0
    while num >= 10:
        num = multiply_digits(num)
        count += 1
    return count

if __name__ == "__main__":
    print(persistence(39))  # 3
    print(persistence(999)) # 4
    print(persistence(4))   # 0