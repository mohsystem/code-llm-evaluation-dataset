# Python Code
def is_narcissistic(number):
    number_of_digits = len(str(number))
    sum_of_powers = sum(int(digit) ** number_of_digits for digit in str(number))
    return sum_of_powers == number

if __name__ == "__main__":
    num = 153  # example number
    print(is_narcissistic(num))