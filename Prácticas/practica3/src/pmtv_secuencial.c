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
	struct timespec cgt1, cgt2;
	double ncgt;

#ifdef LOCAL
	int m[TAM][TAM];	//Matriz
	int v1[TAM];		//Vector
	int v2[TAM];		//Resultado
#endif

#ifdef DYNAMIC
	double **m;
	double *v1, *v2;
	m = (double**) malloc(TAM * sizeof(double*));
	for (int i = 0; i < TAM; i++)
		m[i] = (double*)malloc(TAM * sizeof(double));
	v1 = (double*)malloc(TAM * sizeof(double));
	v2 = (double*)malloc(TAM * sizeof(double));
#endif

	//Inicialización

	for (int i = 0; i < TAM; i++) {
		v1[i] = TAM;
		for (int j = 0; j < TAM; j++)
			m[i][j] = 0;
	}

	for (int i = 0; i < TAM; i++)
		for (int j = i; j < TAM; j++)
			m[i][j] = 1;

#if TEST
	printf("---------Valores iniciales------\n");
	for (int i = 0; i < TAM; i++) {
		for (int j = 0; j < TAM; j++)
			printf("%f ", m[i][j]);
		printf("\n");
	}
	for (int i = 0; i < TAM; i++)
		printf("v1[%d]=%f\n", i, v1[i]);
	printf("---------------------------------\n");

#endif

	/***Producto***/
	double temp;
	clock_gettime(CLOCK_REALTIME, &cgt1);
	for (int i = 0; i < TAM; i++) {
		temp = 0;
		for (int j = i; j < TAM; j++) {
			temp += m[i][j] * v1[j];
		}
		v2[i] = temp;
	}
	clock_gettime(CLOCK_REALTIME, &cgt2);
	ncgt = (double) (cgt2.tv_sec - cgt1.tv_sec) + (double) ((cgt2.tv_nsec - cgt1.tv_nsec) / (1.e+9));
	/*************/

#if TEST
	printf("---------Valores finales------\n");

	for (int i = 0; i < TAM; i++)
		printf("v2[%d]=%f\n", i, v2[i]);
	printf("---------------------------------\n");
#endif

	printf("\nTiempo (seg): %11.9f\t Tamaño: %d\tv2[0]=%f\tv[%d]=%f\n", ncgt, TAM, v2[0], TAM - 1, v2[TAM - 1]);

#ifdef DYNAMIC
	free(v1);
	free(v2);
	for (int i = 0; i < TAM; i++)
		free(m[i]);
	free(m);
#endif

}