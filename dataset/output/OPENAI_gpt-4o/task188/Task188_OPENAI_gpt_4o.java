import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Task188_OPENAI_gpt_4o {
    public static void main(String[] args) {
        int n = 2;
        FooBar fooBar = new FooBar(n);
        Thread threadA = new Thread(() -> {
            try {
                fooBar.foo();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });
        Thread threadB = new Thread(() -> {
            try {
                fooBar.bar();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });
        threadA.start();
        threadB.start();
    }
}

class FooBar {
    private int n;
    private Lock lock;
    private Condition conditionFoo;
    private Condition conditionBar;
    private boolean fooTurn;

    public FooBar(int n) {
        this.n = n;
        this.lock = new ReentrantLock();
        this.conditionFoo = lock.newCondition();
        this.conditionBar = lock.newCondition();
        this.fooTurn = true;
    }

    public void foo() throws InterruptedException {
        for (int i = 0; i < n; i++) {
            lock.lock();
            try {
                while (!fooTurn) {
                    conditionFoo.await();
                }
                System.out.print("foo");
                fooTurn = false;
                conditionBar.signal();
            } finally {
                lock.unlock();
            }
        }
    }

    public void bar() throws InterruptedException {
        for (int i = 0; i < n; i++) {
            lock.lock();
            try {
                while (fooTurn) {
                    conditionBar.await();
                }
                System.out.print("bar");
                fooTurn = true;
                conditionFoo.signal();
            } finally {
                lock.unlock();
            }
        }
    }
}