public class Main {
    public static void main(String[] args) {
        System.out.println(solution("abc", "bc")); // true
        System.out.println(solution("abc", "d")); // false
    }

    public static boolean solution(String str, String ending) {
        return str.endsWith(ending);
    }
}