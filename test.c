#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  pid_t p1, p2;
  printf("A %d\n\n", getpid());

  p1 = fork(); // ①
  p2 = fork(); // ②

  printf("ProcessID: %d, FirstChildProcessID: %d, SecondProcessID: %d\n", getpid(), p1, p2);


  if (p1 > 0 &&  p2 > 0) {
    printf("This is main Process %d\n", getpid());
    wait(NULL);
    printf("finish all Process\n");
  }

  if (p1 == 0 && p2 > 0)
  {
    printf("This is second Process %d\n", getpid());
    sleep.
  }

  if (p1 > 0 && p2 == 0)
  {
    printf("This is third Process %d\n", getpid());
  }

  if (p1 == 0 && p2 == 0)
  {
    printf("This is forth Process %d\n", getpid());
  }

  return 0;
}