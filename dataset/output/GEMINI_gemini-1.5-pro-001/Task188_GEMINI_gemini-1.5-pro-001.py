from threading import Lock, Thread
class FooBar:
    def __init__(self, n):
        self.n = n
        self.foo_lock = Lock()
        self.bar_lock = Lock()
        self.bar_lock.acquire()

    def foo(self) -> None:
        for i in range(self.n):
            self.foo_lock.acquire()
            print("foo", end="")
            self.bar_lock.release()

    def bar(self) -> None:
        for i in range(self.n):
            self.bar_lock.acquire()
            print("bar", end="")
            self.foo_lock.release()
            
if __name__ == "__main__":
    n = 2
    foobar = FooBar(n)
    thread1 = Thread(target=foobar.foo)
    thread2 = Thread(target=foobar.bar)
    thread1.start()
    thread2.start()
    thread1.join()
    thread2.join()