#!/bin/bash
for ((N=16384;N<67108865;N=N*2))
do
  echo "----------FOR-----------"
 ./suma_vectores_for $N
  echo "----------SECTIONS-----------"
 ./suma_vectores_sections $N
  echo "----------SECUENCIAL-----------"
 ./suma_vectores $N
done