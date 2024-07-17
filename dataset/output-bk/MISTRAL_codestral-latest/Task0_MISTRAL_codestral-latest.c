#include <pthread.h>
#include <semaphore.h>
#include <dirent.h>
#include <stdio.h>

sem_t semaphore;

void *process_file(void *filename) {
    sem_wait(&semaphore);
    // Process the file here
    sem_post(&semaphore);
    pthread_exit(NULL);
}

void process_files(char *path) {
    DIR *d;
    struct dirent *dir;
    d = opendir(path);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            pthread_t thread;
            pthread_create(&thread, NULL, process_file, dir->d_name);
        }
        closedir(d);
    }
}