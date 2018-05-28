#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct {
  int a;
  int b;
} s[5000];

int main() {
  int ii, i, X1, X2;
  int *R;
  const int TAM = 40000;
  const int TAM2 = 5000;
  struct timespec cgt1, cgt2;
  double ncgt;
  R = (int *)malloc(TAM * sizeof(int));

  clock_gettime(CLOCK_REALTIME, &cgt1);

  for (ii = 0; ii < TAM; ii++) {
    X1 = 0;
    X2 = 0;
    for (i = 0; i < TAM2; i+=4) {
      X1 += 2 * s[i].a + ii;
      X2 += 3 * s[i].b - ii;
      //
      X1 += 2 * s[i+1].a + ii;
      X2 += 3 * s[i+1].b - ii;
      //
      X1 += 2 * s[i+2].a + ii;
      X2 += 3 * s[i+2].b - ii;
      //
      X1 += 2 * s[i+3].a + ii;
      X2 += 3 * s[i+3].b - ii;
    }
    if (X1 < X2)
      R[ii] = X1;
    else
      R[ii] = X2;
  }
  clock_gettime(CLOCK_REALTIME, &cgt2);
  ncgt = (double)(cgt2.tv_sec - cgt1.tv_sec) +
         (double)((cgt2.tv_nsec - cgt1.tv_nsec) / (1.e+9));

  printf("\nTiempo (seg): %11.9f\n", ncgt);

  free(R);
}
