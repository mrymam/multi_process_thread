#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

#define NUM_LENGTH 20
#define HALF_NUM_LENGTH 10

int main() {
  int numbers[NUM_LENGTH];

  int numbers1[HALF_NUM_LENGTH];
  int numbers2[HALF_NUM_LENGTH];

  randomNumnbers(numbers1, HALF_NUM_LENGTH);
  randomNumnbers(numbers2, HALF_NUM_LENGTH);

  printNumbers(numbers1, 10);
  printNumbers(numbers2, 10);

  qsort(&numbers1[0], HALF_NUM_LENGTH, sizeof(numbers1[0]), isOver);
  qsort(numbers2, HALF_NUM_LENGTH, sizeof(int), isOver);

  printf("sorted\n");

  printNumbers(numbers1, HALF_NUM_LENGTH);
  printNumbers(numbers2, HALF_NUM_LENGTH);

  merge(numbers, numbers1, numbers2, HALF_NUM_LENGTH, HALF_NUM_LENGTH);
  printNumbers(numbers, 20);

  return 0;
}