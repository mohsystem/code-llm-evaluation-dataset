import java.util.concurrent.Semaphore;

class H2O {
    private Semaphore hSemaphore = new Semaphore(2);
    private Semaphore oSemaphore = new Semaphore(0);
    private int hCount = 0;
    private final Object mutex = new Object();

    public H2O() {}

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        hSemaphore.acquire();
        releaseHydrogen.run();
        synchronized (mutex) {
            hCount++;
            if (hCount == 2) {
                hCount = 0;
                oSemaphore.release();
            }
        }
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        oSemaphore.acquire();
        releaseOxygen.run();
        hSemaphore.release();
        hSemaphore.release();
    }
}