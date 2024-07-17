import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class SharedResource {
    private int currentCounter = 0;
    private int maxCounter = 10;
    private Lock lock = new ReentrantLock();

    public void accessResource(int threadId) {
        if (currentCounter <= maxCounter) {
            lock.lock();
            try {
                currentCounter++;
                System.out.println("Thread " + threadId + " is accessing the currentCounter at the moment. Current counter value: " + currentCounter);
            } finally {
                lock.unlock();
            }
        }
    }
}

class ThreadSafeMechanism extends Thread {
    private SharedResource sharedResource;
    private int threadId;

    public ThreadSafeMechanism(SharedResource sharedResource, int threadId) {
        this.sharedResource = sharedResource;
        this.threadId = threadId;
    }

    @Override
    public void run() {
        sharedResource.accessResource(threadId);
    }
}

public class Main {
    public static void main(String[] args) {
        SharedResource sharedResource = new SharedResource();
        for (int i = 1; i <= 20; i++) {
            Thread thread = new ThreadSafeMechanism(sharedResource, i);
            thread.start();
        }
    }
}