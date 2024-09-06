import java.util.concurrent.Semaphore;
import java.util.concurrent.CyclicBarrier;

class H2O {
    private Semaphore hSemaphore = new Semaphore(2);
    private Semaphore oSemaphore = new Semaphore(1);
    private CyclicBarrier barrier = new CyclicBarrier(3);

    public H2O() {
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        hSemaphore.acquire();
        try {
            barrier.await();
            // releaseHydrogen() outputs "H". Do not change or remove this line.
            releaseHydrogen.run();
        } finally {
            hSemaphore.release();
        }
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        oSemaphore.acquire();
        try {
            barrier.await();
            // releaseOxygen() outputs "O". Do not change or remove this line.
            releaseOxygen.run();
        } finally {
            oSemaphore.release();
        }
    }
}