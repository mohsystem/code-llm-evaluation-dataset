
import socket
import threading
import time
import secrets
import base64

class Session:
    def __init__(self, username):
        self.id = self.generate_session_id()
        self.username = username
        self.creation_time = time.time()
        self.last_access_time = self.creation_time

    def generate_session_id(self):
        return base64.urlsafe_b64encode(secrets.token_bytes(16)).decode(\'utf-8\')

class SessionManager:
    def __init__(self):
        self.sessions = {}
        self.SESSION_TIMEOUT = 1800  # 30 minutes in seconds

    def create_session(self, username):
        session = Session(username)
        self.sessions[session.id] = session
        return session.id

    def validate_session(self, session_id):
        session = self.sessions.get(session_id)
        if session:
            current_time = time.time()
            if current_time - session.last_access_time <= self.SESSION_TIMEOUT:
                session.last_access_time = current_time
                return True
            else:
                self.terminate_session(session_id)
        return False

    def terminate_session(self, session_id):
        self.sessions.pop(session_id, None)

def handle_client(client_socket, session_manager):
    request = client_socket.recv(1024).decode(\'utf-8\').strip()
    parts = request.split(\' \')
    action = parts[0]

    if action == \'LOGIN\':
        username = parts[1]
        session_id = session_manager.create_session(username)
        response = f"Session created: {session_id}"
    elif action == \'VALIDATE\':
        session_id = parts[1]
        is_valid = session_manager.validate_session(session_id)
        response = f"Session valid: {is_valid}"
    elif action == \'LOGOUT\':
        session_id = parts[1]
        session_manager.terminate_session(session_id)
        response = "Session terminated"
    else:
        response = "Invalid action"

    client_socket.send(response.encode(\'utf-8\'))
    client_socket.close()

def main():
    session_manager = SessionManager()
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((\'0.0.0.0\', 8080))
    server.listen(5)

    print("Server started on port 8080")

    while True:
        client_sock, address = server.accept()
        client_handler = threading.Thread(
            target=handle_client,
            args=(client_sock, session_manager)
        )
        client_handler.start()

if __name__ == "__main__":
    main()
