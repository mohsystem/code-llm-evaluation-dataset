public class Task31_OPENAI_gpt_4o {
    public static String dnaStrand(String dna) {
        StringBuilder complement = new StringBuilder();
        for (char base : dna.toCharArray()) {
            switch (base) {
                case 'A':
                    complement.append('T');
                    break;
                case 'T':
                    complement.append('A');
                    break;
                case 'C':
                    complement.append('G');
                    break;
                case 'G':
                    complement.append('C');
                    break;
            }
        }
        return complement.toString();
    }

    public static void main(String[] args) {
        System.out.println(dnaStrand("ATTGC"));  // Output: TAACG
        System.out.println(dnaStrand("GTAT"));   // Output: CATA
    }
}