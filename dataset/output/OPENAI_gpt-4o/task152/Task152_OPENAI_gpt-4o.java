import java.util.Arrays;

class HashTable {
    private final int SIZE = 10;
    private String[] table;

    public HashTable() {
        table = new String[SIZE];
        Arrays.fill(table, null);
    }

    private int hashFunction(int key) {
        return key % SIZE;
    }

    public void insert(int key, String value) {
        int hashKey = hashFunction(key);
        table[hashKey] = value;
    }

    public void delete(int key) {
        int hashKey = hashFunction(key);
        table[hashKey] = null;
    }

    public String search(int key) {
        int hashKey = hashFunction(key);
        return table[hashKey];
    }

    public static void main(String[] args) {
        HashTable ht = new HashTable();
        ht.insert(1, "one");
        ht.insert(2, "two");
        ht.insert(11, "eleven");
        System.out.println("Search key 1: " + ht.search(1));
        System.out.println("Search key 2: " + ht.search(2));
        ht.delete(1);
        System.out.println("Search key 1 after deletion: " + ht.search(1));
    }
}