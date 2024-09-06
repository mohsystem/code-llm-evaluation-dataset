class UserSession:
    def __init__(self, session_id, user_id):
        self.session_id = session_id
        self.user_id = user_id

    def __str__(self):
        return f'Session ID: {self.session_id}, User ID: {self.user_id}'

session = UserSession("abc123", "user001")
print(session)