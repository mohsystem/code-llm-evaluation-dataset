def authenticate(username, password):
    user_data = {
        "user1": "password123",
        "john_doe": "securepassword",
    }
    if username in user_data and user_data[username] == password:
        print("Authentication successful. Welcome, {}!".format(username))
    else:
        print("Authentication failed. Invalid username or password.")

if __name__ == "__main__":
    username = input("Username: ")
    password = input("Password: ")
    authenticate(username, password)