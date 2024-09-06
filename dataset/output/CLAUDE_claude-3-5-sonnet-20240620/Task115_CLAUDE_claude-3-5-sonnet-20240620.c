
#include <stdint.h>

struct BitFields {
    uint8_t field1 : 2;
    uint8_t field2 : 3;
    uint8_t field3 : 1;
    uint8_t : 2;  // padding
};
