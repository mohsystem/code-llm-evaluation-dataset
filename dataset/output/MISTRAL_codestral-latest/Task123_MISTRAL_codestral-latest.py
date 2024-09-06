# Python
class Session:
    def __init__(self, user_id):
        self.user_id = user_id
        self.is_active = True

    def end_session(self):
        self.is_active = False

# Example usage:
user_session = Session(123)
# ... user interacts with the system ...
user_session.end_session()