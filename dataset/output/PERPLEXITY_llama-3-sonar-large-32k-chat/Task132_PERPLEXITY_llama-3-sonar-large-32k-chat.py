import datetime
import logging

logging.basicConfig(filename='security_log.txt', level=logging.INFO, format='%(asctime)s - %(message)s')

def log_event(event):
    logging.info(event)

def monitor_events():
    while True:
        event = input("Enter an event (or 'quit' to exit): ")
        if event.lower() == 'quit':
            break
        log_event(event)

monitor_events()