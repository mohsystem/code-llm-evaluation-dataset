database = {}

def register_user(name, email, password):
    database[email] = name + ":" + password
    print("User information stored in database:")
    print("Email:", email)
    print("Name:", name)
    print("Password:", password)

def main():
    print("Welcome to the User Registration System!")
    name = input("Enter your name: ")
    email = input("Enter your email: ")
    password = input("Enter your password: ")

    register_user(name, email, password)

    print("User registered successfully!")

if __name__ == "__main__":
    main()