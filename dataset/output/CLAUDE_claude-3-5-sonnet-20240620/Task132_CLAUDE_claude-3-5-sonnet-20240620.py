
import logging
from datetime import datetime

# Configure logging
logging.basicConfig(filename='security_events.log', level=logging.INFO,
                    format='%(asctime)s - %(levelname)s - %(message)s')

def log_event(event_type, description):
    logging.info(f"Event Type: {event_type}, Description: {description}")

def monitor_events():
    while True:
        event_type = input("Enter event type (or 'q' to quit): ")
        if event_type.lower() == 'q':
            break
        description = input("Enter event description: ")
        log_event(event_type, description)
        print("Event logged successfully.")

if __name__ == "__main__":
    print("Security Event Monitoring System")
    monitor_events()
    print("Monitoring ended. Check 'security_events.log' for recorded events.")
