class ZeroEvenOdd {
    private int n;
    private int state;
    private Object lock = new Object();

    public ZeroEvenOdd(int n) {
        this.n = n;
        this.state = 0;
    }

    public void zero(printNumber printNumber) {
        for (int i = 0; i < n * 2; i++) {
            synchronized (lock) {
                while (state % 3 != 0) {
                    try {
                        lock.wait();
                    } catch (InterruptedException e) {
                        Thread.currentThread().interrupt();
                    }
                }
                printNumber.print(0);
                state++;
                lock.notifyAll();
            }
        }
    }

    public void even(printNumber printNumber) {
        for (int i = 2; i <= n * 2; i += 2) {
            synchronized (lock) {
                while (state % 3 != 1) {
                    try {
                        lock.wait();
                    } catch (InterruptedException e) {
                        Thread.currentThread().interrupt();
                    }
                }
                printNumber.print(i);
                state++;
                lock.notifyAll();
            }
        }
    }

    public void odd(printNumber printNumber) {
        for (int i = 1; i <= n * 2; i += 2) {
            synchronized (lock) {
                while (state % 3 != 2) {
                    try {
                        lock.wait();
                    } catch (InterruptedException e) {
                        Thread.currentThread().interrupt();
                    }
                }
                printNumber.print(i);
                state++;
                lock.notifyAll();
            }
        }
    }
}