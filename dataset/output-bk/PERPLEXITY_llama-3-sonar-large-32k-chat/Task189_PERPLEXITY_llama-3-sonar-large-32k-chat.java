class ZeroEvenOdd {
    private int n;
    private boolean zeroTurn = true;
    private boolean evenTurn = false;
    private boolean oddTurn = false;
    private int count = 0;

    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    public void zero(IntConsumer printNumber) throws InterruptedException {
        for (int i = 0; i < n * 2; i++) {
            synchronized (this) {
                while (!zeroTurn) {
                    wait();
                }
                printNumber.accept(0);
                count++;
                if (count % 2 == 0) {
                    zeroTurn = false;
                    evenTurn = true;
                } else {
                    zeroTurn = false;
                    oddTurn = true;
                }
                notifyAll();
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int i = 2; i <= n * 2; i += 2) {
            synchronized (this) {
                while (!evenTurn) {
                    wait();
                }
                printNumber.accept(i);
                evenTurn = false;
                zeroTurn = true;
                notifyAll();
            }
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n * 2; i += 2) {
            synchronized (this) {
                while (!oddTurn) {
                    wait();
                }
                printNumber.accept(i);
                oddTurn = false;
                zeroTurn = true;
                notifyAll();
            }
        }
    }
}