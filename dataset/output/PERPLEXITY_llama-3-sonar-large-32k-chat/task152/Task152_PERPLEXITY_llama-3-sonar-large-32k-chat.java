class HashTable {
    private int size;
    private int[] slots;
    private String[] data;

    public HashTable(int size) {
        this.size = size;
        this.slots = new int[size];
        this.data = new String[size];
    }

    public void put(int key, String value) {
        int hashValue = hashFunction(key, size);

        if (slots[hashValue] == 0) {
            slots[hashValue] = key;
            data[hashValue] = value;
        } else {
            if (slots[hashValue] == key) {
                data[hashValue] = value; // replace
            } else {
                int nextSlot = rehash(hashValue, size);
                while (slots[nextSlot] != 0 && slots[nextSlot] != key) {
                    nextSlot = rehash(nextSlot, size);
                }

                if (slots[nextSlot] == 0) {
                    slots[nextSlot] = key;
                    data[nextSlot] = value;
                } else {
                    data[nextSlot] = value; // replace
                }
            }
        }
    }

    public int hashFunction(int key, int size) {
        return key % size;
    }

    public int rehash(int oldHash, int size) {
        return (oldHash + 1) % size;
    }

    public String get(int key) {
        int startSlot = hashFunction(key, size);

        String value = null;
        boolean stop = false;
        boolean found = false;
        int position = startSlot;
        while (slots[position] != 0 && !found && !stop) {
            if (slots[position] == key) {
                found = true;
                value = data[position];
            } else {
                position = rehash(position, size);
                if (position == startSlot) {
                    stop = true;
                }
            }
        }
        return value;
    }

    public static void main(String[] args) {
        HashTable h = new HashTable(11);
        h.put(54, "cat");
        h.put(26, "dog");
        h.put(93, "lion");
        h.put(17, "tiger");
        h.put(77, "bird");
        h.put(31, "cow");
        h.put(44, "goat");
        h.put(55, "pig");
        h.put(20, "chicken");

        for (int i = 0; i < h.slots.length; i++) {
            System.out.print(h.slots[i] + " ");
        }
        System.out.println();

        for (int i = 0; i < h.data.length; i++) {
            System.out.print(h.data[i] + " ");
        }
        System.out.println();

        System.out.println(h.get(20));

        System.out.println(h.get(17));
        h.put(20, "duck");
        System.out.println(h.get(20));
        System.out.println(h.get(99));
    }
}