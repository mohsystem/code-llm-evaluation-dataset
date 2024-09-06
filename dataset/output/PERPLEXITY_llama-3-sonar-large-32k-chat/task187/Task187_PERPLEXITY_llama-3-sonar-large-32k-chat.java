import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class H2O {
    private int hydrogenCount = 0;
    private int oxygenCount = 0;
    private Lock hydrogenLock = new ReentrantLock();
    private Lock oxygenLock = new ReentrantLock();
    private Condition hydrogenCond = hydrogenLock.newCondition();
    private Condition oxygenCond = oxygenLock.newCondition();

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        hydrogenLock.lock();
        try {
            hydrogenCount++;
            while (hydrogenCount < 2 || oxygenCount < 1) {
                hydrogenCond.await();
            }
            releaseHydrogen.run();
            hydrogenCount--;
            if (hydrogenCount == 0) {
                oxygenCond.signalAll();
            }
        } finally {
            hydrogenLock.unlock();
        }
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        oxygenLock.lock();
        try {
            oxygenCount++;
            while (oxygenCount < 1 || hydrogenCount < 2) {
                oxygenCond.await();
            }
            releaseOxygen.run();
            oxygenCount--;
            if (oxygenCount == 0) {
                hydrogenCond.signalAll();
            }
        } finally {
            oxygenLock.unlock();
        }
    }
}