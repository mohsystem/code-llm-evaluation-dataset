public class Task16_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static boolean solution(String str1, String str2) {
        return str1.endsWith(str2);
    }
    public static void main(String[] args) {
        System.out.println(solution("abc", "bc")); // returns true
        System.out.println(solution("abc", "d")); // returns false
    }
}