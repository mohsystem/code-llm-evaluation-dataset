#include <iostream>

class BitFieldExample {
private:
    unsigned int bitField : 32;

public:
    unsigned int getBitField() {
        return bitField;
    }

    void setBitField(unsigned int bitField) {
        this->bitField = bitField;
    }

    bool getBit(int position) {
        return ((bitField & (1 << position)) != 0);
    }

    void setBit(int position, bool value) {
        if (value)
            bitField |= (1 << position);
        else
            bitField &= ~(1 << position);
    }
};