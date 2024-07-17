#include <stdio.h>
#include <string.h>
#include <jansson.h>

int main() {
  char data[1024];

  printf("Enter the data to deserialize: ");
  fgets(data, sizeof(data), stdin);

  // Remove trailing newline from fgets
  data[strcspn(data, "
")] = 0;

  json_error_t error;
  json_t *root = json_loads(data, 0, &error);

  if (!root) {
    fprintf(stderr, "Error: Invalid JSON data: %s
", error.text);
    return 1;
  }

  char *json_string = json_dumps(root, JSON_INDENT(2));
  printf("Deserialized data: 
%s
", json_string);

  free(json_string);
  json_decref(root);

  return 0;
}