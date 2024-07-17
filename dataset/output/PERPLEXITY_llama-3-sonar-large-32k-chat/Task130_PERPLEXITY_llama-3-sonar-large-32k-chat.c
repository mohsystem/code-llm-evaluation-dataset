code here:
#include <stdio.h>
#include <string.h>

int main() {
    char origin[1024];
    if (getenv("HTTP_ORIGIN") != NULL) {
        strcpy(origin, getenv("HTTP_ORIGIN"));
        printf("Access-Control-Allow-Origin: %s
", origin);
        printf("Access-Control-Allow-Headers: Content-Type, Authorization
");
        printf("Access-Control-Allow-Methods: GET, PUT, POST, DELETE, OPTIONS
");
    }
    printf("Content-Type: application/json

");
    printf("{\"data\": \"Hello, World.\"}
");
    return 0;
}