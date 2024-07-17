public class MemoryAllocation {
    public static void main(String[] args) {
        // Allocate memory for an integer
        Integer myVar = new Integer(42);
        System.out.println("Java: Value = " + myVar);

        // Deallocate memory
        myVar = null;
        System.gc(); // Request garbage collection
    }
}