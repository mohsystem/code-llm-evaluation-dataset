#include <stdio.h>
#include <pthread.h>

typedef struct {
    int max_counter;
    int current_counter;
    pthread_mutex_t lock;
} Counter;

void* access_resource(void* arg) {
    Counter* counter = (Counter*)arg;
    int thread_id = (int)pthread_self();

    pthread_mutex_lock(&counter->lock);
    if (counter->current_counter <= counter->max_counter) {
        counter->current_counter++;
        printf("Thread %d is accessing the currentCounter at the moment.\n", thread_id);
    }
    pthread_mutex_unlock(&counter->lock);

    return NULL;
}

int main() {
    int max_counter = 10;
    Counter counter = {max_counter, 0, PTHREAD_MUTEX_INITIALIZER};

    // Create and start multiple threads
    pthread_t threads[15];
    for (int i = 0; i < 15; i++) {
        pthread_create(&threads[i], NULL, access_resource, &counter);
    }

    // Wait for all threads to finish
    for (int i = 0; i < 15; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&counter.lock);

    return 0;
}