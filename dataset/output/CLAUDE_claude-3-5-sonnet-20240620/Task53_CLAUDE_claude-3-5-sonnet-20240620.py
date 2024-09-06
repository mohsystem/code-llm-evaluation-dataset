
import time
import uuid

class Session:
    def __init__(self, user_id):
        self.session_id = str(uuid.uuid4())
        self.user_id = user_id
        self.created_at = time.time()
        self.last_accessed = time.time()

class SessionManager:
    def __init__(self, session_timeout=1800):  # 30 minutes default timeout
        self.sessions = {}
        self.session_timeout = session_timeout

    def create_session(self, user_id):
        session = Session(user_id)
        self.sessions[session.session_id] = session
        return session.session_id

    def get_session(self, session_id):
        session = self.sessions.get(session_id)
        if session:
            if time.time() - session.last_accessed > self.session_timeout:
                self.destroy_session(session_id)
                return None
            session.last_accessed = time.time()
        return session

    def destroy_session(self, session_id):
        if session_id in self.sessions:
            del self.sessions[session_id]

    def cleanup_expired_sessions(self):
        current_time = time.time()
        expired_sessions = [
            session_id for session_id, session in self.sessions.items()
            if current_time - session.last_accessed > self.session_timeout
        ]
        for session_id in expired_sessions:
            self.destroy_session(session_id)

# Example usage
if __name__ == "__main__":
    session_manager = SessionManager()

    # Create a new session
    user_id = "user123"
    session_id = session_manager.create_session(user_id)
    print(f"New session created: {session_id}")

    # Get session
    session = session_manager.get_session(session_id)
    if session:
        print(f"Session found for user: {session.user_id}")
    else:
        print("Session not found")

    # Cleanup expired sessions
    session_manager.cleanup_expired_sessions()

    # Destroy session
    session_manager.destroy_session(session_id)
    print("Session destroyed")
