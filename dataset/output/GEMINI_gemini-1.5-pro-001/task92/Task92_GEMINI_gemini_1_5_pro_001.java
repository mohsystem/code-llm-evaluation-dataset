public class Task92_GEMINI_gemini_1_5_pro_001 {

    private static int currentCounter = 0;
    private static final int maxCounter = 5;
    private static final Object lock = new Object();

    public static void main(String[] args) {
        for (int i = 0; i < 10; i++) {
            int threadId = i;
            Thread thread = new Thread(() -> accessResource(threadId));
            thread.start();
        }
    }

    private static void accessResource(int threadId) {
        if (currentCounter <= maxCounter) {
            synchronized (lock) {
                if (currentCounter < maxCounter) {
                    currentCounter++;
                    System.out.println("Thread " + threadId + " is accessing currentCounter: " + currentCounter);
                }
            }
        }
    }
}