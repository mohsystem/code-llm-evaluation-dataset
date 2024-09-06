import logging
import time

logging.basicConfig(filename='security.log', level=logging.INFO)

while True:
    # Simulate a security event
    logging.info('Security event detected at ' + time.ctime())
    time.sleep(1)