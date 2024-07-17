
public class DnaStrand {
    public static String makeComplement(String dna) {
        StringBuilder complement = new StringBuilder();
        for (char c : dna.toCharArray()) {
            switch (c) {
                case \'A\':
                    complement.append(\'T\');
                    break;
                case \'T\':
                    complement.append(\'A\');
                    break;
                case \'C\':
                    complement.append(\'G\');
                    break;
                case \'G\':
                    complement.append(\'C\');
                    break;
            }
        }
        return complement.toString();
    }

    public static void main(String[] args) {
        System.out.println(makeComplement("ATTGC")); // Output: TAACG
        System.out.println(makeComplement("GTAT"));  // Output: CATA
    }
}
