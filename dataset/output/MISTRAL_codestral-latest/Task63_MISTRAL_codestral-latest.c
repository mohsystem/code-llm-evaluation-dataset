// C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <base64.h>
#include <json-c/json.h>

char* processRequest(const char* rawData) {
    int decodedLength = base64_decodestate_out_length(strlen(rawData));
    char* decodedString = malloc(decodedLength + 1);
    base64_decode_block(rawData, strlen(rawData), decodedString);
    decodedString[decodedLength] = '\0';

    json_object* jobj = json_tokener_parse(decodedString);
    char* serializedData = strdup(json_object_to_json_string_ext(jobj, JSON_C_TO_STRING_PLAIN));

    free(decodedString);
    json_object_put(jobj);

    return serializedData;
}