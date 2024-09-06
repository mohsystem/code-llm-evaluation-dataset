import threading

class FooBar:
    def __init__(self, n):
        self.n = n
        self.foo_lock = threading.Lock()
        self.bar_lock = threading.Lock()
        self.bar_lock.acquire()

    def foo(self, print_foo):
        for i in range(self.n):
            self.foo_lock.acquire()
            print_foo()
            self.bar_lock.release()

    def bar(self, print_bar):
        for i in range(self.n):
            self.bar_lock.acquire()
            print_bar()
            self.foo_lock.release()