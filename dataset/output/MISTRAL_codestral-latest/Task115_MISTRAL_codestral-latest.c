// C does not support bit fields in structs in the same way as C++ or Java.
// However, you can use bitwise operators to manipulate individual bits.
// Here's an example of how you might define a struct with three bits:

struct BitFields {
    unsigned char bits : 3;
};