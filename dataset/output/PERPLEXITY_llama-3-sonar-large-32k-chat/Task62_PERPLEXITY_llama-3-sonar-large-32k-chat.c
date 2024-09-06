// Note: C does not have a built-in JSON parsing library. You need to use a third-party library.
// This code uses the parson library, which is a lightweight JSON library for C.
// You need to install it before compiling the code.

#include <parson.h>
#include <stdio.h>

int main() {
    const char *jsonString = "{\"name\":\"John\", \"age\":30, \"city\":\"New York\"}";
    JSON_Value *jsonValue = json_parse_string(jsonString);
    JSON_Object *jsonObject = json_value_get_object(jsonValue);
    printf("%s\n", json_type_to_string(json_value_get_type(jsonValue)));
    json_value_free(jsonValue);
    return 0;
}