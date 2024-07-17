class UserSession:
    def __init__(self, user_id):
        self.user_id = user_id
        self.active = True

    def end_session(self):
        self.active = False

# Example usage
session = UserSession(1)
print(session.user_id)
print(session.active)
session.end_session()
print(session.active)