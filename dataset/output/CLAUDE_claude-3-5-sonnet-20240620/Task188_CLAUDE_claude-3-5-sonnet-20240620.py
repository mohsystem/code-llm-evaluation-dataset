
import threading

class FooBar:
    def __init__(self, n):
        self.n = n
        self.foo_lock = threading.Lock()
        self.bar_lock = threading.Lock()
        self.bar_lock.acquire()

    def foo(self, printFoo: 'Callable[[], None]') -> None:
        for i in range(self.n):
            self.foo_lock.acquire()
            printFoo()
            self.bar_lock.release()

    def bar(self, printBar: 'Callable[[], None]') -> None:
        for i in range(self.n):
            self.bar_lock.acquire()
            printBar()
            self.foo_lock.release()

def printFoo():
    print("foo", end="")

def printBar():
    print("bar", end="")

n = 2
fooBar = FooBar(n)

thread1 = threading.Thread(target=fooBar.foo, args=(printFoo,))
thread2 = threading.Thread(target=fooBar.bar, args=(printBar,))

thread1.start()
thread2.start()

thread1.join()
thread2.join()
