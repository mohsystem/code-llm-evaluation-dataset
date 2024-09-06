
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_FILES 100
#define MAX_FILENAME 256

typedef struct {
    char filename[MAX_FILENAME];
} FileTask;

FileTask fileTasks[MAX_FILES];
int taskCount = 0;
int processedCount = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* processFile(void* arg) {
    FileTask* task = (FileTask*)arg;
    
    pthread_mutex_lock(&mutex);
    if (processedCount >= taskCount) {
        pthread_mutex_unlock(&mutex);
        return NULL;
    }
    processedCount++;
    pthread_mutex_unlock(&mutex);

    printf("Processing file: %s\\n", task->filename);
    sleep(1); // Simulate file processing
    printf("Finished processing file: %s\\n", task->filename);

    return NULL;
}

int main() {
    DIR* dir;
    struct dirent* entry;
    pthread_t threads[MAX_FILES];

    dir = opendir("./files");
    if (dir == NULL) {
        perror("Unable to open directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL && taskCount < MAX_FILES) {
        if (strstr(entry->d_name, ".txt") != NULL) {
            strncpy(fileTasks[taskCount].filename, entry->d_name, MAX_FILENAME - 1);
            taskCount++;
        }
    }
    closedir(dir);

    for (int i = 0; i < taskCount; i++) {
        pthread_create(&threads[i], NULL, processFile, &fileTasks[i]);
    }

    for (int i = 0; i < taskCount; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
