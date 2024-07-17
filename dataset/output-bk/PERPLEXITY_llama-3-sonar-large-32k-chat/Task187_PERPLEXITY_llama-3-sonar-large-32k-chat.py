import threading

class H2O:
    def __init__(self):
        self.hydrogen_count = 0
        self.oxygen_count = 0
        self.hydrogen_lock = threading.Lock()
        self.oxygen_lock = threading.Lock()
        self.condition = threading.Condition()

    def hydrogen(self, releaseHydrogen: 'Callable[[], None]') -> None:
        with self.condition:
            self.hydrogen_count += 1
            if self.hydrogen_count == 2:
                self.condition.notify_all()
            else:
                self.condition.wait()
        releaseHydrogen()
        with self.condition:
            self.hydrogen_count -= 1

    def oxygen(self, releaseOxygen: 'Callable[[], None]') -> None:
        with self.condition:
            self.oxygen_count += 1
            if self.oxygen_count == 1:
                self.condition.notify_all()
            else:
                self.condition.wait()
        releaseOxygen()
        with self.condition:
            self.oxygen_count -= 1