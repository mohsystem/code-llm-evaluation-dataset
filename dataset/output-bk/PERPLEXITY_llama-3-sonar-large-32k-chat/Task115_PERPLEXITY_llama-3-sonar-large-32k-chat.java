class BitFields {
    int a;
    int b;
    int c;

    void setA(int val) {
        a = val;
    }

    void setB(int val) {
        b = val;
    }

    void setC(int val) {
        c = val;
    }

    void print() {
        System.out.println("a: " + a);
        System.out.println("b: " + b);
        System.out.println("c: " + c);
    }

    public static void main(String[] args) {
        BitFields bf = new BitFields();
        bf.setA(1);
        bf.setB(2);
        bf.setC(3);
        bf.print();
    }
}