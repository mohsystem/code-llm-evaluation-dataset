import threading

n = 2

class FooBar:

    def __init__(self, n):
        self.n = n
        self.foo_done = threading.Event()
        self.bar_done = threading.Event()
        self.foo_done.set()  # foo_done initially set to allow foo to run first

    def foo(self):
        for _ in range(self.n):
            self.foo_done.wait()    # Wait for foo_done to be set
            self.foo_done.clear()   # Reset foo_done
            print("foo", end="")
            self.bar_done.set()     # Signal bar_done to allow bar to run

    def bar(self):
        for _ in range(self.n):
            self.bar_done.wait()    # Wait for bar_done to be set
            self.bar_done.clear()   # Reset bar_done
            print("bar", end="")
            self.foo_done.set()     # Signal foo_done to allow foo to run

foobar = FooBar(n)
threadA = threading.Thread(target=foobar.foo)
threadB = threading.Thread(target=foobar.bar)
threadA.start()
threadB.start()
threadA.join()
threadB.join()