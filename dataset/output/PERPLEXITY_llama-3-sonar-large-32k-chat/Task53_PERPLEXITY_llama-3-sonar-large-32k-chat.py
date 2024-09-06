class SessionManager:
    def __init__(self):
        self.sessions = {}

    def create_session(self, user_id):
        session_id = self.generate_session_id()
        self.sessions[session_id] = user_id
        return session_id

    def generate_session_id(self):
        # implement your own session id generation logic
        return "session_id_" + str(len(self.sessions) + 1)

    def get_user_id(self, session_id):
        return self.sessions.get(session_id)

    def invalidate_session(self, session_id):
        if session_id in self.sessions:
            del self.sessions[session_id]

session_manager = SessionManager()

# create a session
session_id = session_manager.create_session("user1")
print("Session ID:", session_id)

# get user id from session id
user_id = session_manager.get_user_id(session_id)
print("User ID:", user_id)

# invalidate session
session_manager.invalidate_session(session_id)
print("Session invalidated")