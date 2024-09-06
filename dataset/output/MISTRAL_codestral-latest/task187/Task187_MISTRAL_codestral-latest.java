import java.util.concurrent.Semaphore;

class H2O {
    private Semaphore hSem;
    private Semaphore oSem;

    public H2O() {
        hSem = new Semaphore(2);
        oSem = new Semaphore(0);
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        hSem.acquire();
        releaseHydrogen.run();
        oSem.release();
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        oSem.acquire(2);
        releaseOxygen.run();
        hSem.release(2);
    }
}