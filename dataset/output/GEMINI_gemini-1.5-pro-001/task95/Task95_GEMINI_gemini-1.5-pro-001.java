class ProcessorTime {
    public static void main(String[] args) {
        long startTime = System.nanoTime();
        // Some code here
        long endTime = System.nanoTime();
        double seconds = (double) (endTime - startTime) / 1_000_000_000;
        System.out.println(seconds);
    }
}