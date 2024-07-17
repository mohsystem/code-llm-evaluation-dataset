import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class ZeroEvenOdd {
    private int n;
    private Lock lock = new ReentrantLock();
    private Condition condition = lock.newCondition();
    private int state = 0;

    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    public void zero(IntConsumer printNumber) throws InterruptedException {
        for (int i = 0; i < n * 2; i++) {
            lock.lock();
            try {
                while (state % 2 != 0) {
                    condition.await();
                }
                printNumber.accept(0);
                state++;
                condition.signalAll();
            } finally {
                lock.unlock();
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int i = 2; i <= n * 2; i += 2) {
            lock.lock();
            try {
                while (state != i) {
                    condition.await();
                }
                printNumber.accept(i);
                state++;
                condition.signalAll();
            } finally {
                lock.unlock();
            }
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n * 2; i += 2) {
            lock.lock();
            try {
                while (state != i) {
                    condition.await();
                }
                printNumber.accept(i);
                state++;
                condition.signalAll();
            } finally {
                lock.unlock();
            }
        }
    }
}