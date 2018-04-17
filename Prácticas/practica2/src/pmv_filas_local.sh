#!/bin/bash
#Se asigna al trabajo el nombre filas
#PBS -N filas
#Se asigna al trabajo la cola ac
#PBS -q ac
#Se imprime información del trabajo usando variables de entorno de PBS

if [ $# -eq 1 ]
	then
		for ((N=1;N<9;N=N+1))
		do
			export OMP_NUM_THREADS=$N
			echo "Hebras: $N"
			 ./pmv_openMP_a $1
		done
	else
			echo "Falta tamanio vector"
fi