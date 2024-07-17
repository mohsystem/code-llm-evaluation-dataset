
def check_password_strength(password):
    if len(password) < 8:
        return False

    has_uppercase = False
    has_lowercase = False
    has_digit = False

    for char in password:
        if char.isupper():
            has_uppercase = True
        elif char.islower():
            has_lowercase = True
        elif char.isdigit():
            has_digit = True

    return has_uppercase and has_lowercase and has_digit

def main():
    password = input("Enter a password: ")
    is_strong = check_password_strength(password)

    if is_strong:
        print("Strong password!")
    else:
        print("Weak password. Please try again.")

if __name__ == "__main__":
    main()
