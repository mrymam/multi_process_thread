#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <err.h>
#include <errno.h>
#include <pthread.h>

void roop(long int count)
{
  for (long int i = 0; i < count; i++)
    ;
}


void threadRoop(void *arg) {
  long int count = *(long int *)arg;
  printf("count %ld\n", count);
  roop(count);
}

int main() {
  struct timeval t0, t1;
  gettimeofday(&t0, NULL);

  pthread_t thread1, thread2, thread3, thread4; // Thread handle.
  long int data = 100000000;

  pthread_create(&thread1, NULL, &threadRoop, &data);
  pthread_create(&thread2, NULL, &threadRoop, &data);
  pthread_create(&thread3, NULL, &threadRoop, &data);
  pthread_create(&thread4, NULL, &threadRoop, &data);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  pthread_join(thread3, NULL);
  pthread_join(thread4, NULL);

  gettimeofday(&t1, NULL);
  timersub(&t1, &t0, &t1);
  printf("double %d.%06d\n", t1.tv_sec, t1.tv_usec);
  // printf("printed from parent process %d\n", getpid());
  puts("-----------------");
}