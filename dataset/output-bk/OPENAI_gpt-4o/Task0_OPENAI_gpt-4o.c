#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <dirent.h>
#include <unistd.h>

#define NUM_THREADS 10

pthread_mutex_t lock;

void *process_file(void *filename) {
    pthread_mutex_lock(&lock);
    printf("Processing %s by thread %ld
", (char *)filename, pthread_self());
    sleep(1); // Simulate file processing
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    DIR *dir;
    struct dirent *ent;
    int thread_index = 0;

    if (pthread_mutex_init(&lock, NULL) != 0) {
        perror("Mutex init has failed");
        return 1;
    }

    if ((dir = opendir("shared_directory")) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_REG) {
                if (pthread_create(&threads[thread_index++ % NUM_THREADS], NULL, process_file, ent->d_name) != 0) {
                    perror("Failed to create thread");
                }
                sleep(0.1); // Control creation speed
            }
        }
        closedir(dir);
    } else {
        perror("Unable to open directory");
        return 1;
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&lock);
    return 0;
}