class SessionManager:
    def __init__(self):
        self.sessions = {}

    def create_user_session(self, user_id, session_id):
        self.sessions[user_id] = session_id

    def delete_user_session(self, user_id):
        if user_id in self.sessions:
            del self.sessions[user_id]

    def get_user_session_id(self, user_id):
        return self.sessions.get(user_id)

if __name__ == "__main__":
    session_manager = SessionManager()
    session_manager.create_user_session("user1", "session1")
    session_manager.create_user_session("user2", "session2")
    print(session_manager.get_user_session_id("user1"))  # prints "session1"
    session_manager.delete_user_session("user1")
    print(session_manager.get_user_session_id("user1"))  # prints None