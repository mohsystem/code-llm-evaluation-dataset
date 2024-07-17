
public class BitFieldExample {
    public static class Flags {
        private int data;

        public boolean isFlag1() { return (data & 1) != 0; }
        public boolean isFlag2() { return (data & 2) != 0; }
        public boolean isFlag3() { return (data & 4) != 0; }
        public int getValue() { return (data >> 3) & 0x1F; }

        public void setFlag1(boolean value) {
            data = value ? (data | 1) : (data & ~1);
        }
        public void setFlag2(boolean value) {
            data = value ? (data | 2) : (data & ~2);
        }
        public void setFlag3(boolean value) {
            data = value ? (data | 4) : (data & ~4);
        }
        public void setValue(int value) {
            data = (data & 0x7) | ((value & 0x1F) << 3);
        }
    }

    public static void main(String[] args) {
        Flags flags = new Flags();
        flags.setFlag1(true);
        flags.setFlag2(false);
        flags.setFlag3(true);
        flags.setValue(15);

        System.out.println("Flag1: " + flags.isFlag1());
        System.out.println("Flag2: " + flags.isFlag2());
        System.out.println("Flag3: " + flags.isFlag3());
        System.out.println("Value: " + flags.getValue());
    }
}
