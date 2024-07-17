import uuid

class Session:
    def __init__(self, session_id, username):
        self.session_id = session_id
        self.username = username

    def __str__(self):
        return f"Session(session_id='{self.session_id}', username='{self.username}')"

class SessionManager:
    def __init__(self):
        self.sessions = {}

    def create_session(self, username):
        session_id = str(uuid.uuid4())
        self.sessions[session_id] = Session(session_id, username)
        return session_id

    def get_session(self, session_id):
        return self.sessions.get(session_id)

    def invalidate_session(self, session_id):
        if session_id in self.sessions:
            del self.sessions[session_id]

if __name__ == "__main__":
    session_manager = SessionManager()

    # Create a session for user "john.doe"
    session_id = session_manager.create_session("john.doe")
    print(f"Created session: {session_id}")

    # Retrieve the session
    session = session_manager.get_session(session_id)
    print(f"Retrieved session: {session}")

    # Invalidate the session
    session_manager.invalidate_session(session_id)
    print(f"Invalidated session: {session_id}")