
import time
import uuid

class Session:
    def __init__(self, user_id):
        self.session_id = str(uuid.uuid4())
        self.user_id = user_id
        self.creation_time = time.time()
        self.last_activity = self.creation_time

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
            if time.time() - session.last_activity > self.session_timeout:
                self.destroy_session(session_id)
                return None
            session.last_activity = time.time()
        return session

    def destroy_session(self, session_id):
        if session_id in self.sessions:
            del self.sessions[session_id]

    def cleanup_expired_sessions(self):
        current_time = time.time()
        expired_sessions = [
            session_id for session_id, session in self.sessions.items()
            if current_time - session.last_activity > self.session_timeout
        ]
        for session_id in expired_sessions:
            self.destroy_session(session_id)

def main():
    session_manager = SessionManager()

    # Create a session
    user_id = "user123"
    session_id = session_manager.create_session(user_id)
    print(f"Session created for user {user_id}: {session_id}")

    # Get session
    session = session_manager.get_session(session_id)
    if session:
        print(f"Session found for user {session.user_id}")
    else:
        print("Session not found")

    # Simulate session expiration
    time.sleep(2)
    session_manager.session_timeout = 1  # Set timeout to 1 second for demonstration
    session = session_manager.get_session(session_id)
    if session:
        print(f"Session still active for user {session.user_id}")
    else:
        print("Session expired")

    # Cleanup expired sessions
    session_manager.cleanup_expired_sessions()
    print("Expired sessions cleaned up")

if __name__ == "__main__":
    main()
