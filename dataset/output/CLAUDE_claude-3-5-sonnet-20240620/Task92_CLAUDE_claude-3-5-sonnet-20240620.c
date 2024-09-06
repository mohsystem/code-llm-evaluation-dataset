
#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int currentCounter;
    int maxCounter;
    pthread_mutex_t mutex;
} SharedResource;

void initSharedResource(SharedResource* resource, int maxCounter) {
    resource->currentCounter = 0;
    resource->maxCounter = maxCounter;
    pthread_mutex_init(&resource->mutex, NULL);
}

bool accessResource(SharedResource* resource, int threadId) {
    bool accessed = false;
    if (resource->currentCounter <= resource->maxCounter) {
        pthread_mutex_lock(&resource->mutex);
        if (resource->currentCounter <= resource->maxCounter) {
            resource->currentCounter++;
            printf("Thread %d accessing. Current counter: %d\\n", threadId, resource->currentCounter);
            accessed = resource->currentCounter <= resource->maxCounter;
        }
        pthread_mutex_unlock(&resource->mutex);
    }
    return accessed;
}

void* threadFunction(void* arg) {
    int* threadId = (int*)arg;
    SharedResource* resource = (SharedResource*)((void**)arg)[1];
    
    while (accessResource(resource, *threadId)) {
        // Continue accessing the resource
    }
    
    free(threadId);
    return NULL;
}

int main() {
    const int maxCounter = 10;
    const int numThreads = 5;
    SharedResource sharedResource;
    initSharedResource(&sharedResource, maxCounter);

    pthread_t threads[numThreads];
    for (int i = 0; i < numThreads; i++) {
        int* threadId = malloc(sizeof(int));
        *threadId = i;
        void* args[2] = {threadId, &sharedResource};
        pthread_create(&threads[i], NULL, threadFunction, args);
    }

    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&sharedResource.mutex);
    return 0;
}
