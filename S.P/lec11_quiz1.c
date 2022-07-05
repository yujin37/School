#include <stdio.h>
#include <stdlib.h>
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

int main(void)
{
    double **data;
    int data_size = 10000;
    int i = 0, j = 0;
    double start, end;
    
    data = (double **)malloc(data_size * sizeof(double *));
    
    for (i = 0; i < data_size; i++)
        data[i] = (double *)malloc(data_size * sizeof(double));

    for (i = 0; i < data_size; i++){
        for (j = 0; j < data_size; j++){
            data[i][j] = (data_size * i) + j;               // initialization
        }
    }

    start = omp_get_wtime();

    /* insert openmp directive */
    for (i = 0; i < data_size; i++){
        for (j = 0; j < data_size; j++){
            data[i][j] = sqrt(data[i][j]);                  // compute square root
        }
    }

    end = omp_get_wtime();
    
    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            printf("data[%d][%d]:%f ", i, j, data[i][j]);
        }
        printf("\n");
    }              

    printf("Execution time in the openmp parallel region: %f (sec) \n", end - start);

    for(i = 0; i < data_size; i++)
        free(data[i]);

    free(data);

    return 0;
}
