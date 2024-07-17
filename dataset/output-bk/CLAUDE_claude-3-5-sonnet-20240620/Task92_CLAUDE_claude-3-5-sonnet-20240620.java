
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class ThreadSafeCounter {
    private static int currentCounter = 0;
    private static final int maxCounter = 10;
    private static final Lock lock = new ReentrantLock();

    static class CounterThread extends Thread {
        @Override
        public void run() {
            while (true) {
                if (currentCounter <= maxCounter) {
                    lock.lock();
                    try {
                        if (currentCounter <= maxCounter) {
                            currentCounter++;
                            System.out.println("Thread " + Thread.currentThread().getId() + " accessing counter: " + currentCounter);
                        }
                    } finally {
                        lock.unlock();
                    }
                } else {
                    break;
                }
            }
        }
    }

    public static void main(String[] args) {
        for (int i = 0; i < 5; i++) {
            new CounterThread().start();
        }
    }
}
