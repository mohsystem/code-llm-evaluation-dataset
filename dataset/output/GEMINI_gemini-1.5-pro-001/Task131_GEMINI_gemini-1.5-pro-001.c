#include <stdio.h>
#include <string.h>
#include <cJSON.h>

int main() {
  char data[1024];
  printf("Enter the data to deserialize: ");
  fgets(data, sizeof(data), stdin);
  data[strcspn(data, "\n")] = 0; // remove trailing newline

  cJSON *deserialized_data = cJSON_Parse(data);

  if (deserialized_data == NULL) {
    const char *error_ptr = cJSON_GetErrorPtr();
    if (error_ptr != NULL) {
      fprintf(stderr, "Error deserializing data: %s\n", error_ptr);
    }
    return 1;
  }

  char *json_string = cJSON_Print(deserialized_data);
  printf("%s\n", json_string);

  cJSON_Delete(deserialized_data);
  free(json_string);

  return 0;
}