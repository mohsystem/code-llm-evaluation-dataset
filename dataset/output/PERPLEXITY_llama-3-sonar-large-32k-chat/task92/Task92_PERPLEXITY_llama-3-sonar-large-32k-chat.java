class SharedResource {
    int maxCounter;
    int currentCounter;
    Object lock = new Object();

    public SharedResource(int maxCounter) {
        this.maxCounter = maxCounter;
        this.currentCounter = 0;
    }

    public void accessResource(String threadName) {
        while (currentCounter <= maxCounter) {
            synchronized (lock) {
                if (currentCounter <= maxCounter) {
                    currentCounter++;
                    System.out.println("Thread " + threadName + " is accessing the currentCounter at " + currentCounter);
                } else {
                    break;
                }
            }
        }
    }

    public static void main(String[] args) {
        SharedResource resource = new SharedResource(5);
        Thread[] threads = new Thread[5];
        for (int i = 0; i < 5; i++) {
            threads[i] = new Thread(() -> resource.accessResource(String.valueOf(i)));
            threads[i].start();
        }
        for (Thread t : threads) {
            try {
                t.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}