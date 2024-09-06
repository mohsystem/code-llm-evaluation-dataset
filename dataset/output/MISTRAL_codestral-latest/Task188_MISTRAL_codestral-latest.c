#include <semaphore.h>
#include <stdio.h>

typedef void (*printFunc)();

typedef struct {
    int n;
    sem_t fooSemaphore;
    sem_t barSemaphore;
} FooBar;

FooBar* FooBarCreate(int n) {
    FooBar* obj = (FooBar*)malloc(sizeof(FooBar));
    obj->n = n;
    sem_init(&obj->fooSemaphore, 0, 1);
    sem_init(&obj->barSemaphore, 0, 0);
    return obj;
}

void foo(FooBar* obj, printFunc printFoo) {
    for (int i = 0; i < obj->n; i++) {
        sem_wait(&obj->fooSemaphore);
        printFoo();
        sem_post(&obj->barSemaphore);
    }
}

void bar(FooBar* obj, printFunc printBar) {
    for (int i = 0; i < obj->n; i++) {
        sem_wait(&obj->barSemaphore);
        printBar();
        sem_post(&obj->fooSemaphore);
    }
}