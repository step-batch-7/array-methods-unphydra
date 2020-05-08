#! /bin/bash

executable=$1

rm -rf *.o

gcc -c *.c
gcc -c $executable
gcc -o main *.o
./main
rm -rf *.o main