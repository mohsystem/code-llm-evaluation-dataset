
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct {
    int n;
    sem_t foo_sem;
    sem_t bar_sem;
} FooBar;

void FooBar_init(FooBar* obj, int n) {
    obj->n = n;
    sem_init(&obj->foo_sem, 0, 1);
    sem_init(&obj->bar_sem, 0, 0);
}

void FooBar_free(FooBar* obj) {
    sem_destroy(&obj->foo_sem);
    sem_destroy(&obj->bar_sem);
}

void* foo(void* arg) {
    FooBar* obj = (FooBar*)arg;
    for (int i = 0; i < obj->n; i++) {
        sem_wait(&obj->foo_sem);
        printf("foo");
        sem_post(&obj->bar_sem);
    }
    return NULL;
}

void* bar(void* arg) {
    FooBar* obj = (FooBar*)arg;
    for (int i = 0; i < obj->n; i++) {
        sem_wait(&obj->bar_sem);
        printf("bar");
        sem_post(&obj->foo_sem);
    }
    return NULL;
}

int main() {
    int n = 2;
    FooBar fooBar;
    FooBar_init(&fooBar, n);

    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, foo, &fooBar);
    pthread_create(&thread2, NULL, bar, &fooBar);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    FooBar_free(&fooBar);
    return 0;
}
