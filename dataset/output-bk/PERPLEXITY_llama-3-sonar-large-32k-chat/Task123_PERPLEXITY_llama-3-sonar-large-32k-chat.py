class UserSession:
    def __init__(self, username):
        self.username = username
        self.logged_in = False

    def login(self):
        self.logged_in = True
        print(f"{self.username} has logged in.")

    def logout(self):
        self.logged_in = False
        print(f"{self.username} has logged out.")

def main():
    sessions = {}
    while True:
        print("1. Create session")
        print("2. Login")
        print("3. Logout")
        print("4. Exit")
        choice = input("Choose an option: ")
        if choice == "1":
            username = input("Enter username: ")
            sessions[username] = UserSession(username)
            print(f"Session created for {username}.")
        elif choice == "2":
            username = input("Enter username: ")
            if username in sessions:
                sessions[username].login()
            else:
                print("Session not found.")
        elif choice == "3":
            username = input("Enter username: ")
            if username in sessions:
                sessions[username].logout()
            else:
                print("Session not found.")
        elif choice == "4":
            break
        else:
            print("Invalid option. Please try again.")

if __name__ == "__main__":
    main()