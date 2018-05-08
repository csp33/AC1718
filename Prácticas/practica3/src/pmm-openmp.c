#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST 0

//#define LOCAL

//#define GLOBAL

#define DYNAMIC

#ifdef GLOBAL
int m[TAM][TAM];	//Matriz
int v1[TAM];		//Vector
int v2[TAM];		//Resultado
#endif

#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#endif

int main(int argc, char **argv) {

	if (argc != 2) {
		fprintf(stderr, "Error de argumentos\n");
		exit(-1);
	}

	const int TAM = atoi(argv[1]);
	double ini, fin;
	double ncgt;

#ifdef LOCAL
	int m1[TAM][TAM];	//Matriz
	int m2[TAM][TAM];	//Matriz
#endif

#ifdef DYNAMIC
	double **m1, **m2, **m3;
	m1 = (double**) malloc(TAM * sizeof(double*));
	m2 = (double**) malloc(TAM * sizeof(double*));
	m3 = (double**) malloc(TAM * sizeof(double*));
	#pragma omp parallel for
	for (int i = 0; i < TAM; i++) {
		m1[i] = (double*)malloc(TAM * sizeof(double));
		m2[i] = (double*)malloc(TAM * sizeof(double));
		m3[i] = (double*)malloc(TAM * sizeof(double));
	}
#endif

	//Inicialización
	#pragma omp parallel for
	for (int i = 0; i < TAM; i++){
		#pragma omp parallel for
		for (int j = 0; j < TAM; j++)
			if (i == j)
				m1[i][j] = m2[i][j] = 1;
			else
				m1[i][j] = m2[i][j] = 0;
	}


#if TEST
	printf("---------Valores iniciales------\n");

	printf("------Matriz 1------\n");

	for (int i = 0; i < TAM; i++) {
		for (int j = 0; j < TAM; j++)
			printf("%f ", m1[i][j]);
		printf("\n");
	}

	printf("------Matriz 2------\n");

	for (int i = 0; i < TAM; i++) {
		for (int j = 0; j < TAM; j++)
			printf("%f ", m2[i][j]);
		printf("\n");
	}
	printf("---------------------------------\n");

#endif

	/***Producto***/
	double temp=0;
	ini=omp_get_wtime();
	#pragma omp parallel for
	for (int i = 0; i < TAM; i++) {
		for (int j = 0; j < TAM; j++) {
			temp = 0;
			for (int k = 0; k < TAM; k++)
				temp += m1[i][k] * m2[k][j];
			m3[i][j] = temp;
		}
	}
	fin=omp_get_wtime();
	ncgt = fin-ini;
	/*************/

#if TEST
	printf("---------Valores finales------\n");

	for (int i = 0; i < TAM; i++) {
		for (int j = 0; j < TAM; j++)
			printf("%f ", m3[i][j]);
		printf("\n");
	}
	printf("---------------------------------\n");
#endif

	printf("\nTiempo (seg): %11.9f\t Tamaño: %d\tm3[0][0]=%f\tm3[%d][%d]=%f\n", ncgt, TAM, m3[0][0], TAM - 1, TAM - 1, m3[TAM - 1][TAM - 1]);

#ifdef DYNAMIC
	for (int i = 0; i < TAM; i++) {
		free(m1[i]);
		free(m2[i]);
		free(m3[i]);
	}
	free(m1);
	free(m2);
	free(m3);
#endif

}