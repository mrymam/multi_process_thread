#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <err.h>
#include <errno.h>
#include <pthread.h>
#include "../sort.h"

#define NUM_LENGTH 80000
#define HALF_NUM_LENGTH 40000
#define QUAD_NUM_LENGTH 20000

void *sortQuad(void *arg1) {
  int* numbers = (int*)arg1;
  // qsort(numbers, QUAD_NUM_LENGTH, sizeof(int), isOver);

  bubbleSort(numbers, QUAD_NUM_LENGTH);
}

int main() {
  int numbers[NUM_LENGTH];
  int half_numbers1[HALF_NUM_LENGTH];
  int half_numbers2[HALF_NUM_LENGTH];
  int numbers1[QUAD_NUM_LENGTH];
  int numbers2[QUAD_NUM_LENGTH];
  int numbers3[QUAD_NUM_LENGTH];
  int numbers4[QUAD_NUM_LENGTH];

  randomNumnbers(numbers1, QUAD_NUM_LENGTH);
  randomNumnbers(numbers2, QUAD_NUM_LENGTH);
  randomNumnbers(numbers3, QUAD_NUM_LENGTH);
  randomNumnbers(numbers4, QUAD_NUM_LENGTH);

  struct timeval t0, t1;
  gettimeofday(&t0, NULL);
  pthread_t thread1, thread2, thread3, thread4; // Thread handle.

  pthread_create(&thread1, NULL, &sortQuad, &numbers1);
  pthread_create(&thread2, NULL, &sortQuad, &numbers2);
  pthread_create(&thread3, NULL, &sortQuad, &numbers3);
  pthread_create(&thread4, NULL, &sortQuad, &numbers4);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  pthread_join(thread3, NULL);
  pthread_join(thread4, NULL);

  merge(half_numbers1, numbers1, numbers2, QUAD_NUM_LENGTH, QUAD_NUM_LENGTH);
  merge(half_numbers2, numbers3, numbers4, QUAD_NUM_LENGTH, QUAD_NUM_LENGTH);
  merge(numbers, half_numbers1, half_numbers2, HALF_NUM_LENGTH, HALF_NUM_LENGTH);

  gettimeofday(&t1, NULL);
  timersub(&t1, &t0, &t1);
  printf("quad   %ld.%06d\n", t1.tv_sec, t1.tv_usec);
  puts("-----------------");
}