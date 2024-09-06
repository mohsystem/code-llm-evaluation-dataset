import threading

class H2O:
    def __init__(self):
        self.hydrogen_count = 0
        self.oxygen_count = 0
        self.hydrogen_lock = threading.Lock()
        self.oxygen_lock = threading.Lock()
        self.hydrogen_cond = threading.Condition(self.hydrogen_lock)
        self.oxygen_cond = threading.Condition(self.oxygen_lock)

    def hydrogen(self, releaseHydrogen: 'Callable[[], None]') -> None:
        with self.hydrogen_lock:
            self.hydrogen_count += 1
            while self.hydrogen_count < 2 or self.oxygen_count < 1:
                self.hydrogen_cond.wait()
            releaseHydrogen()
            self.hydrogen_count -= 1
            if self.hydrogen_count == 0:
                self.oxygen_cond.notify_all()

    def oxygen(self, releaseOxygen: 'Callable[[], None]') -> None:
        with self.oxygen_lock:
            self.oxygen_count += 1
            while self.oxygen_count < 1 or self.hydrogen_count < 2:
                self.oxygen_cond.wait()
            releaseOxygen()
            self.oxygen_count -= 1
            if self.oxygen_count == 0:
                self.hydrogen_cond.notify_all()