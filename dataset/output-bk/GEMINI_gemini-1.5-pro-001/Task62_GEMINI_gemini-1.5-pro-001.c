#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure to represent a JSON value
typedef struct {
    enum { JSON_OBJECT, JSON_ARRAY, JSON_STRING, JSON_NUMBER, JSON_BOOLEAN, JSON_NULL } type;
    union {
        struct { char *keys; char *values; int count; } object;
        struct { char **elements; int count; } array;
        char *string;
        double number;
        bool boolean;
    } value;
} JSONValue;

// Function to parse a JSON string
JSONValue *parse_json(const char *json);

// Function to free the memory allocated for a JSON value
void free_json(JSONValue *value);

// Function to parse a JSON object
JSONValue *parse_object(const char *json) {
    JSONValue *object = malloc(sizeof(JSONValue));
    object->type = JSON_OBJECT;
    object->value.object.keys = NULL;
    object->value.object.values = NULL;
    object->value.object.count = 0;
    return object;
}

// Function to parse a JSON array
JSONValue *parse_array(const char *json) {
    JSONValue *array = malloc(sizeof(JSONValue));
    array->type = JSON_ARRAY;
    array->value.array.elements = NULL;
    array->value.array.count = 0;
    return array;
}

// Function to parse a JSON string
JSONValue *parse_string(const char *json) {
    JSONValue *string = malloc(sizeof(JSONValue));
    string->type = JSON_STRING;
    string->value.string = strdup(json);
    return string;
}

// Function to parse a JSON number
JSONValue *parse_number(const char *json) {
    JSONValue *number = malloc(sizeof(JSONValue));
    number->type = JSON_NUMBER;
    number->value.number = atof(json);
    return number;
}

// Function to parse a JSON boolean
JSONValue *parse_boolean(const char *json) {
    JSONValue *boolean = malloc(sizeof(JSONValue));
    boolean->type = JSON_BOOLEAN;
    boolean->value.boolean = strcmp(json, "true") == 0;
    return boolean;
}

// Function to parse a JSON null
JSONValue *parse_null(const char *json) {
    JSONValue *null = malloc(sizeof(JSONValue));
    null->type = JSON_NULL;
    return null;
}

// Function to parse a JSON value
JSONValue *parse_json(const char *json) {
    while (*json == ' ' || *json == '\t' || *json == '
' || *json == '\r') {
        json++;
    }
    if (*json == '{') {
        return parse_object(json);
    } else if (*json == '[') {
        return parse_array(json);
    } else if (*json == '"') {
        return parse_string(json);
    } else if (*json == '-' || (*json >= '0' && *json <= '9')) {
        return parse_number(json);
    } else if (strncmp(json, "true", 4) == 0) {
        return parse_boolean(json);
    } else if (strncmp(json, "false", 5) == 0) {
        return parse_boolean(json);
    } else if (strncmp(json, "null", 4) == 0) {
        return parse_null(json);
    } else {
        return NULL;
    }
}

// Function to free the memory allocated for a JSON value
void free_json(JSONValue *value) {
    if (value == NULL) {
        return;
    }
    switch (value->type) {
        case JSON_OBJECT:
            free(value->value.object.keys);
            free(value->value.object.values);
            break;
        case JSON_ARRAY:
            for (int i = 0; i < value->value.array.count; i++) {
                free_json(value->value.array.elements[i]);
            }
            free(value->value.array.elements);
            break;
        case JSON_STRING:
            free(value->value.string);
            break;
        default:
            break;
    }
    free(value);
}

int main() {
    char *jsonString = "{\"name\":\"John\", \"age\":30, \"city\":\"New York\"}";
    JSONValue *root = parse_json(jsonString);

    if (root != NULL) {
        // Process the parsed JSON structure
        printf("JSON parsing successful!
");
        free_json(root);
    } else {
        printf("JSON parsing failed!
");
    }

    return 0;
}