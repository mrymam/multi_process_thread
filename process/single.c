#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <err.h>
#include <errno.h>
#include "../sort.h"

#define NUM_LENGTH 400000
#define HALF_NUM_LENGTH 200000

int main()
{
  struct timeval t0, t1;
  int numbers[NUM_LENGTH];
  randomNumnbers(numbers, NUM_LENGTH);

  puts("-----------------");
  gettimeofday(&t0, NULL);

  qsort(numbers, NUM_LENGTH, sizeof(int), isOver);

  gettimeofday(&t1, NULL);
  timersub(&t1, &t0, &t1);
  printf("single %ld.%06d\n", t1.tv_sec, t1.tv_usec);
  puts("-----------------");
}