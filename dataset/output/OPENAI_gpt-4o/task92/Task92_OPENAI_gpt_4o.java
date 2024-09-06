import java.util.concurrent.locks.ReentrantLock;

public class Task92_OPENAI_gpt_4o {
    private static int maxCounter = 10;
    private static int currentCounter = 0;
    private static final ReentrantLock lock = new ReentrantLock();

    public static void main(String[] args) {
        Runnable worker = () -> {
            while (true) {
                lock.lock();
                try {
                    if (currentCounter <= maxCounter) {
                        System.out.println(Thread.currentThread().getName() + " accessing currentCounter: " + currentCounter);
                        currentCounter++;
                    } else {
                        break;
                    }
                } finally {
                    lock.unlock();
                }
            }
        };

        Thread[] threads = new Thread[5];
        for (int i = 0; i < 5; i++) {
            threads[i] = new Thread(worker, "Thread " + i);
            threads[i].start();
        }

        for (int i = 0; i < 5; i++) {
            try {
                threads[i].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}