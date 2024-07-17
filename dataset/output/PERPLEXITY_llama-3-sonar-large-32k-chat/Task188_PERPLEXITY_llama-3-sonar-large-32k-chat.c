#include <stdio.h>
#include <pthread.h>

typedef struct {
    int n;
    pthread_mutex_t mtx;
    pthread_cond_t cv;
    int fooTurn;
} FooBar;

void* foo(void* arg) {
    FooBar* fooBar = (FooBar*)arg;
    for (int i = 0; i < fooBar->n; i++) {
        pthread_mutex_lock(&fooBar->mtx);
        while (!fooBar->fooTurn) {
            pthread_cond_wait(&fooBar->cv, &fooBar->mtx);
        }
        printf("foo");
        fflush(stdout);
        fooBar->fooTurn = 0;
        pthread_cond_signal(&fooBar->cv);
        pthread_mutex_unlock(&fooBar->mtx);
    }
    return NULL;
}

void* bar(void* arg) {
    FooBar* fooBar = (FooBar*)arg;
    for (int i = 0; i < fooBar->n; i++) {
        pthread_mutex_lock(&fooBar->mtx);
        while (fooBar->fooTurn) {
            pthread_cond_wait(&fooBar->cv, &fooBar->mtx);
        }
        printf("bar");
        fflush(stdout);
        fooBar->fooTurn = 1;
        pthread_cond_signal(&fooBar->cv);
        pthread_mutex_unlock(&fooBar->mtx);
    }
    return NULL;
}

int main() {
    FooBar fooBar;
    fooBar.n = 1;
    pthread_mutex_init(&fooBar.mtx, NULL);
    pthread_cond_init(&fooBar.cv, NULL);
    fooBar.fooTurn = 1;
    pthread_t t1, t2;
    pthread_create(&t1, NULL, foo, &fooBar);
    pthread_create(&t2, NULL, bar, &fooBar);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}