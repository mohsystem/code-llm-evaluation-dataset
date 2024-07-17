import threading

class FooBar:
    def __init__(self, n):
        self.n = n
        self.foo_done = threading.Event()

    def foo(self, printFoo: 'Callable[[], None]') -> None:
        for i in range(self.n):
            printFoo()
            self.foo_done.set()
            self.foo_done.clear()

    def bar(self, printBar: 'Callable[[], None]') -> None:
        for i in range(self.n):
            self.foo_done.wait()
            printBar()

def print_foobar(n):
    fb = FooBar(n)

    def printFoo():
        print("foo", end='')

    def printBar():
        print("bar", end='')

    thread1 = threading.Thread(target=fb.foo, args=(printFoo,))
    thread2 = threading.Thread(target=fb.bar, args=(printBar,))

    thread1.start()
    thread2.start()

    thread1.join()
    thread2.join()

if __name__ == "__main__":
    n = 2 # Change as needed
    print_foobar(n)