class ZeroEvenOdd {

    private int n;
    boolean zero_turn = true;
    boolean even_turn = false;
    boolean odd_turn = false;
    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    public void zero(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i++) {
            while (!zero_turn) {
                Thread.yield();
            }
            printNumber.accept(0);
            if (i%2 == 0) {
                even_turn = true;
            } else {
                odd_turn = true;
            }
            zero_turn = false;
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int i = 2; i <= n; i+=2) {
            while (!even_turn) {
                Thread.yield();
            }
            printNumber.accept(i);
            zero_turn = true;
            even_turn = false;
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i+=2) {
            while (!odd_turn) {
                Thread.yield();
            }
            printNumber.accept(i);
            odd_turn = false;
            zero_turn = true;
        }
    }
}