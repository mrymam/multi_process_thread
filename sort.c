#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void printNumbers(int numbers[], int numLength)
{
  for (int i = 0; i < numLength; i++)
  {
    printf("%d ", numbers[i]);
  }
  printf("\n");
}

void merge(int n[], int n1[], int n2[], int n1Length, int n2Length)
{
  // int n1Length = sizeof(n1);
  // int n2Length = sizeof(n2);
  int length = n1Length + n2Length;

  int i1 = 0;
  int i2 = 0;

  for (int i = 0; i < length; i++)
  {
    // n1が全て終わっていたら
    if (i1 == n1Length)
    {
      n[i] = n2[i2];
      i2++;
      continue;
    }

    // n2が全て終わっていたら
    if (i2 == n2Length)
    {
      n[i] = n1[i1];
      i1++;
      continue;
    }

    // n1とn2の小さいほうを挿入
    if (n1[i1] <= n2[i2])
    {
      n[i] = n1[i1];
      i1++;
      continue;
    }
    else
    {
      n[i] = n2[i2];
      i2++;
      continue;
    }
  }
}

int isOver(const void *n1, const void *n2)
{
  if (*(int *)n1 > *(int *)n2)
  {
    return 1;
  }
  else if (*(int *)n1 < *(int *)n2)
  {
    return -1;
  }
  else
  {
    return 0;
  }
}

void randomNumnbers(int numbers[], int length) {
  for (int i = 0; i < length; i++)
  {
    numbers[i] = rand() % 100;
  }
}