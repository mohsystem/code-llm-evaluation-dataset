def main():
    num = input("Enter a number: ")

    try:
        num = float(num)
        print("The square of the number is: ", num * num)
    except ValueError:
        print("Invalid input. Please enter a number.")

if __name__ == "__main__":
    main()