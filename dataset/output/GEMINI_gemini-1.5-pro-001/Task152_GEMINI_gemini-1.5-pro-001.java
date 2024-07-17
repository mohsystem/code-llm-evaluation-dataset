class HashTable {
    private int size;
    private LinkedList<Entry>[] table;

    public HashTable(int size) {
        this.size = size;
        this.table = new LinkedList[size];
    }

    public int size() {
        return size;
    }

    public boolean containsKey(int key) {
        int index = hash(key) % size;
        if (table[index] != null) {
            for (Entry entry : table[index]) {
                if (entry.key == key) {
                    return true;
                }
            }
        }
        return false;
    }

    public void insert(int key, int value) {
        int index = hash(key) % size;
        if (table[index] == null) {
            table[index] = new LinkedList<>();
        }
        table[index].add(new Entry(key, value));
    }

    public void delete(int key) {
        int index = hash(key) % size;
        if (table[index] != null) {
            table[index].removeIf(entry -> entry.key == key);
        }
    }

    public Integer search(int key) {
        int index = hash(key) % size;
        if (table[index] != null) {
            for (Entry entry : table[index]) {
                if (entry.key == key) {
                    return entry.value;
                }
            }
        }
        return null;
    }

    private int hash(int key) {
        return key;
    }

    private static class Entry {
        int key;
        int value;

        Entry(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }
}