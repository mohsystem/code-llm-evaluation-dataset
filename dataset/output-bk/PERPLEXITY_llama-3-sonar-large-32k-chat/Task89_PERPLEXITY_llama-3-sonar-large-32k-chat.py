def main():
    input_password = input("Enter password: ")

    with open("password.txt", "r") as file:
        stored_password = file.read().strip()

    is_valid = True
    if len(input_password) != len(stored_password):
        is_valid = False
    else:
        for i in range(len(input_password)):
            if input_password[i] != stored_password[i]:
                is_valid = False
                break

    if is_valid:
        print("Password is valid")
    else:
        print("Password is invalid")

if __name__ == "__main__":
    main()