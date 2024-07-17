public class HashTable {
    private int size;
    private Node[] table;

    public HashTable(int size) {
        this.size = size;
        this.table = new Node[size];
    }

    private int hash(int key) {
        return key % size;
    }

    public void insert(int key, String value) {
        int index = hash(key);
        if (table[index] == null) {
            table[index] = new Node(key, value);
        } else {
            Node node = table[index];
            while (node != null) {
                if (node.key == key) {
                    node.value = value;
                    break;
                }
                if (node.next == null) {
                    node.next = new Node(key, value);
                    break;
                }
                node = node.next;
            }
        }
    }

    public void delete(int key) {
        int index = hash(key);
        if (table[index] != null) {
            Node node = table[index];
            Node prev = null;
            while (node != null) {
                if (node.key == key) {
                    if (prev == null) {
                        table[index] = node.next;
                    } else {
                        prev.next = node.next;
                    }
                    break;
                }
                prev = node;
                node = node.next;
            }
        }
    }

    public String search(int key) {
        int index = hash(key);
        if (table[index] != null) {
            Node node = table[index];
            while (node != null) {
                if (node.key == key) {
                    return node.value;
                }
                node = node.next;
            }
        }
        return null;
    }

    private static class Node {
        int key;
        String value;
        Node next;

        public Node(int key, String value) {
            this.key = key;
            this.value = value;
        }
    }

    public static void main(String[] args) {
        HashTable ht = new HashTable(10);
        ht.insert(1, "one");
        ht.insert(11, "eleven");
        ht.insert(21, "twenty one");
        System.out.println(ht.search(1));  // Output: one
        System.out.println(ht.search(11));  // Output: eleven
        System.out.println(ht.search(21));  // Output: twenty one
        ht.delete(11);
        System.out.println(ht.search(11));  // Output: null
    }
}