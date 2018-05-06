#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main(int argc, char **argv) {
	omp_set_num_threads(2);
	int chunk_;
	omp_sched_t schedule;

	int i, n = 200, chunk, a[n], suma = 0;
	if (argc < 3) {
		fprintf(stderr, "\nFalta iteraciones o chunk \n");
		exit(-1);
	}

	n = atoi(argv[1]);
	if (n > 200)
		n = 200;

	chunk = atoi(argv[2]);

	for (i = 0; i < n; i++)
		a[i] = i;

	#pragma omp parallel for firstprivate(suma) lastprivate(suma) schedule(dynamic,chunk)
	for (i = 0; i < n; i++) {
		if (i == 0) {	//Master
			omp_get_schedule(&schedule, &chunk_);
			printf("\nDentro de parallel.\ndyn_var=%d \t nthreads_var=%d \t thread_limit_var=%d \t run_sched_var=%d \t chunk=%d\n",
			       omp_get_dynamic(), omp_get_max_threads(), omp_get_thread_limit(), schedule, chunk_);
		}
		suma = suma + a[i];
		printf(" thread %d suma a[%d]=%d suma=%d \n", omp_get_thread_num(), i, a[i], suma);
	}

	printf("Fuera de 'parallel for' suma=%d\n", suma);
	omp_get_schedule(&schedule, &chunk_);
	printf("Fuera de parallel.\n dyn_var=%d \t nthreads_var=%d \t thread_limit_var=%d \t run_sched_var=%d \t chunk=%d\n",
	       omp_get_dynamic(), omp_get_max_threads(), omp_get_thread_limit(), schedule, chunk_);
}