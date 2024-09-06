
import getpass

def authenticate():
    username = input("Enter username: ")
    password = getpass.getpass("Enter password: ")
    return username == "admin" and password == "password123"

def access_resource(resource):
    if resource == "1":
        print("Accessing confidential files...")
    elif resource == "2":
        print("Accessing financial records...")
    elif resource == "3":
        print("Accessing employee database...")
    else:
        print("Invalid resource selection.")

def main():
    if authenticate():
        print("Authentication successful.")
        while True:
            print("\\nAvailable resources:")
            print("1. Confidential files")
            print("2. Financial records")
            print("3. Employee database")
            print("4. Exit")
            choice = input("Enter resource number to access (or 4 to exit): ")
            if choice == "4":
                break
            access_resource(choice)
    else:
        print("Authentication failed. Access denied.")

if __name__ == "__main__":
    main()
