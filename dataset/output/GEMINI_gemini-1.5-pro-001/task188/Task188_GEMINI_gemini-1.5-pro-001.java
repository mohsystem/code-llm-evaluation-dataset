class FooBar {
    private int n;
    private Object fooLock = new Object();
    private Object barLock = new Object();

    public FooBar(int n) {
        this.n = n;
    }

    public void foo() {
        for (int i = 0; i < n; i++) {
            synchronized (fooLock) {
                synchronized (barLock) {
                    System.out.print("foo");
                    barLock.notify();
                    try {
                        barLock.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        }
    }

    public void bar() {
        for (int i = 0; i < n; i++) {
            synchronized (barLock) {
                System.out.print("bar");
                fooLock.notify();
                try {
                    fooLock.wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public static void main(String[] args) {
        int n = 2;
        FooBar fooBar = new FooBar(n);
        Thread threadA = new Thread(fooBar::foo);
        Thread threadB = new Thread(fooBar::bar);
        threadA.start();
        threadB.start();
    }
}