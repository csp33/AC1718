#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct {
  int a;
  int b;
} s[5000];

int main() {
  int x1, x2, i, j;
  int *R;
  const int TAM = 40000;
  const int TAM2 = 5000;
  struct timespec cgt1, cgt2;
  double ncgt;

  clock_gettime(CLOCK_REALTIME, &cgt1);

  R = (int *)malloc(TAM * sizeof(int));
  for (i = 0; i < TAM; i++) {
    x1 = 0;
    x2 = 0;
    for (j = 0; j < TAM2; j++)
      x1 += 2 * s[i].a + i;
    for (j = 0; j < TAM2; j++)
      x2 += 3 * s[i].b - i;
    if (x1 < x2)
      R[i] = x1;
    else
      R[i] = x2;
  }

  clock_gettime(CLOCK_REALTIME, &cgt2);
  ncgt = (double)(cgt2.tv_sec - cgt1.tv_sec) +
         (double)((cgt2.tv_nsec - cgt1.tv_nsec) / (1.e+9));

  printf("\nTiempo (seg): %11.9f\n", ncgt);

  free(R);
}
