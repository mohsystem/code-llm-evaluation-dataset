public class Task31_MISTRAL_codestral_latest {
    public static String makeComplement(String dna) {
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
}