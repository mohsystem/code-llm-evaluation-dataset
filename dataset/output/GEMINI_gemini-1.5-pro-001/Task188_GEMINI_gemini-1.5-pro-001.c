#include <stdio.h>
#include <pthread.h>

typedef struct {
    int n;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int turn;
} FooBar;

void foo(FooBar* obj) {
    for (int i = 0; i < obj->n; i++) {
        pthread_mutex_lock(&obj->mutex);
        while (obj->turn != 0) {
            pthread_cond_wait(&obj->cond, &obj->mutex);
        }
        printf("foo");
        obj->turn = 1;
        pthread_cond_signal(&obj->cond);
        pthread_mutex_unlock(&obj->mutex);
    }
}

void bar(FooBar* obj) {
    for (int i = 0; i < obj->n; i++) {
        pthread_mutex_lock(&obj->mutex);
        while (obj->turn != 1) {
            pthread_cond_wait(&obj->cond, &obj->mutex);
        }
        printf("bar");
        obj->turn = 0;
        pthread_cond_signal(&obj->cond);
        pthread_mutex_unlock(&obj->mutex);
    }
}

int main() {
    FooBar obj = { 1, PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER, 0 };
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, (void*)foo, &obj);
    pthread_create(&thread2, NULL, (void*)bar, &obj);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}