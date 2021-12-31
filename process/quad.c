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
#define QUAD_NUM_LENGTH 100000

int main(int argc, char *argv[])
{
  int numbers[NUM_LENGTH];
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
  pid_t pid, main_pid;
  main_pid = getpid();

  for (int i = 0; i < 4; i++)
  {
    pid = fork();
    if (pid == 0) {
      if (i == 0) {
        qsort(numbers1, QUAD_NUM_LENGTH, sizeof(int), isOver);
      }
      if (i == 1)
      {
        qsort(numbers2, QUAD_NUM_LENGTH, sizeof(int), isOver);
      }
      if (i == 2)
      {
        qsort(numbers3, QUAD_NUM_LENGTH, sizeof(int), isOver);
      }
      if (i == 3)
      {
        qsort(numbers, QUAD_NUM_LENGTH, sizeof(int), isOver);
      }
      break;
    }
  }

  if (main_pid == getpid()) {
    wait(NULL);
    gettimeofday(&t1, NULL);
    timersub(&t1, &t0, &t1);
    printf("quad   %ld.%06d\n", t1.tv_sec, t1.tv_usec);
    puts("-----------------");
  }

  return 0;
}