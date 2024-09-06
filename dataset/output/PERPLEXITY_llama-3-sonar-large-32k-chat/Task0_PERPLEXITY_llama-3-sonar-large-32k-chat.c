#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* processFile(void* arg) {
    char* fileName = (char*) arg;
    pthread_mutex_lock(&lock);
    printf("Processing file: %s\n", fileName);
    FILE* file = fopen(fileName, "r");
    if (file != NULL) {
        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("File content: %s", buffer);
        }
        fclose(file);
    }
    printf("Finished processing file: %s\n", fileName);
    pthread_mutex_unlock(&lock);
    free(arg);
    return NULL;
}

int main() {
    DIR* dir;
    struct dirent* ent;
    pthread_t threads[256];
    int i = 0;

    dir = opendir("./files");
    if (dir != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                char* fileName = malloc(strlen("./files/") + strlen(ent->d_name) + 1);
                sprintf(fileName, "./files/%s", ent->d_name);
                pthread_create(&threads[i], NULL, processFile, (void*) fileName);
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