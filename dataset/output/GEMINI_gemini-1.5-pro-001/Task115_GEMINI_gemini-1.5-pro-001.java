public class Main {
    public static class Data {
        public int field1;
        public int field2;

        public Data(int field1, int field2) {
            this.field1 = field1;
            this.field2 = field2;
        }
    }

    public static void main(String[] args) {
        Data data = new Data(2, 20);
        System.out.println("field1: " + data.field1);
        System.out.println("field2: " + data.field2);
    }
}