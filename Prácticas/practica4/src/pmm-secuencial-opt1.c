#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST 0

//#define LOCAL

//#define GLOBAL

#define DYNAMIC

#ifdef GLOBAL
int m[TAM][TAM]; // Matriz
int v1[TAM];     // Vector
int v2[TAM];     // Resultado
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
  int m1[TAM][TAM]; // Matriz
  int m2[TAM][TAM]; // Matriz
#endif

#ifdef DYNAMIC
  double **m1, **m2, **m3;
  m1 = (double **)malloc(TAM * sizeof(double *));
  m2 = (double **)malloc(TAM * sizeof(double *));
  m3 = (double **)malloc(TAM * sizeof(double *));
  for (int i = 0; i < TAM; i++) {
    m1[i] = (double *)malloc(TAM * sizeof(double));
    m2[i] = (double *)malloc(TAM * sizeof(double));
    m3[i] = (double *)malloc(TAM * sizeof(double));
  }
#endif

  // Inicialización

  for (int i = 0; i < TAM; i++)
    for (int j = 0; j < TAM; j++)
      if (i == j)
        m1[i][j] = m2[i][j] = 1;
      else
        m1[i][j] = m2[i][j] = 0;

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
  double temp1, temp2, temp3, temp4;
  clock_gettime(CLOCK_REALTIME, &cgt1);
  for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++) {
      temp1 = 0;
      temp2 = 0;
      temp3 = 0;
      temp4 = 0;
      for (int k = 0; k < TAM; k += 4) {
        temp1 += m1[i][k] * m2[k][j];
        temp2 += m1[i][k + 1] * m2[k + 1][j];
        temp3 += m1[i][k + 2] * m2[k + 2][j];
        temp4 += m1[i][k + 3] * m2[k + 3][j];
      }
      m3[i][j] = temp1 + temp2 + temp3 + temp4;
    }
  }
  clock_gettime(CLOCK_REALTIME, &cgt2);
  ncgt = (double)(cgt2.tv_sec - cgt1.tv_sec) +
         (double)((cgt2.tv_nsec - cgt1.tv_nsec) / (1.e+9));
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

  printf("\nTiempo (seg): %11.9f\t Tamaño: %d\tm3[0][0]=%f\tm3[%d][%d]=%f\n",
         ncgt, TAM, m3[0][0], TAM - 1, TAM - 1, m3[TAM - 1][TAM - 1]);

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
