
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <dirent.h>
#include <sys/stat.h>

#define DIRECTORY_PATH "shared_directory"
#define NUM_THREADS 4
#define MAX_FILENAME 256

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* process_files(void* arg) {
    while (1) {
        DIR* dir;
        struct dirent* entry;
        char filename[MAX_FILENAME];

        pthread_mutex_lock(&mutex);
        dir = opendir(DIRECTORY_PATH);
        if (dir == NULL) {
            pthread_mutex_unlock(&mutex);
            continue;
        }

        while ((entry = readdir(dir)) != NULL) {
            if (entry->d_type == DT_REG) {
                snprintf(filename, sizeof(filename), "%s/%s", DIRECTORY_PATH, entry->d_name);
                break;
            }
        }

        closedir(dir);
        pthread_mutex_unlock(&mutex);

        if (entry == NULL) {
            sleep(1);
            continue;
        }

        printf("Processing file: %s by thread: %ld\
", filename, (long)pthread_self());
        // Simulating file processing
        sleep(2);

        // Delete the processed file
        remove(filename);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i;

    mkdir(DIRECTORY_PATH, 0777);

    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, process_files, NULL) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
