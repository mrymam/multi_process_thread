#!/bin/bash

# exec single
# gcc single.c -o single
# ./single

# gcc double.c -o double
# ./double

# gcc quad.c -o quad
# ./quad

echo "process\n"
gcc -o out process/single.c sort.c
./out

gcc -o out process/double.c sort.c
./out

gcc -o out process/quad.c sort.c
./out

echo "thread\n"

gcc -o out thread/single.c sort.c

# gcc -o out thread/double.c sort.c
# ./out

# gcc -o out thread/quad.c sort.c
# ./out