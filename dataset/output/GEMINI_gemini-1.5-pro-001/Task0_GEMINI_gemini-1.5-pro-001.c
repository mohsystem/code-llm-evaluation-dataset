#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <dirent.h>

#define MAX_PATH_LEN 256

// Structure to hold file path and mutex
typedef struct {
    char file_path[MAX_PATH_LEN];
    pthread_mutex_t mutex;
} FileData;

// Global array to store file data and mutexes (replace with dynamic allocation if needed)
FileData file_data[1024];
int file_count = 0;

// Function to process a single file
void* process_file(void* arg) {
    FileData* data = (FileData*)arg;
    
    // Acquire mutex for the file
    pthread_mutex_lock(&data->mutex);

    // Simulate file processing
    printf("Thread %lu is processing file: %s\n", pthread_self(), data->file_path);
    // Add your file processing logic here

    // Release mutex
    pthread_mutex_unlock(&data->mutex);

    pthread_exit(NULL);
}

int main() {
    char directory_path[] = "path/to/your/directory"; // Replace with your directory path

    // Open directory for reading
    DIR* dir = opendir(directory_path);
    if (dir == NULL) {
        perror("Error opening directory");
        return 1;
    }

    // Read directory entries
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip current and parent directories
        }

        // Create full file path
        snprintf(file_data[file_count].file_path, MAX_PATH_LEN, "%s/%s", directory_path, entry->d_name);

        // Initialize mutex
        pthread_mutex_init(&file_data[file_count].mutex, NULL);

        // Create and start thread for file processing
        pthread_t thread;
        pthread_create(&thread, NULL, process_file, &file_data[file_count]);
        pthread_detach(thread); 

        file_count++;
    }

    // Close directory
    closedir(dir);

    // Keep the main thread alive to allow detached threads to complete (replace with proper synchronization)
    while (1) {
        sleep(1);
    }

    return 0;
}