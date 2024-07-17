import threading

class FooBar:
    def __init__(self, n):
        self.n = n
        self.lock = threading.Lock()
        self.foo_lock = threading.Lock()
        self.foo_lock.acquire()

    def foo(self):
        for i in range(self.n):
            with self.lock:
                print("foo", end="")
                self.foo_lock.release()
                self.bar_lock = self.lock

    def bar(self):
        for i in range(self.n):
            self.foo_lock.acquire()
            with self.bar_lock:
                print("bar", end="")
                self.foo_lock = threading.Lock()
                self.foo_lock.acquire()
                self.bar_lock = self.lock