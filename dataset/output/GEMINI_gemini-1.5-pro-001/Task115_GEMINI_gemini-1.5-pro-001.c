#include <stdio.h>

struct PackedData {
    int value : 8;
    int flag1 : 1;
    int flag2 : 2;
    int value2 : 5;
};