public class Task123_OPENAI_gpt_4o {
    private String userId;
    private long startTime;

    public Task123_OPENAI_gpt_4o(String userId) {
        this.userId = userId;
        this.startTime = System.currentTimeMillis();
    }

    public long getDuration() {
        return (System.currentTimeMillis() - startTime) / 1000;
    }

    public static void main(String[] args) {
        try {
            Task123_OPENAI_gpt_4o session = new Task123_OPENAI_gpt_4o("User1");
            Thread.sleep(2000);
            System.out.println("Java: Session duration for " + session.userId + ": " + session.getDuration() + " seconds");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}