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

#define NUM_LENGTH 400000
#define HALF_NUM_LENGTH 200000

void sortHalf(void *arg1)
{
  int* numbers = (int*)arg1;
  qsort(*numbers, HALF_NUM_LENGTH, sizeof(int), isOver);
}

int main() {
  int numbers[NUM_LENGTH];
  int numbers1[HALF_NUM_LENGTH];
  int numbers2[HALF_NUM_LENGTH];
  randomNumnbers(numbers1, HALF_NUM_LENGTH);
  randomNumnbers(numbers2, HALF_NUM_LENGTH);

  struct timeval t0, t1;
  gettimeofday(&t0, NULL);
  pthread_t thread1, thread2; // Thread handle.

  pthread_create(&thread1, NULL, &sortHalf, &numbers1);
  pthread_create(&thread2, NULL, &sortHalf, &numbers2);

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