import threading
from collections import deque

class H2O:
    def __init__(self):
        self.hydrogen_queue = deque()
        self.oxygen_queue = deque()
        self.barrier = threading.Semaphore(2)

    def hydrogen(self, releaseHydrogen):
        with self.barrier:
            self.hydrogen_queue.append(releaseHydrogen)
            self.check_molecule()

    def oxygen(self, releaseOxygen):
        with self.barrier:
            self.oxygen_queue.append(releaseOxygen)
            self.check_molecule()

    def check_molecule(self):
        if len(self.hydrogen_queue) >= 2 and len(self.oxygen_queue) >= 1:
            self.hydrogen_queue.popleft()()
            self.hydrogen_queue.popleft()()
            self.oxygen_queue.popleft()()