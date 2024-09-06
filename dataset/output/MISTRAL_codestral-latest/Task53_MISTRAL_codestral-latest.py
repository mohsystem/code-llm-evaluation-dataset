# Python
class Session:
    def __init__(self, user_id):
        self.user_id = user_id
        self.is_active = True

# Example usage:
user_sessions = {}
user_id = "123"
user_sessions[user_id] = Session(user_id)