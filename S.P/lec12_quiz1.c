#include <stdio.h>
#include <math.h>
#include <time.h>
#include <omp.h>

// Write the execution time in the openmp parallel region, acoording to the number of threads
/*************************************/
/* # of threads | Elapsed time (sec) */
/*            1 |           0.000000 */
/*            2 |           0.000000 */
/*            3 |           0.000000 */
/*            4 |           0.000000 */
/*************************************/

int main(int argc, char** argv)
{
    long i, n;
    double sum, step, pi, x;
    int cont;
    double start, end;

    cont = 1;

    while (cont)
    {
        printf("Enter the number of intervals (n >= 1): ");
        scanf("%ld", &n);

        if (n < 1)
        {
            cont = 0;
            break;
        }

        start = omp_get_wtime();

        step = 1.0 / (double)n;
        sum = 0.0;

        /* insert openmp directive */
        for (i = 0; i < n; i++)
        {
            x = ((double)i + 0.5) * step;
            sum += ((4.0 / (1.0 + (x * x))) * step);
        }

        pi = sum;

        end = omp_get_wtime();

        printf("============================================================\n");
        printf("PI = %.15f (error = %E)\n", pi, fabs(acos(-1.0) - pi));
        printf("Elapsed time: %f s\n", end - start);
        printf("============================================================\n\n");
    }

    return 0;
}
