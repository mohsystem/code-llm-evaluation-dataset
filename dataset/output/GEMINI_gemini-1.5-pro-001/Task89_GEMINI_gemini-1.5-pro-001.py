def compare_passwords(stored, entered):
    if len(stored) != len(entered):
        return False
    for i in range(len(stored)):
        if stored[i] != entered[i]:
            return False
    return True

try:
    with open("password.txt", "r") as f:
        stored_password = f.readline().strip()
except FileNotFoundError:
    print("Password file not found.")
    exit(1)

entered_password = input("Enter password: ")

if compare_passwords(stored_password, entered_password):
    print("Password matches.")
else:
    print("Incorrect password.")