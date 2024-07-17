
public class MemoryAllocation {
    public static void main(String[] args) {
        // Allocate memory
        int[] array = new int[10];

        // Use the allocated memory
        array[0] = 5;
        System.out.println(array[0]);

        // Memory is automatically deallocated when array goes out of scope
    }
}
