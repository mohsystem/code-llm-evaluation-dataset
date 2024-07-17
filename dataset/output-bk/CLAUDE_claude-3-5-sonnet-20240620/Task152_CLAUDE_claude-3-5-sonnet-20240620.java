
import java.util.LinkedList;

class HashTable {
    private int size;
    private LinkedList<Entry>[] table;

    @SuppressWarnings("unchecked")
    public HashTable(int size) {
        this.size = size;
        table = new LinkedList[size];
        for (int i = 0; i < size; i++) {
            table[i] = new LinkedList<>();
        }
    }

    private int hashFunction(String key) {
        return Math.abs(key.hashCode() % size);
    }

    public void insert(String key, int value) {
        int hashIndex = hashFunction(key);
        for (Entry entry : table[hashIndex]) {
            if (entry.key.equals(key)) {
                entry.value = value;
                return;
            }
        }
        table[hashIndex].add(new Entry(key, value));
    }

    public void delete(String key) {
        int hashIndex = hashFunction(key);
        table[hashIndex].removeIf(entry -> entry.key.equals(key));
    }

    public Integer search(String key) {
        int hashIndex = hashFunction(key);
        for (Entry entry : table[hashIndex]) {
            if (entry.key.equals(key)) {
                return entry.value;
            }
        }
        return null;
    }

    private static class Entry {
        String key;
        int value;

        Entry(String key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    public static void main(String[] args) {
        HashTable ht = new HashTable(10);
        ht.insert("apple", 5);
        ht.insert("banana", 7);
        ht.insert("orange", 3);

        System.out.println(ht.search("apple"));  // Output: 5
        System.out.println(ht.search("grape"));  // Output: null

        ht.delete("banana");
        System.out.println(ht.search("banana"));  // Output: null
    }
}
