import java.util.*;
public class ComplementaryDNA {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter DNA strand: ");
        String dnaStrand = scanner.nextLine();
        System.out.println(makeComplement(dnaStrand));
    }
    public static String makeComplement(String dna) {
        StringBuilder complement = new StringBuilder();
        for (char nucleotide : dna.toCharArray()) {
            switch (nucleotide) {
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
                default: 
                    complement.append('?'); 
            }
        }
        return complement.toString();
    }
}