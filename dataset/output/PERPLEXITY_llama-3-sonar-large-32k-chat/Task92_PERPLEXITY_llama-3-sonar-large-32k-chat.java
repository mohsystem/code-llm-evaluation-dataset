class SharedResource {
    int currentCounter;
    int maxCounter;
    Object lock = new Object();

    public SharedResource(int maxCounter) {
        this.maxCounter = maxCounter;
        this.currentCounter = 0;
    }

    public void accessResource(int threadId) {
        synchronized (lock) {
            while (currentCounter <= maxCounter) {
                currentCounter++;
                System.out.println("Thread " + threadId + " is accessing the currentCounter: " + currentCounter);
                try {
                    Thread.sleep(100); // simulate some work
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}

class ThreadWorker extends Thread {
    SharedResource sharedResource;
    int threadId;

    public ThreadWorker(SharedResource sharedResource, int threadId) {
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
        SharedResource sharedResource = new SharedResource(5);
        ThreadWorker thread1 = new ThreadWorker(sharedResource, 1);
        ThreadWorker thread2 = new ThreadWorker(sharedResource, 2);
        thread1.start();
        thread2.start();
    }
}