def createPhoneNumber(numbers):
    return "({}) {}-{}".format("".join(map(str, numbers[:3])), "".join(map(str, numbers[3:6])), "".join(map(str, numbers[6:])))

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
print(createPhoneNumber(numbers))