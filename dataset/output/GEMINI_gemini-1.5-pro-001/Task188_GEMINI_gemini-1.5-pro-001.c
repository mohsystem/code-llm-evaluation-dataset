#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t cond;
int count = 0;
int n;

void *foo(void *arg) {
    for (int i = 0; i < n; i++) {
        pthread_mutex_lock(&mutex);
        while (count % 2 != 0) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("foo");
        count++;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *bar(void *arg) {
    for (int i = 0; i < n; i++) {
        pthread_mutex_lock(&mutex);
        while (count % 2 == 0) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("bar");
        count++;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    n = 2; 
    pthread_t thread1, thread2;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&thread1, NULL, foo, NULL);
    pthread_create(&thread2, NULL, bar, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}