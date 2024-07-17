#include <json-c/json.h>

json_object* deserialize_json(const char* json_data) {
    return json_tokener_parse(json_data);
}