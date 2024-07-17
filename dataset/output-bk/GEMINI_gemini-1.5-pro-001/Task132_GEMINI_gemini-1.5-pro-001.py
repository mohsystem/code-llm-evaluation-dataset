import time
from datetime import datetime

def log_event(event_type, description):
  """Logs a security event with timestamp, type, and description."""
  timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
  log_entry = f"{timestamp} - [{event_type}] - {description}"
  with open("security_log.txt", "a") as log_file:
    log_file.write(log_entry + "
")
  print(log_entry)

def monitor_filesystem(directory):
  """Monitors a directory for file changes."""
  # Placeholder - Implement file monitoring logic here
  # This could involve checking for file modifications, additions, or deletions
  # You can use libraries like watchdog for more advanced file monitoring.
  while True:
    # Simulate checking for changes every 5 seconds
    time.sleep(5)
    log_event("File System", f"Monitoring directory: {directory}")

if __name__ == "__main__":
  log_event("System", "Security monitoring started.")
  monitor_filesystem("/path/to/monitor")