
def create_phone_number(n):
    return "({}{}{}) {}{}{}-{}{}{}{}".format(*n)

if __name__ == "__main__":
    numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
    print(create_phone_number(numbers))
