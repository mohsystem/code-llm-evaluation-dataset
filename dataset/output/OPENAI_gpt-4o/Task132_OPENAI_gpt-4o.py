import time

class SecurityEventLogger:
    def __init__(self):
        self.events = []

    def log_event(self, event):
        timestamp = time.strftime("%Y-%m-%d %H:%M:%S", time.gmtime())
        self.events.append(f"{timestamp} - {event}")

    def show_events(self):
        for event in self.events:
            print(event)

def main():
    logger = SecurityEventLogger()
    logger.log_event("User login")
    logger.log_event("File accessed")
    time.sleep(1)
    logger.log_event("User logout")
    logger.show_events()

if __name__ == "__main__":
    main()