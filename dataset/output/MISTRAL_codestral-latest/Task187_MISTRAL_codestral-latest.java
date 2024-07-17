import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.ReentrantLock;

public class H2O {
    private Semaphore hydrogen;
    private Semaphore oxygen;
    private ReentrantLock lock;

    public H2O() {
        hydrogen = new Semaphore(2);
        oxygen = new Semaphore(0);
        lock = new ReentrantLock();
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        hydrogen.acquire();
        lock.lock();
        releaseHydrogen.run();
        oxygen.release();
        lock.unlock();
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        oxygen.acquire(2);
        lock.lock();
        releaseOxygen.run();
        hydrogen.release(2);
        lock.unlock();
    }
}