
def check_password():
    try:
        with open("password.txt", "r") as file:
            stored_password = file.readline().strip()

        entered_password = input("Enter password: ")

        if len(stored_password) != len(entered_password):
            return False

        for stored_char, entered_char in zip(stored_password, entered_password):
            if stored_char != entered_char:
                return False

        return True

    except FileNotFoundError:
        print("Password file not found.")
        return False

if check_password():
    print("Password correct!")
else:
    print("Password incorrect!")
