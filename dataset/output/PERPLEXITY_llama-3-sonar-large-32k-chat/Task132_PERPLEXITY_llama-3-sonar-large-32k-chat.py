import datetime

class SecurityEvent:
    def __init__(self, event_type, description):
        self.event_type = event_type
        self.description = description
        self.timestamp = datetime.datetime.now()

    def log_event(self):
        print(f"{self.timestamp} - {self.event_type}: {self.description}")

class SecurityMonitor:
    def __init__(self):
        self.event_log = []

    def log_event(self, event):
        self.event_log.append(event)
        event.log_event()

    def monitor_events(self):
        for event in self.event_log:
            print(f"Monitoring: {event.event_type} - {event.description}")

monitor = SecurityMonitor()
monitor.log_event(SecurityEvent("Login Attempt", "User attempted to login"))
monitor.log_event(SecurityEvent("File Access", "User accessed confidential file"))
monitor.monitor_events()