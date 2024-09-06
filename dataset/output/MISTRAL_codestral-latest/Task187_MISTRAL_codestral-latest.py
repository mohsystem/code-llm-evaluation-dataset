import threading

class H2O:
    def __init__(self):
        self.h_sem = threading.Semaphore(2)
        self.o_sem = threading.Semaphore(0)

    def hydrogen(self, releaseHydrogen):
        with self.h_sem:
            releaseHydrogen()
            self.o_sem.release()

    def oxygen(self, releaseOxygen):
        with self.o_sem:
            self.h_sem.acquire()
            self.h_sem.acquire()
            releaseOxygen()
            self.h_sem.release()
            self.h_sem.release()