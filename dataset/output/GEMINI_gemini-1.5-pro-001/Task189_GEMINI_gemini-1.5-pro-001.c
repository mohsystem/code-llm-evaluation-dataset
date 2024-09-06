typedef struct {
    int n;
    int count;
    sem_t z;
    sem_t e;
    sem_t o;
} ZeroEvenOdd;

ZeroEvenOdd* zeroEvenOddCreate(int n) {
    ZeroEvenOdd* obj = malloc(sizeof(ZeroEvenOdd));
    obj->n = n;
    obj->count = 0;
    sem_init(&obj->z, 0, 1);
    sem_init(&obj->e, 0, 0);
    sem_init(&obj->o, 0, 0);
    return obj;
}

void zeroEvenOddZero(ZeroEvenOdd* obj, int (*printNumber)(int)) {
    for (int i = 0; i < obj->n; i++) {
        sem_wait(&obj->z);
        printNumber(0);
        obj->count++;
        if (obj->count % 2 == 0) {
            sem_post(&obj->e);
        } else {
            sem_post(&obj->o);
        }
    }
}

void zeroEvenOddEven(ZeroEvenOdd* obj, int (*printNumber)(int)) {
    for (int i = 2; i <= obj->n; i += 2) {
        sem_wait(&obj->e);
        printNumber(i);
        obj->count++;
        if (obj->count % 2 == 0) {
            sem_post(&obj->e);
        } else {
            sem_post(&obj->o);
        }
    }
}

void zeroEvenOddOdd(ZeroEvenOdd* obj, int (*printNumber)(int)) {
    for (int i = 1; i <= obj->n; i += 2) {
        sem_wait(&obj->o);
        printNumber(i);
        obj->count++;
        if (obj->count % 2 == 0) {
            sem_post(&obj->e);
        } else {
            sem_post(&obj->o);
        }
    }
}

void zeroEvenOddFree(ZeroEvenOdd* obj) {
    sem_destroy(&obj->z);
    sem_destroy(&obj->e);
    sem_destroy(&obj->o);
    free(obj);
}