#! /bin/bash

print_sum() { let "sum = $1 + $2"; echo $sum; }
print_mul() { let "mul = $1 + $2"; echo $mul; }

print_sum 2 2
print_mul 5 5

