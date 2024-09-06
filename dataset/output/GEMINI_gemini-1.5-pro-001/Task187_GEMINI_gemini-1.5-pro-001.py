from threading import Barrier, Thread

class H2O:
    def __init__(self):
        self.barrier = Barrier(3)
        self.h_count = 0
        self.o_count = 0

    def hydrogen(self, releaseHydrogen: 'Callable[[], None]') -> None:
        self.barrier.wait()
        # releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen()
        self.h_count += 1
        if self.h_count == 2 and self.o_count == 1:
            self.h_count = 0
            self.o_count = 0

    def oxygen(self, releaseOxygen: 'Callable[[], None]') -> None:
        self.barrier.wait()
        # releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen()
        self.o_count += 1
        if self.h_count == 2 and self.o_count == 1:
            self.h_count = 0
            self.o_count = 0