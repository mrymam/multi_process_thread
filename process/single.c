#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <err.h>
#include <errno.h>
#include "../sort.h"

#define NUM_LENGTH 80000
#define HALF_NUM_LENGTH 40000
#define QUAD_NUM_LENGTH 20000

int main()
{
  struct timeval t0, t1;
  int numbers[NUM_LENGTH];
  int numbers1[QUAD_NUM_LENGTH];
  int numbers2[QUAD_NUM_LENGTH];
  int numbers3[QUAD_NUM_LENGTH];
  int numbers4[QUAD_NUM_LENGTH];
  randomNumnbers(numbers1, QUAD_NUM_LENGTH);
  randomNumnbers(numbers2, QUAD_NUM_LENGTH);
  randomNumnbers(numbers3, QUAD_NUM_LENGTH);
  randomNumnbers(numbers4, QUAD_NUM_LENGTH);

  puts("-----------------");
  gettimeofday(&t0, NULL);

  // qsort(numbers, NUM_LENGTH, sizeof(int), isOver);
  bubbleSort(numbers1, QUAD_NUM_LENGTH);
  bubbleSort(numbers2, QUAD_NUM_LENGTH);
  bubbleSort(numbers3, QUAD_NUM_LENGTH);
  bubbleSort(numbers4, QUAD_NUM_LENGTH);

  gettimeofday(&t1, NULL);
  timersub(&t1, &t0, &t1);
  printf("single %ld.%06d\n", t1.tv_sec, t1.tv_usec);
  puts("-----------------");
}