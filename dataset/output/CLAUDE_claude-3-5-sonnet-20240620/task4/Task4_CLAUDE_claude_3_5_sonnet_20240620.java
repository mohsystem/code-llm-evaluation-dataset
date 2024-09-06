
public class Task4_CLAUDE_claude_3_5_sonnet_20240620 {
    public static boolean isIsogram(String str) {
        return str.toLowerCase().chars().distinct().count() == str.length();
    }
    
    public static void main(String[] args) {
        System.out.println(isIsogram("Dermatoglyphics"));  // true
        System.out.println(isIsogram("aba"));  // false
        System.out.println(isIsogram("moOse"));  // false
    }
}
