#include <stdio.h>
#include <pthread.h>

typedef struct {
    int n;
    int foo_done;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} FooBar;

void FooBar_init(FooBar* fb, int n) {
    fb->n = n;
    fb->foo_done = 0;
    pthread_mutex_init(&fb->mutex, NULL);
    pthread_cond_init(&fb->cond, NULL);
}

void* foo(void* arg) {
    FooBar* fb = (FooBar*)arg;
    for (int i = 0; i < fb->n; i++) {
        pthread_mutex_lock(&fb->mutex);
        printf("foo");
        fb->foo_done = 1;
        pthread_cond_signal(&fb->cond);
        while (fb->foo_done) {
            pthread_cond_wait(&fb->cond, &fb->mutex);
        }
        pthread_mutex_unlock(&fb->mutex);
    }
    return NULL;
}

void* bar(void* arg) {
    FooBar* fb = (FooBar*)arg;
    for (int i = 0; i < fb->n; i++) {
        pthread_mutex_lock(&fb->mutex);
        while (!fb->foo_done) {
            pthread_cond_wait(&fb->cond, &fb->mutex);
        }
        printf("bar");
        fb->foo_done = 0;
        pthread_cond_signal(&fb->cond);
        pthread_mutex_unlock(&fb->mutex);
    }
    return NULL;
}

int main() {
    int n = 2; // Change as needed
    FooBar fb;
    FooBar_init(&fb, n);

    pthread_t threadA, threadB;
    pthread_create(&threadA, NULL, foo, &fb);
    pthread_create(&threadB, NULL, bar, &fb);

    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);

    pthread_mutex_destroy(&fb.mutex);
    pthread_cond_destroy(&fb->cond);
    
    return 0;
}