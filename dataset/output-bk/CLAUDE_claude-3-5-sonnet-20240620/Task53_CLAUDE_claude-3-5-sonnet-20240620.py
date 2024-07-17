
import uuid
import time
from typing import Dict, Optional

class Session:
    def __init__(self, session_id: str, user_id: str):
        self.session_id = session_id
        self.user_id = user_id
        self.creation_time = time.time()
        self.last_access_time = self.creation_time

class SessionManager:
    SESSION_TIMEOUT_SECONDS = 1800  # 30 minutes

    def __init__(self):
        self.sessions: Dict[str, Session] = {}

    def create_session(self, user_id: str) -> str:
        session_id = str(uuid.uuid4())
        self.sessions[session_id] = Session(session_id, user_id)
        return session_id

    def validate_session(self, session_id: str) -> bool:
        session = self.sessions.get(session_id)
        if session:
            current_time = time.time()
            if current_time - session.last_access_time < self.SESSION_TIMEOUT_SECONDS:
                session.last_access_time = current_time
                return True
            else:
                del self.sessions[session_id]
        return False

    def end_session(self, session_id: str) -> None:
        self.sessions.pop(session_id, None)

    def get_user_id(self, session_id: str) -> Optional[str]:
        session = self.sessions.get(session_id)
        return session.user_id if session else None

def main():
    manager = SessionManager()

    # Example usage
    user_id = "user123"
    session_id = manager.create_session(user_id)
    print(f"Session created: {session_id}")

    is_valid = manager.validate_session(session_id)
    print(f"Session valid: {is_valid}")

    retrieved_user_id = manager.get_user_id(session_id)
    print(f"Retrieved user ID: {retrieved_user_id}")

    manager.end_session(session_id)
    print("Session ended")

    is_valid = manager.validate_session(session_id)
    print(f"Session valid after ending: {is_valid}")

if __name__ == "__main__":
    main()
