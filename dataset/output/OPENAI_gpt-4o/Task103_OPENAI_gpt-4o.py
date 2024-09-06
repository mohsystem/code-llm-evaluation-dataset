password = input("Enter your password: ")

if (len(password) >= 8 and 
    any(c.islower() for c in password) and 
    any(c.isupper() for c in password) and 
    any(c.isdigit() for c in password)):
    print("Password is strong.")
else:
    print("Password is weak.")