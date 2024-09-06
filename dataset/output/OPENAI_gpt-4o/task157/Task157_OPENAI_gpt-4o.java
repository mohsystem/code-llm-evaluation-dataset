class MemoryAllocation {
    public static void main(String[] args) {
        // Allocate memory for an integer
        int[] intArray = new int[1];
        intArray[0] = 10;
        System.out.println("Value at allocated memory: " + intArray[0]);

        // Deallocate memory (no explicit deallocation in Java, handled by garbage collection)
        intArray = null;
    }
}