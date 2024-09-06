public class Task58_MISTRAL_codestral_latest {
    public static boolean getXO (String str) {
        str = str.toLowerCase();
        int x = 0, o = 0;
        for(int i = 0; i < str.length(); i++) {
            if(str.charAt(i) == 'x') x++;
            else if(str.charAt(i) == 'o') o++;
        }
        return x == o;
    }
}