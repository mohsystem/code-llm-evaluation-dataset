def main():
    with open("password.txt", "r") as file:
        stored_password = file.read().strip()

    entered_password = input("Enter your password: ")

    is_match = len(stored_password) == len(entered_password)

    for sp, ep in zip(stored_password, entered_password):
        is_match &= sp == ep

    if is_match:
        print("Password match")
    else:
        print("Password does not match")

if __name__ == "__main__":
    main()