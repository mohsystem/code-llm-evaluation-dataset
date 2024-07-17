
import logging
from datetime import datetime

def setup_logger():
    logger = logging.getLogger(\'security_logger\')
    logger.setLevel(logging.INFO)
    file_handler = logging.FileHandler(\'security_events.log\')
    formatter = logging.Formatter(\'%(asctime)s - %(levelname)s - %(message)s\')
    file_handler.setFormatter(formatter)
    logger.addHandler(file_handler)
    return logger

def log_event(logger, event_type, description):
    logger.info(f"Event Type: {event_type}, Description: {description}")

def monitor_events(logger):
    while True:
        event_type = input("Enter event type (or \'q\' to quit): ")
        if event_type.lower() == \'q\':
            break
        description = input("Enter event description: ")
        log_event(logger, event_type, description)

if __name__ == "__main__":
    logger = setup_logger()
    print("Security Event Monitoring System")
    monitor_events(logger)
