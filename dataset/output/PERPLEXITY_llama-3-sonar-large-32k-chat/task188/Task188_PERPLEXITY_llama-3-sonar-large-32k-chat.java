class FooBar {
    private int n;
    private boolean fooLock = true;

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            synchronized (this) {
                while (!fooLock) {
                    wait();
                }
                printFoo.run();
                fooLock = false;
                notifyAll();
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            synchronized (this) {
                while (fooLock) {
                    wait();
                }
                printBar.run();
                fooLock = true;
                notifyAll();
            }
        }
    }
}