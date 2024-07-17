class BitFieldsExample {
    public static void main(String[] args) {
        class BitFields {
            private int field1 : 1;
            private int field2 : 2;
            private int field3 : 3;

            public BitFields(int field1, int field2, int field3) {
                this.field1 = field1;
                this.field2 = field2;
                this.field3 = field3;
            }

            public void displayFields() {
                System.out.println("Field1: " + field1);
                System.out.println("Field2: " + field2);
                System.out.println("Field3: " + field3);
            }
        }

        BitFields bf = new BitFields(1, 2, 5);
        bf.displayFields();
    }
}