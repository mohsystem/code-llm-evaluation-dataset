import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Task92_MISTRAL_codestral_latest {
    private int maxCounter;
    private int currentCounter;
    private Lock lock;

    public Task92_MISTRAL_codestral_latest(int maxCounter) {
        this.maxCounter = maxCounter;
        this.currentCounter = 0;
        this.lock = new ReentrantLock();
    }

    public void accessResource(int threadId) {
        lock.lock();
        try {
            if (currentCounter <= maxCounter) {
                currentCounter++;
                System.out.println("Thread " + threadId + " is accessing the currentCounter at the moment.");
            }
        } finally {
            lock.unlock();
        }
    }

    public static void main(String[] args) {
        int maxCounter = 10;
        Task92_MISTRAL_codestral_latest counter = new Task92_MISTRAL_codestral_latest(maxCounter);

        // Create and start multiple threads
        for (int i = 0; i < 15; i++) {
            Thread thread = new Thread(() -> counter.accessResource(i));
            thread.start();
        }
    }
}