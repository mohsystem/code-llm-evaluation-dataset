from datetime import datetime

class Session:
  def __init__(self, username):
    self.username = username
    self.login_time = datetime.now()

  def get_session_data(self):
    return f"Username: {self.username}, Login Time: {self.login_time}"

sessions = {}

def create_session(username):
  sessions[username] = Session(username)
  print(f"Session created for {username}")

def get_session(username):
  if username in sessions:
    print(sessions[username].get_session_data())
  else:
    print(f"Session not found for {username}")

def delete_session(username):
  if username in sessions:
    del sessions[username]
    print(f"Session deleted for {username}")
  else:
    print(f"Session not found for {username}")

while True:
  action = input("Enter action (create/get/delete/exit): ")
  if action == "exit":
    break
  username = input("Enter username: ")
  if action == "create":
    create_session(username)
  elif action == "get":
    get_session(username)
  elif action == "delete":
    delete_session(username)
  else:
    print("Invalid action")