public class Main {
    public static void main(String[] args) {
        System.out.println(findNb(1071225)); // 45
        System.out.println(findNb(91716553919377L)); // -1
    }

    public static long findNb(long m) {
        long n = 0;
        long volume = 0;
        
        while (volume < m) {
            n++;
            volume += n * n * n;
        }
        
        if (volume == m) {
            return n;
        } else {
            return -1;
        }
    }
}