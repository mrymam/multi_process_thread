#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <err.h>
#include <errno.h>

#include <sys/ipc.h>
#include <sys/shm.h>

#include "../sort.h"

#define NUM_LENGTH 80000
#define HALF_NUM_LENGTH 40000
#define QUAD_NUM_LENGTH 20000

int memID;
int memSize;

int main() {
  // 数を作成
  int numbers[NUM_LENGTH];
  int numbers1[QUAD_NUM_LENGTH];
  int numbers2[QUAD_NUM_LENGTH];
  int numbers3[QUAD_NUM_LENGTH];
  int numbers4[QUAD_NUM_LENGTH];
  randomNumnbers(numbers1, QUAD_NUM_LENGTH);
  randomNumnbers(numbers2, QUAD_NUM_LENGTH);
  randomNumnbers(numbers3, QUAD_NUM_LENGTH);
  randomNumnbers(numbers4, QUAD_NUM_LENGTH);


  struct timeval t0,t1;
  gettimeofday(&t0, NULL);
  pid_t pid;
  pid = fork();

  if (-1 == pid)
  {
    err(EXIT_FAILURE, "can not create");
  }

  if (0 == pid)
  {
    // child
    // qsort(numbers1, HALF_NUM_LENGTH, sizeof(int), isOver);
    bubbleSort(numbers1, QUAD_NUM_LENGTH);
    bubbleSort(numbers2, QUAD_NUM_LENGTH);
    exit(EXIT_SUCCESS);
  }
  else
  {
    // parent

    // qsort(numbers2, HALF_NUM_LENGTH, sizeof(int), isOver);
    bubbleSort(numbers3, QUAD_NUM_LENGTH);
    bubbleSort(numbers4, QUAD_NUM_LENGTH);

    wait(NULL);

    gettimeofday(&t1, NULL);
    timersub(&t1, &t0, &t1);

    printf("double %ld.%06d\n", t1.tv_sec, t1.tv_usec);
    // printf("printed from parent process %d\n", getpid());
    puts("-----------------");
  }
}