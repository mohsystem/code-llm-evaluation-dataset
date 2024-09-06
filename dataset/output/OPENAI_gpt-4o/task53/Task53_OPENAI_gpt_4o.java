public class Task53_OPENAI_gpt_4o {
    private String sessionId;
    private String userId;

    public Task53_OPENAI_gpt_4o(String sessionId, String userId) {
        this.sessionId = sessionId;
        this.userId = userId;
    }

    @Override
    public String toString() {
        return "Session ID: " + sessionId + ", User ID: " + userId;
    }

    public static void main(String[] args) {
        Task53_OPENAI_gpt_4o session = new Task53_OPENAI_gpt_4o("abc123", "user001");
        System.out.println(session);
    }
}