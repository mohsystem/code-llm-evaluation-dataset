#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>

sem_t fooSemaphore;
sem_t barSemaphore;
int n;

void* foo(void* arg) {
    for (int i = 0; i < n; i++) {
        sem_wait(&fooSemaphore);
        printf("foo");
        sem_post(&barSemaphore);
    }
    return NULL;
}

void* bar(void* arg) {
    for (int i = 0; i < n; i++) {
        sem_wait(&barSemaphore);
        printf("bar");
        sem_post(&fooSemaphore);
    }
    return NULL;
}

int main(int argc, char* argv[]) {
    n = atoi(argv[1]);
    sem_init(&fooSemaphore, 0, 1);
    sem_init(&barSemaphore, 0, 0);

    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, foo, NULL);
    pthread_create(&thread2, NULL, bar, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}