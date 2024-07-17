import logging
import time

logging.basicConfig(filename='security.log', level=logging.INFO)

while True:
    # Simulate a security event
    event = "Security event detected at " + time.ctime()
    logging.info(event)
    time.sleep(5)