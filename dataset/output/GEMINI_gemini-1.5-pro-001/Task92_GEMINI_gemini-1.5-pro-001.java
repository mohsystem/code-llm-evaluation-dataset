import java.util.concurrent.locks.ReentrantLock;

class SharedResource {
    private int currentCounter = 0;
    private int maxCounter;
    private ReentrantLock lock = new ReentrantLock();

    public SharedResource(int maxCounter) {
        this.maxCounter = maxCounter;
    }

    public void accessResource(int threadId) {
        if (currentCounter <= maxCounter) {
            lock.lock();
            try {
                if (currentCounter <= maxCounter) {
                    currentCounter++;
                    System.out.println("Thread " + threadId + " is accessing currentCounter: " + currentCounter);
                }
            } finally {
                lock.unlock();
            }
        }
    }
}

class MyThread extends Thread {
    private int threadId;
    private SharedResource sharedResource;

    public MyThread(int threadId, SharedResource sharedResource) {
        this.threadId = threadId;
        this.sharedResource = sharedResource;
    }

    @Override
    public void run() {
        sharedResource.accessResource(threadId);
    }
}

public class Main {
    public static void main(String[] args) {
        SharedResource sharedResource = new SharedResource(5);
        MyThread thread1 = new MyThread(1, sharedResource);
        MyThread thread2 = new MyThread(2, sharedResource);
        thread1.start();
        thread2.start();
    }
}