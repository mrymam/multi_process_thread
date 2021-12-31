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

struct Arg
{
  int* numbers1;
  int* numbers2;
  int* numbers3;
  int* numbers4;
};

void *sortSingle(void *arg1)
{
  struct Arg arg = *(struct Arg *)arg1;
  // qsort(numbers, NUM_LENGTH, sizeof(int), isOver);
  bubbleSort(arg.numbers1, QUAD_NUM_LENGTH);
  bubbleSort(arg.numbers2, QUAD_NUM_LENGTH);
  bubbleSort(arg.numbers3, QUAD_NUM_LENGTH);
  bubbleSort(arg.numbers4, QUAD_NUM_LENGTH);
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

  struct Arg arg;
  arg.numbers1 = numbers1;
  arg.numbers2 = numbers2;
  arg.numbers3 = numbers3;
  arg.numbers4 = numbers4;

  struct timeval t0, t1;
  gettimeofday(&t0, NULL);
  pthread_t thread; // Thread handle.

  pthread_create(&thread, NULL, &sortSingle, &arg);

  pthread_join(thread, NULL);
  gettimeofday(&t1, NULL);
  timersub(&t1, &t0, &t1);
  printf("single %ld.%06d\n", t1.tv_sec, t1.tv_usec);
  // printf("printed from parent process %d\n", getpid());
  puts("-----------------");

  return 0;
}