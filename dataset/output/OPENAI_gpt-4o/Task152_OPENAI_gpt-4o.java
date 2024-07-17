import java.util.LinkedList;

class HashTable {
    private class HashNode {
        int key;
        String value;

        HashNode(int key, String value) {
            this.key = key;
            this.value = value;
        }
    }

    private int size;
    private LinkedList<HashNode>[] table;

    @SuppressWarnings("unchecked")
    public HashTable(int size) {
        this.size = size;
        table = new LinkedList[size];
        for (int i = 0; i < size; i++) {
            table[i] = new LinkedList<>();
        }
    }

    private int hashFunction(int key) {
        return key % size;
    }

    public void insert(int key, String value) {
        int hashKey = hashFunction(key);
        for (HashNode node : table[hashKey]) {
            if (node.key == key) {
                node.value = value;
                return;
            }
        }
        table[hashKey].add(new HashNode(key, value));
    }

    public void delete(int key) {
        int hashKey = hashFunction(key);
        table[hashKey].removeIf(node -> node.key == key);
    }

    public String search(int key) {
        int hashKey = hashFunction(key);
        for (HashNode node : table[hashKey]) {
            if (node.key == key) {
                return node.value;
            }
        }
        return null;
    }

    public static void main(String[] args) {
        HashTable ht = new HashTable(10);
        ht.insert(1, "one");
        ht.insert(2, "two");
        System.out.println(ht.search(1)); // should print "one"
        ht.delete(1);
        System.out.println(ht.search(1)); // should print "null"
    }
}