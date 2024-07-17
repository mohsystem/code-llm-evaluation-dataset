import threading

class H2O:
    def __init__(self):
        self.hydrogen = threading.Semaphore(2)
        self.oxygen = threading.Semaphore(0)
        self.mutex = threading.Lock()
        self.h_count = 0

    def hydrogen(self, releaseHydrogen: 'Callable[[], None]') -> None:
        self.hydrogen.acquire()
        releaseHydrogen()
        with self.mutex:
            self.h_count += 1
            if self.h_count == 2:
                self.h_count = 0
                self.oxygen.release()

    def oxygen(self, releaseOxygen: 'Callable[[], None]') -> None:
        self.oxygen.acquire()
        releaseOxygen()
        self.hydrogen.release()
        self.hydrogen.release()