import java.util.*;

public class Task28_OPENAI_gpt_4o {
    public static String likes(String... names) {
        int n = names.length;
        switch (n) {
            case 0: return "no one likes this";
            case 1: return names[0] + " likes this";
            case 2: return names[0] + " and " + names[1] + " like this";
            case 3: return names[0] + ", " + names[1] + " and " + names[2] + " like this";
            default: return names[0] + ", " + names[1] + " and " + (n - 2) + " others like this";
        }
    }

    public static void main(String[] args) {
        System.out.println(likes());
        System.out.println(likes("Peter"));
        System.out.println(likes("Jacob", "Alex"));
        System.out.println(likes("Max", "John", "Mark"));
        System.out.println(likes("Alex", "Jacob", "Mark", "Max"));
    }
}