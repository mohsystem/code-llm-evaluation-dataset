# Python
class Session:
    def __init__(self, user_id):
        self.user_id = user_id
        self.is_active = True

    def end_session(self):
        self.is_active = False

# Usage
user_session = Session(123)
print(user_session.is_active)  # True
user_session.end_session()
print(user_session.is_active)  # False