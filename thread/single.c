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

void sortSingle(void *arg)
{
  long int numbers = (int *)arg;
  qsort(numbers, NUM_LENGTH, sizeof(int), isOver);
}

int main() {
  int numbers[NUM_LENGTH];
  randomNumnbers(numbers, NUM_LENGTH);

  struct timeval t0, t1;
  gettimeofday(&t0, NULL);
  pthread_t thread; // Thread handle.

  pthread_create(&thread, NULL, &sortSingle, &numbers);

  pthread_join(thread, NULL);
  gettimeofday(&t1, NULL);
  timersub(&t1, &t0, &t1);
  printf("double %ld.%06d\n", t1.tv_sec, t1.tv_usec);
  // printf("printed from parent process %d\n", getpid());
  puts("-----------------");
}