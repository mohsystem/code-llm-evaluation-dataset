import logging

# Configure logging
logging.basicConfig(filename='security.log', level=logging.INFO,
                    format='%(asctime)s - %(levelname)s - %(message)s')

def log_event(event):
    logging.info(event)

if __name__ == "__main__":
    log_event("User login detected.")
    log_event("Unauthorized access attempt detected.")
    log_event("File integrity check failed.")