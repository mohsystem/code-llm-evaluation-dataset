import uuid

class UserSessionManager:
    def __init__(self):
        self.sessions = {}

    def createSession(self, username):
        sessionId = str(uuid.uuid4())
        self.sessions[sessionId] = username
        return sessionId

    def getSession(self, sessionId):
        return self.sessions.get(sessionId)

    def removeSession(self, sessionId):
        if sessionId in self.sessions:
            del self.sessions[sessionId]

if __name__ == "__main__":
    manager = UserSessionManager()
    sessionId = manager.createSession("JohnDoe")
    print(f"Session ID: {sessionId}")
    print(f"User: {manager.getSession(sessionId)}")
    manager.removeSession(sessionId)
    print(f"Session removed. User: {manager.getSession(sessionId)}")