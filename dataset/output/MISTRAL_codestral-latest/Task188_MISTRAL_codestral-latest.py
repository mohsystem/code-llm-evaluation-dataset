from threading import Semaphore

class FooBar:
    def __init__(self, n):
        self.n = n
        self.fooSemaphore = Semaphore(1)
        self.barSemaphore = Semaphore(0)

    def foo(self, printFoo):
        for i in range(self.n):
            self.fooSemaphore.acquire()
            printFoo()
            self.barSemaphore.release()

    def bar(self, printBar):
        for i in range(self.n):
            self.barSemaphore.acquire()
            printBar()
            self.fooSemaphore.release()