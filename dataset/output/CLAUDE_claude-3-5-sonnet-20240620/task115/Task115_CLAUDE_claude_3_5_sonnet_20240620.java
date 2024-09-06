
public class Task115_CLAUDE_claude_3_5_sonnet_20240620 {
    private byte data;

    public int getField1() {
        return data & 0b11;
    }

    public void setField1(int value) {
        data = (byte) ((data & ~0b11) | (value & 0b11));
    }

    public int getField2() {
        return (data >> 2) & 0b111;
    }

    public void setField2(int value) {
        data = (byte) ((data & ~(0b111 << 2)) | ((value & 0b111) << 2));
    }

    public boolean getField3() {
        return ((data >> 5) & 0b1) != 0;
    }

    public void setField3(boolean value) {
        data = (byte) ((data & ~(0b1 << 5)) | ((value ? 1 : 0) << 5));
    }
}
