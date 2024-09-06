
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class SharedResource {
    private int currentCounter = 0;
    private final int maxCounter;
    private final Lock lock = new ReentrantLock();

    public SharedResource(int maxCounter) {
        this.maxCounter = maxCounter;
    }

    public boolean accessResource(int threadId) {
        if (currentCounter <= maxCounter) {
            lock.lock();
            try {
                if (currentCounter <= maxCounter) {
                    currentCounter++;
                    System.out.println("Thread " + threadId + " accessing. Current counter: " + currentCounter);
                    return currentCounter <= maxCounter;
                }
            } finally {
                lock.unlock();
            }
        }
        return false;
    }
}

class ResourceAccessThread extends Thread {
    private final SharedResource sharedResource;
    private final int threadId;

    public ResourceAccessThread(SharedResource sharedResource, int threadId) {
        this.sharedResource = sharedResource;
        this.threadId = threadId;
    }

    @Override
    public void run() {
        while (sharedResource.accessResource(threadId)) {
            // Continue accessing the resource
        }
    }
}

public class Task92_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) {
        int maxCounter = 10;
        int numThreads = 5;
        SharedResource sharedResource = new SharedResource(maxCounter);

        Thread[] threads = new Thread[numThreads];
        for (int i = 0; i < numThreads; i++) {
            threads[i] = new ResourceAccessThread(sharedResource, i);
            threads[i].start();
        }

        for (Thread thread : threads) {
            try {
                thread.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
