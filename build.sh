#!/bin/bash

# exec single
# gcc single.c -o single
# ./single

# gcc double.c -o double
# ./double

# gcc quad.c -o quad
# ./quad

gcc -o out quick_sort_test.c sort.c

gcc test.c -o test