public class BitFieldExample {
    private int bitField;

    public BitFieldExample(int bitField) {
        this.bitField = bitField;
    }

    public int getBitField() {
        return bitField;
    }

    public void setBitField(int bitField) {
        this.bitField = bitField;
    }

    public boolean getBit(int position) {
        return ((bitField & (1 << position)) != 0);
    }

    public void setBit(int position, boolean value) {
        if (value)
            bitField |= (1 << position);
        else
            bitField &= ~(1 << position);
    }
}