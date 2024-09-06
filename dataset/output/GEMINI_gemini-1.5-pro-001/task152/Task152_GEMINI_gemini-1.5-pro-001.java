import java.util.LinkedList;

class HashTable {
    private int size;
    private LinkedList<Entry>[] table;

    public HashTable(int size) {
        this.size = size;
        this.table = new LinkedList[size];
        for (int i = 0; i < size; i++) {
            table[i] = new LinkedList<>();
        }
    }

    @Override
    public String toString() {
        return java.util.Arrays.toString(table);
    }

    private int _hash(Object key) {
        return Math.abs(key.hashCode()) % size;
    }

    public void insert(Object key, Object value) {
        int index = _hash(key);
        table[index].add(new Entry(key, value));
    }

    public boolean delete(Object key) {
        int index = _hash(key);
        return table[index].removeIf(entry -> entry.key.equals(key));
    }

    public Object search(Object key) {
        int index = _hash(key);
        for (Entry entry : table[index]) {
            if (entry.key.equals(key)) {
                return entry.value;
            }
        }
        return null;
    }

    private static class Entry {
        Object key;
        Object value;

        Entry(Object key, Object value) {
            this.key = key;
            this.value = value;
        }
    }
}