#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <dirent.h>
#include <string.h>

pthread_mutex_t lock;

void* process_file(void* file_path) {
    pthread_mutex_lock(&lock);
    FILE* file = fopen((char*)file_path, "r");
    if (file) {
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            printf("Processed by %ld: %s", pthread_self(), line);
        }
        fclose(file);
    } else {
        fprintf(stderr, "Unable to open file %s\n", (char*)file_path);
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

void process_directory(const char* directory_path) {
    DIR* dir = opendir(directory_path);
    if (!dir) {
        perror("opendir");
        return;
    }
    struct dirent* entry;
    pthread_t threads[256];
    int thread_count = 0;

    while ((entry = readdir(dir)) != NULL) {
        char file_path[1024];
        snprintf(file_path, sizeof(file_path), "%s/%s", directory_path, entry->d_name);
        if (entry->d_type == DT_REG) {
            pthread_create(&threads[thread_count++], NULL, process_file, strdup(file_path));
        }
    }
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
    closedir(dir);
}

int main() {
    char directory[] = "path_to_directory";
    if (pthread_mutex_init(&lock, NULL) != 0) {
        fprintf(stderr, "Mutex init failed\n");
        return 1;
    }
    process_directory(directory);
    pthread_mutex_destroy(&lock);
    return 0;
}