#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <json-c/json.h>

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

json_object *read_json_from_url(const char *url) {
    CURL *curl;
    FILE *fp;
    char *data;
    long data_size;
    json_object *jobj;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        fp = fopen("temp.json", "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    curl_global_cleanup();

    fp = fopen("temp.json", "rb");
    fseek(fp, 0, SEEK_END);
    data_size = ftell(fp);
    rewind(fp);

    data = (char *)malloc(sizeof(char) * (data_size + 1));
    fread(data, sizeof(char), data_size, fp);
    fclose(fp);

    jobj = json_tokener_parse(data);
    free(data);

    remove("temp.json");

    return jobj;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Please provide a URL as a command line argument.
");
        return 1;
    }

    const char *url = argv[1];
    json_object *jobj = read_json_from_url(url);
    printf("%s
", json_object_to_json_string_ext(jobj, JSON_C_TO_STRING_PRETTY));
    json_object_put(jobj);

    return 0;
}