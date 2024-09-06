import time

class UserSession:
    def __init__(self, user_id):
        self.user_id = user_id
        self.start_time = time.time()

    def get_duration(self):
        return time.time() - self.start_time

if __name__ == "__main__":
    session = UserSession('User1')
    time.sleep(2)
    print(f'Python: Session duration for {session.user_id}: {session.get_duration()} seconds')