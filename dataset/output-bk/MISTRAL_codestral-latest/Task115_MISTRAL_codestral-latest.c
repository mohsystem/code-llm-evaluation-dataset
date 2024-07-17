#include <stdio.h>

typedef struct {
    unsigned int bitField : 32;
} BitFieldExample;

int getBit(BitFieldExample bfe, int position) {
    return ((bfe.bitField & (1 << position)) != 0);
}

void setBit(BitFieldExample *bfe, int position, int value) {
    if (value)
        bfe->bitField |= (1 << position);
    else
        bfe->bitField &= ~(1 << position);
}