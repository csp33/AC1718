#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {

  if (argc != 2) {
    printf("Falta tamanio\n");
    exit(-1);
  }

  const int N = atoi(argv[1])>INT_MAX ? INT_MAX : atoi(argv[1]);
  const float a = 5.15445455445;
  int i;
  float *x, *y;
  x = (float *)malloc(N * sizeof(float));
  y = (float *)malloc(N * sizeof(float));

  for (i = 0; i < N; i++) {
    x[i] = 23.1313455445513;
    y[i] = 54.54455544554;
  }

  struct timespec cgt1, cgt2;
  double ncgt;

  clock_gettime(CLOCK_REALTIME, &cgt1);

  for (i = 0; i < N; i++)
    y[i] = a * x[i] + y[i];

  clock_gettime(CLOCK_REALTIME, &cgt2);
  ncgt = (double)(cgt2.tv_sec - cgt1.tv_sec) +
         (double)((cgt2.tv_nsec - cgt1.tv_nsec) / (1.e+9));

  printf("\nTiempo (seg): %11.9f\n", ncgt);

  free(x);
  free(y);
}
