#! /bin/bash
executable=$1
rm -rf *.o
gcc -o bin/$executable *.c