import threading

class FooBar:
    def __init__(self, n):
        self.n = n
        self.lock = threading.Lock()
        self.foo_lock = True

    def foo(self, printFoo: 'Callable[[], None]') -> None:
        for i in range(self.n):
            with self.lock:
                while not self.foo_lock:
                    self.lock.wait()
                printFoo()
                self.foo_lock = False
                self.lock.notify_all()

    def bar(self, printBar: 'Callable[[], None]') -> None:
        for i in range(self.n):
            with self.lock:
                while self.foo_lock:
                    self.lock.wait()
                printBar()
                self.foo_lock = True
                self.lock.notify_all()