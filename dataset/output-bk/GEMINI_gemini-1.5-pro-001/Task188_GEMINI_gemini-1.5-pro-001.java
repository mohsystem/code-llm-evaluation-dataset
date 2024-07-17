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
                System.out.print("foo");
                synchronized (barLock) {
                    barLock.notify();
                }
            }
        }
    }

    public void bar() {
        for (int i = 0; i < n; i++) {
            synchronized (barLock) {
                try {
                    barLock.wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.print("bar");
                synchronized (fooLock) {
                    fooLock.notify();
                }
            }
        }
    }

    public static void main(String[] args) {
        FooBar fooBar = new FooBar(1);
        Thread threadA = new Thread(fooBar::foo);
        Thread threadB = new Thread(fooBar::bar);
        threadA.start();
        threadB.start();
    }
}