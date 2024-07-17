public class EncryptString {
    public static void main(String[] args) {
        String input = "HelloWorld";
        int shift = 3;
        StringBuilder encrypted = new StringBuilder();
        
        for (char c : input.toCharArray()) {
            if (Character.isLetter(c)) {
                char base = Character.isLowerCase(c) ? 'a' : 'A';
                encrypted.append((char) ((c - base + shift) % 26 + base));
            } else {
                encrypted.append(c);
            }
        }
        
        System.out.println("Java: " + encrypted.toString());
    }
}
EncryptString.main(null);