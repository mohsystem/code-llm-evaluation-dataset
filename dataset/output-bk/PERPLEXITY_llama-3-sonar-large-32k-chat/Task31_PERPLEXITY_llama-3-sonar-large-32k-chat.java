public class Main {
    public static void main(String[] args) {
        System.out.println(DNATranslate("ATTGC")); // --> "TAACG"
        System.out.println(DNATranslate("GTAT")); // --> "CATA"
    }

    public static String DNATranslate(String dna) {
        String complement = "";
        for (char c : dna.toCharArray()) {
            switch (c) {
                case 'A':
                    complement += 'T';
                    break;
                case 'T':
                    complement += 'A';
                    break;
                case 'C':
                    complement += 'G';
                    break;
                case 'G':
                    complement += 'C';
                    break;
            }
        }
        return complement;
    }
}