def check_password(password):
    admin_password = "admin123"
    if password == admin_password:
        return "Password is valid"
    else:
        return "Password is invalid"

password_input = input("Enter the admin password: ")
print(check_password(password_input))