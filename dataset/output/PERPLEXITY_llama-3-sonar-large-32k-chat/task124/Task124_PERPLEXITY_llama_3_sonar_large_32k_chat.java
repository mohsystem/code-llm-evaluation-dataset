public class Task124_PERPLEXITY_llama_3_sonar_large_32k_chat {
    private String data;

    public Task124_PERPLEXITY_llama_3_sonar_large_32k_chat(String data) {
        this.data = data;
    }

    public String getData() {
        return data;
    }

    public static void main(String[] args) {
        Task124_PERPLEXITY_llama_3_sonar_large_32k_chat data = new Task124_PERPLEXITY_llama_3_sonar_large_32k_chat("1234-5678-9012-3456");
        System.out.println(data.getData());
    }
}