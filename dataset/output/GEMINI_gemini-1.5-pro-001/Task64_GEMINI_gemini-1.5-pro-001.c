#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Structure to hold the downloaded data
struct MemoryStruct {
  char *memory;
  size_t size;
};

// Callback function to write downloaded data to the memory struct
static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;

  // Reallocate memory if needed
  char *ptr = realloc(mem->memory, mem->size + realsize + 1);
  if (ptr == NULL) {
    fprintf(stderr, "Not enough memory (realloc returned NULL)
");
    return 0; // Indicate failure to libcurl
  }

  mem->memory = ptr;
  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0; // Null-terminate the string

  return realsize;
}

// Function to fetch JSON from a URL
char *fetch_json(const char *url) {
  CURL *curl;
  CURLcode res;
  struct MemoryStruct chunk;

  // Initialize curl
  curl = curl_easy_init();
  if (curl) {
    // Set up the curl request
    chunk.memory = malloc(1); // Will be grown as needed
    chunk.size = 0; 

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

    // Perform the request
    res = curl_easy_perform(curl);

    // Check for errors
    if (res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s
", curl_easy_strerror(res));
      curl_easy_cleanup(curl);
      free(chunk.memory);
      return NULL;
    }

    // Cleanup
    curl_easy_cleanup(curl);

    return chunk.memory;
  } else {
    fprintf(stderr, "Failed to initialize libcurl
");
    return NULL;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <url>
", argv[0]);
    return 1;
  }

  char *json_data = fetch_json(argv[1]);
  if (json_data) {
    printf("%s
", json_data);
    free(json_data);
  }

  return 0;
}