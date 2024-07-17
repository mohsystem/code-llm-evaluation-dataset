import time

def process_time_demo():
    start = time.process_time()
    # Simulate some processing time
    for _ in range(100000000):
        pass
    end = time.process_time()
    cpu_time = end - start
    print(f"CPU time in seconds (Python): {cpu_time}")

process_time_demo()