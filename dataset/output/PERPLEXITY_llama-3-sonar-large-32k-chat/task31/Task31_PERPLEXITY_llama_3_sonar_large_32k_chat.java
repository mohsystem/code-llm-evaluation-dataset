public class Task31_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static String makeComplement(String dna) {
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