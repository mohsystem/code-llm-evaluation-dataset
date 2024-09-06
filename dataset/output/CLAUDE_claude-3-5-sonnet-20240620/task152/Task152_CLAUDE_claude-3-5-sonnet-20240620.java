
import java.util.LinkedList;

class HashTable<K, V> {
    private static final int SIZE = 10;
    private LinkedList<Entry<K, V>>[] table;

    @SuppressWarnings("unchecked")
    public HashTable() {
        table = new LinkedList[SIZE];
        for (int i = 0; i < SIZE; i++) {
            table[i] = new LinkedList<>();
        }
    }

    private int hashFunction(K key) {
        return Math.abs(key.hashCode() % SIZE);
    }

    public void insert(K key, V value) {
        int index = hashFunction(key);
        for (Entry<K, V> entry : table[index]) {
            if (entry.key.equals(key)) {
                entry.value = value;
                return;
            }
        }
        table[index].add(new Entry<>(key, value));
    }

    public void delete(K key) {
        int index = hashFunction(key);
        table[index].removeIf(entry -> entry.key.equals(key));
    }

    public V search(K key) {
        int index = hashFunction(key);
        for (Entry<K, V> entry : table[index]) {
            if (entry.key.equals(key)) {
                return entry.value;
            }
        }
        return null;
    }

    private static class Entry<K, V> {
        K key;
        V value;

        Entry(K key, V value) {
            this.key = key;
            this.value = value;
        }
    }

    public static void main(String[] args) {
        HashTable<String, Integer> ht = new HashTable<>();
        ht.insert("apple", 5);
        ht.insert("banana", 7);
        ht.insert("orange", 3);

        System.out.println(ht.search("banana")); // Output: 7
        ht.delete("banana");
        System.out.println(ht.search("banana")); // Output: null
    }
}
