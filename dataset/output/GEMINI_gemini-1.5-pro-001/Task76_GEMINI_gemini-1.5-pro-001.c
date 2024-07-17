#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define USER_AGENT "Mozilla/5.0"

struct MemoryStruct {
  char *memory;
  size_t size;
};

static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;

  char *ptr = realloc(mem->memory, mem->size + realsize + 1);
  if (ptr == NULL) {
    fprintf(stderr, "Not enough memory (realloc returned NULL)
");
    return 0; 
  }

  mem->memory = ptr;
  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;

  return realsize;
}

char *get_page_title(const char *url) {
  CURL *curl_handle;
  CURLcode res;
  struct MemoryStruct chunk;

  chunk.memory = malloc(1);
  chunk.size = 0; 

  curl_global_init(CURL_GLOBAL_ALL);
  curl_handle = curl_easy_init();
  curl_easy_setopt(curl_handle, CURLOPT_URL, url);
  curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, USER_AGENT);
  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_callback);
  curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);
  curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L); 
  res = curl_easy_perform(curl_handle);

  if (res != CURLE_OK) {
    fprintf(stderr, "curl_easy_perform() failed: %s
", curl_easy_strerror(res));
    curl_easy_cleanup(curl_handle);
    free(chunk.memory);
    return NULL;
  }

  char *title_start = strstr(chunk.memory, "<title>");
  if (title_start == NULL) {
    free(chunk.memory);
    curl_easy_cleanup(curl_handle);
    return NULL;
  }
  title_start += 7;

  char *title_end = strstr(title_start, "</title>");
  if (title_end == NULL) {
    free(chunk.memory);
    curl_easy_cleanup(curl_handle);
    return NULL;
  }

  size_t title_len = title_end - title_start;
  char *title = malloc(title_len + 1);
  strncpy(title, title_start, title_len);
  title[title_len] = '\0';

  curl_easy_cleanup(curl_handle);
  free(chunk.memory);

  return title;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <url>
", argv[0]);
    return 1;
  }

  char *title = get_page_title(argv[1]);

  if (title != NULL) {
    printf("%s
", title);
    free(title);
  } else {
    printf("Title not found.
");
  }

  return 0;
}