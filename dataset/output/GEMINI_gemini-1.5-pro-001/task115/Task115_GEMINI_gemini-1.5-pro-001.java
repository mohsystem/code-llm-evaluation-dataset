class PackedData {
    int value;
    int flag1;
    int flag2;
    int value2;

    public PackedData(int value) {
        this.value = value;
        this.flag1 = (value >> 0) & 0x1;
        this.flag2 = (value >> 1) & 0x3;
        this.value2 = (value >> 3) & 0x1F;
    }
}