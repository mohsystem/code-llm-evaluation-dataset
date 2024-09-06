/* C language does not have built-in support for serialization/deserialization.
   This example uses a custom function to deserialize a simple integer. */

#include <stdio.h>
#include <stdint.h>

int32_t deserialize_data(const char* data) {
    int32_t result;
    memcpy(&result, data, sizeof(result));
    return result;
}