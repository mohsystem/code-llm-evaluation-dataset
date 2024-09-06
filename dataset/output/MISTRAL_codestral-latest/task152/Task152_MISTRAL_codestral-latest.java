import java.util.ArrayList;
import java.util.List;

class HashTable<K, V> {
    private static final int SIZE = 10000;
    private List<List<Entry<K, V>>> table;

    public HashTable() {
        table = new ArrayList<>(SIZE);
        for (int i = 0; i < SIZE; i++) {
            table.add(null);
        }
    }

    private int hash(K key) {
        return Math.abs(key.hashCode()) % SIZE;
    }

    public void insert(K key, V value) {
        int hashIndex = hash(key);
        if (table.get(hashIndex) == null) {
            table.set(hashIndex, new ArrayList<>());
        }
        table.get(hashIndex).add(new Entry<>(key, value));
    }

    public void delete(K key) {
        int hashIndex = hash(key);
        if (table.get(hashIndex) != null) {
            List<Entry<K, V>> bucket = table.get(hashIndex);
            for (int i = 0; i < bucket.size(); i++) {
                if (bucket.get(i).key.equals(key)) {
                    bucket.remove(i);
                    break;
                }
            }
        }
    }

    public V search(K key) {
        int hashIndex = hash(key);
        if (table.get(hashIndex) != null) {
            List<Entry<K, V>> bucket = table.get(hashIndex);
            for (Entry<K, V> entry : bucket) {
                if (entry.key.equals(key)) {
                    return entry.value;
                }
            }
        }
        return null;
    }

    private static class Entry<K, V> {
        private K key;
        private V value;

        public Entry(K key, V value) {
            this.key = key;
            this.value = value;
        }
    }
}