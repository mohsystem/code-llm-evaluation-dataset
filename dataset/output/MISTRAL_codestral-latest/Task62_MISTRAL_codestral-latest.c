// C language does not have built-in JSON parsing library.
// You would need to use a third-party library like jansson or cJSON.
// Here is an example using jansson:

#include <jansson.h>
#include <string.h>

char* getRootElement(const char* jsonString) {
    json_t* jsonData = json_loads(jsonString, 0, NULL);
    const char* key = json_object_iter_key(json_object_iter(jsonData));
    char* rootElement = strdup(key);
    json_decref(jsonData);
    return rootElement;
}