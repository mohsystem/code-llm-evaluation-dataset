from threading import Lock
class FooBar:
    def __init__(self, n):
        self.n = n
        self.foo_lock = Lock()
        self.bar_lock = Lock()
        self.bar_lock.acquire()

    def foo(self):
        for i in range(self.n):
            self.foo_lock.acquire()
            print("foo", end="")
            self.bar_lock.release()

    def bar(self):
        for i in range(self.n):
            self.bar_lock.acquire()
            print("bar", end="")
            self.foo_lock.release()