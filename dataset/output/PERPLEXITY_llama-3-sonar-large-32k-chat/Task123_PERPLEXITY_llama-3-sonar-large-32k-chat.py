class SessionManager:
    def __init__(self):
        self.sessions = {}

    def create_session(self, user_id, username):
        self.sessions[user_id] = username
        print(f"Session created for user {username} with ID {user_id}")

    def get_username(self, user_id):
        return self.sessions.get(user_id)

    def delete_session(self, user_id):
        if user_id in self.sessions:
            del self.sessions[user_id]
            print(f"Session deleted for user ID {user_id}")
        else:
            print(f"No session found for user ID {user_id}")

# Example usage
manager = SessionManager()
manager.create_session(1, "John")
manager.create_session(2, "Alice")
print(manager.get_username(1))  # Output: John
manager.delete_session(2)