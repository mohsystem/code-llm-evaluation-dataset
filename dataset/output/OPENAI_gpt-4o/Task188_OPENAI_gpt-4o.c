#include <stdio.h>
#include <pthread.h>

typedef struct {
    int n;
    pthread_mutex_t lock;
    pthread_cond_t cond;
    bool fooTurn;
} FooBar;

void* foo(void* arg) {
    FooBar* fooBar = (FooBar*)arg;
    for (int i = 0; i < fooBar->n; ++i) {
        pthread_mutex_lock(&fooBar->lock);
        while (!fooBar->fooTurn) {
            pthread_cond_wait(&fooBar->cond, &fooBar->lock);
        }
        printf("foo");
        fooBar->fooTurn = false;
        pthread_cond_signal(&fooBar->cond);
        pthread_mutex_unlock(&fooBar->lock);
    }
    return NULL;
}

void* bar(void* arg) {
    FooBar* fooBar = (FooBar*)arg;
    for (int i = 0; i < fooBar->n; ++i) {
        pthread_mutex_lock(&fooBar->lock);
        while (fooBar->fooTurn) {
            pthread_cond_wait(&fooBar->cond, &fooBar->lock);
        }
        printf("bar");
        fooBar->fooTurn = true;
        pthread_cond_signal(&fooBar->cond);
        pthread_mutex_unlock(&fooBar->lock);
    }
    return NULL;
}

int main() {
    int n = 2;
    FooBar fooBar;
    fooBar.n = n;
    pthread_mutex_init(&fooBar.lock, NULL);
    pthread_cond_init(&fooBar.cond, NULL);
    fooBar.fooTurn = true;

    pthread_t threadA, threadB;
    pthread_create(&threadA, NULL, foo, &fooBar);
    pthread_create(&threadB, NULL, bar, &fooBar);
    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);

    pthread_mutex_destroy(&fooBar.lock);
    pthread_cond_destroy(&fooBar.cond);

    return 0;
}