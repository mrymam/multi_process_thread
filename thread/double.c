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

struct Arg {
  int *numbers1;
  int *numbers2;
};

void *sortQuad(void *arg1)
{
  struct Arg arg = *(struct Arg*)arg1;
  // qsort(numbers, HALF_NUM_LENGTH, sizeof(int), isOver);
  bubbleSort(arg.numbers1, QUAD_NUM_LENGTH);
  bubbleSort(arg.numbers2, QUAD_NUM_LENGTH);
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

  struct Arg arg1, arg2;
  arg1.numbers1 = numbers1;
  arg1.numbers2 = numbers2;

  arg2.numbers1 = numbers3;
  arg2.numbers2 = numbers4;

  struct timeval t0, t1;
  gettimeofday(&t0, NULL);
  pthread_t thread1, thread2; // Thread handle.

  pthread_create(&thread1, NULL, &sortQuad, &arg1);
  pthread_create(&thread2, NULL, &sortQuad, &arg2);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  merge(numbers, numbers1, numbers2, HALF_NUM_LENGTH, HALF_NUM_LENGTH);
  // printNumbers(numbers, NUM_LENGTH);

  gettimeofday(&t1, NULL);
  timersub(&t1, &t0, &t1);
  printf("double %ld.%06d\n", t1.tv_sec, t1.tv_usec);
  // printf("printed from parent process %d\n", getpid());
  puts("-----------------");
}