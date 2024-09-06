import datetime

class Session:
  def __init__(self, username):
    self.username = username
    self.session_id = None
    self.created_at = datetime.datetime.now()

  def create_session(self):
    # In a real application, generate a unique session ID
    self.session_id = "session_" + self.username

  def is_valid(self):
    # In a real application, check for session expiry
    return True

class SessionManager:
  def __init__(self):
    self.sessions = {}

  def create_session(self, username):
    session = Session(username)
    session.create_session()
    self.sessions[session.session_id] = session
    return session.session_id

  def get_session(self, session_id):
    return self.sessions.get(session_id)

  def delete_session(self, session_id):
    if session_id in self.sessions:
      del self.sessions[session_id]

if __name__ == "__main__":
  session_manager = SessionManager()

  # Create a new session
  session_id = session_manager.create_session("user1")
  print(f"Session created for user1 with ID: {session_id}")

  # Get the session
  session = session_manager.get_session(session_id)
  if session.is_valid():
    print(f"Session is valid for user: {session.username}")
  else:
    print("Session is not valid")

  # Delete the session
  session_manager.delete_session(session_id)
  print(f"Session with ID {session_id} deleted")