/*SumaVectoresC.c
Compilar con -lrt (Real Time Library)
	gcc -O2 SumaVectores.c -o SumaVectoresC -lrt
Para ejecutar use SumaVectoresC longitud
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
// #define PRINTF_ALL
// #define VECTOR_LOCAL	//Local, si se supera el tamaño de pila se genera Segmentation Fault
// #define VECTOR_GLOBAL //Su longitud no está limitada por el tamaño de la pila
#define VECTOR_DYNAMIC //Memoria dinámica (reutilizable durante la ejecución)

#ifdef VECTOR_GLOBAL
#define MAX 33554432 //2^25
double v1[MAX], v2[MAX], v3[MAX];
#endif
int main (int argc, char **argv) {
	int i;
	struct timespec cgt1, cgt2;
	double ncgt;		//Tiempo de ejecución
	//Leer argumento de entrada (nº de componentes del vector)
	if (argc < 2) {
		printf("Falta el nº de componentes del vector");
		exit(-1);
	}
	unsigned int N = atoi(argv[1]);		//Máximo N=2^32-1
#ifdef VECTOR_LOCAL
	double v1[N], v2[N], v3[N];
#endif
#ifdef VECTOR_GLOBAL
	if (N > MAX) N = MAX;
#endif
#ifdef VECTOR_DYNAMIC
	double *v1, *v2, *v3;
	v1 = (double*) malloc(N * sizeof(double));
	v2 = (double*) malloc(N * sizeof(double));
	v3 = (double*) malloc(N * sizeof(double));
	if (v1 == NULL || v2 == NULL || v3 == NULL) {
		printf("Error al reservar espacio.");
		exit(-1);
	}
#endif
	//Inicializaar vectores
	for (i = 0; i < N; i++) {
		v1[i] = N * 0.1 + i * 0.1;
		v2[i] = N * 0.1 - i * 0.1;
	}
	clock_gettime(CLOCK_REALTIME, &cgt1);
	//Calcular sumcla de vectores
	for (i = 0; i < N; i++)
		v3[i] = v1[i] + v2[i];
	clock_gettime(CLOCK_REALTIME, &cgt2);
	ncgt = (double)(cgt2.tv_sec - cgt1.tv_sec) + (double)((cgt2.tv_nsec - cgt1.tv_nsec) / 1.e+9);
	//Imprimir resultado de suma y tiempo de ejecución
#ifdef PRINTF_ALL
	printf("Tiempo(seg.):%11.9f\t / Tamaño Vectores:%u\n", ncgt, N);
	for (i = 0; i < N; i++)
		printf("/ V1[%d]+V2[%d]=V3[%d](%8.6f+%8.6f+%8.6f) /\n", i, i, i, v1[i], v2[i], v3[i]);
#else
	printf("Tiempo(seg.):%11.9f\t / Tamaño Vectores:%u\t/ V1[0]+V2[0]=V3[0] (%8.6f+%8.6f=%8.6f / / V1[%d]+V2[%d]=V3[%d](%8.6f+%8.6f+%8.6f) /\n",
	       ncgt, N, v1[0], v2[0], v3[0], N - 1, N - 1, N - 1, v1[N - 1], v2[N - 1], v3[N - 1]);
#endif
#ifdef VECTOR_DYNAMIC
	free(v1);
	free(v2);
	free(v3);
#endif
}

