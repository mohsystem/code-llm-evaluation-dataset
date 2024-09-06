#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int n;
  sem_t zero_sem;
  sem_t even_sem;
  sem_t odd_sem;
  int count;
  int thread_id;
} zero_even_odd_t;

zero_even_odd_t *zero_even_odd_create(int n) {
  zero_even_odd_t *obj = malloc(sizeof(zero_even_odd_t));
  obj->n = n;
  sem_init(&obj->zero_sem, 0, 1);
  sem_init(&obj->even_sem, 0, 0);
  sem_init(&obj->odd_sem, 0, 0);
  obj->count = 1;
  obj->thread_id = 0;
  return obj;
}

void zero(zero_even_odd_t *obj, void (*print_number)(int)) {
  for (int i = 0; i < obj->n; i++) {
    sem_wait(&obj->zero_sem);
    print_number(0);
    obj->count++;
    if (obj->count % 2 == 0) {
      sem_post(&obj->odd_sem);
    } else {
      sem_post(&obj->even_sem);
    }
  }
}

void even(zero_even_odd_t *obj, void (*print_number)(int)) {
  for (int i = 2; i <= obj->n; i += 2) {
    sem_wait(&obj->even_sem);
    print_number(i);
    obj->count++;
    sem_post(&obj->zero_sem);
  }
}

void odd(zero_even_odd_t *obj, void (*print_number)(int)) {
  for (int i = 1; i <= obj->n; i += 2) {
    sem_wait(&obj->odd_sem);
    print_number(i);
    obj->count++;
    sem_post(&obj->zero_sem);
  }
}

void zero_even_odd_destroy(zero_even_odd_t *obj) {
  sem_destroy(&obj->zero_sem);
  sem_destroy(&obj->even_sem);
  sem_destroy(&obj->odd_sem);
  free(obj);
}