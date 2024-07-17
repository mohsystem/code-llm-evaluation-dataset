class H2O {
    private int hydrogenCount = 0;
    private int oxygenCount = 0;
    private final Object lock = new Object();

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        synchronized (lock) {
            hydrogenCount++;
            if (hydrogenCount == 2) {
                lock.notifyAll();
            } else {
                lock.wait();
            }
        }
        releaseHydrogen.run();
        synchronized (lock) {
            hydrogenCount--;
        }
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        synchronized (lock) {
            oxygenCount++;
            if (oxygenCount == 1) {
                lock.notifyAll();
            } else {
                lock.wait();
            }
        }
        releaseOxygen.run();
        synchronized (lock) {
            oxygenCount--;
        }
    }
}