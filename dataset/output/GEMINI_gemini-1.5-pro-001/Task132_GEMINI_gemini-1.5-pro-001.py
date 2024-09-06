import time
import logging

logging.basicConfig(filename='security_events.log', level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')

def log_event(event_type, message):
  """Logs a security event with timestamp, type, and message."""
  logging.info(f"{event_type}: {message}")

def monitor_file_changes(file_path):
  """Monitors a file for changes and logs any detected modifications."""
  try:
    last_modified_time = os.path.getmtime(file_path)
    while True:
      current_modified_time = os.path.getmtime(file_path)
      if current_modified_time != last_modified_time:
        log_event("File Change Detected", f"File '{file_path}' has been modified.")
        last_modified_time = current_modified_time
      time.sleep(5)  # Check for changes every 5 seconds
  except Exception as e:
    log_event("Error", f"An error occurred while monitoring '{file_path}': {str(e)}")

if __name__ == "__main__":
  file_to_monitor = "/path/to/your/important_file.txt"  # Replace with the actual file path
  monitor_file_changes(file_to_monitor)