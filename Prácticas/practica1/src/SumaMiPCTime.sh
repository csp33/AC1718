#!/bin/bash
for ((N=65536;N<67108865;N=N*2))
do
 echo "----------FOR-----------"
 time ./suma_vectores_for $N
 echo "----------SECUENCIAL-----------"
 time ./suma_vectores $N
done