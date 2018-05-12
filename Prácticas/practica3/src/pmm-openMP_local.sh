#!/bin/bash

for((N=1;N<5;N=N+1)) do
  export OMP_NUM_THREADS=$N
  echo "N=160;OMP_NUM_THREADS=$N"
  ./pmm-openmp 160
done

for((N=1;N<5;N=N+1)) do
  export OMP_NUM_THREADS=$N
  echo "N=1450;OMP_NUM_THREADS=$N"
  ./pmm-openmp 1450
done
