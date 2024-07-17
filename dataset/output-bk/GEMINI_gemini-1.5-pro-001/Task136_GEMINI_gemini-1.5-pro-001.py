def authenticate(username, password):
    """
    Checks if the provided username and password match a predefined set.

    Args:
        username: The username to check.
        password: The password to check.

    Returns:
        True if the username and password match, False otherwise.
    """
    valid_username = "user"
    valid_password = "password"
    if username == valid_username and password == valid_password:
        return True
    else:
        return False

# Get user credentials
username = input("Username: ")
password = input("Password: ")

# Authenticate user
if authenticate(username, password):
    print("Authentication successful. Welcome!")
else:
    print("Authentication failed. Invalid username or password.")