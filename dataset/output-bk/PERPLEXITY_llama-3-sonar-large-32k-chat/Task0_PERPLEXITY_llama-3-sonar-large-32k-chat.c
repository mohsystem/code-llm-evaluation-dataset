#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* processFile(void* arg) {
    char* filename = (char*) arg;
    pthread_mutex_lock(&lock);
    printf("Processing file: %s
", filename);
    // Simulate file processing
    sleep(1);
    pthread_mutex_unlock(&lock);
    free(arg);
    return NULL;
}

int main() {
    DIR* dir;
    struct dirent* ent;
    pthread_t threads[256];
    int i = 0;

    dir = opendir("files");
    if (dir != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                char* filename = malloc(strlen(ent->d_name) + 1);
                strcpy(filename, ent->d_name);
                pthread_create(&threads[i], NULL, processFile, (void*) filename);
                i++;
            }
        }
        closedir(dir);
    }

    for (int j = 0; j < i; j++) {
        pthread_join(threads[j], NULL);
    }

    return 0;
}