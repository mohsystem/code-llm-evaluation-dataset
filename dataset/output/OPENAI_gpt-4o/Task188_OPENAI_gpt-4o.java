import java.util.concurrent.atomic.AtomicBoolean;

class FooBar {
    private int n;
    private AtomicBoolean fooDone = new AtomicBoolean(false);

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            printFoo.run();
            fooDone.set(true);
            synchronized(this) {
                notifyAll();
                while (fooDone.get()) {
                    wait();
                }
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            synchronized(this) {
                while (!fooDone.get()) {
                    wait();
                }
                printBar.run();
                fooDone.set(false);
                notifyAll();
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        FooBar fb = new FooBar(2);  // change `n` value as needed

        Runnable printFoo = () -> System.out.print("foo");
        Runnable printBar = () -> System.out.print("bar");

        Thread threadA = new Thread(() -> {
            try {
                fb.foo(printFoo);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        Thread threadB = new Thread(() -> {
            try {
                fb.bar(printBar);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        threadA.start();
        threadB.start();

        threadA.join();
        threadB.join();
    }
}