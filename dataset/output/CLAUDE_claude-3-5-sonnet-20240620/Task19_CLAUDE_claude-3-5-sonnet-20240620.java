
public class SpinWords {
    public String spinWords(String sentence) {
        String[] words = sentence.split(" ");
        for (int i = 0; i < words.length; i++) {
            if (words[i].length() >= 5) {
                words[i] = new StringBuilder(words[i]).reverse().toString();
            }
        }
        return String.join(" ", words);
    }

    public static void main(String[] args) {
        SpinWords spinner = new SpinWords();
        System.out.println(spinner.spinWords("Hey fellow warriors"));
        System.out.println(spinner.spinWords("This is a test"));
        System.out.println(spinner.spinWords("This is another test"));
    }
}
