#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#define OVERLOAD 1

// Write the execution time, acoording to the number of processes
/***************************************/
/* # of processes | Elapsed time (sec) */
/*              1 |         0.00000000 */
/*              2 |         0.00000000 */
/*              3 |         0.00000000 */
/*              4 |         0.00000000 */
/***************************************/

// count # of 4 within length 
int main(int argc, char **argv)
{
    const int length = 10000000, iters = 1000;
    int myid, nprocs, length_per_process, i, j, p;
    int *myArray, *tmpArray, *gArray, root, tag, myCount, gCount;

    double t1, t2;

    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);	// # of processes
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);   // allocate rank to processes

    root = 0; 
	tag = 0;
    length_per_process = length / nprocs;

	myArray=(int *)malloc(length_per_process*sizeof(int));
	memset(myArray,0x00, length_per_process*sizeof(int));

	tmpArray=(int *)malloc(length_per_process*sizeof(int));
	memset(tmpArray,0x00, length_per_process*sizeof(int));

    if(myid == root)
	{
        t1 = MPI_Wtime();

        gArray=(int *)malloc(length*sizeof(int));
		
        for (i=0; i< length;i++)
            gArray[i]=i%10;

		// allocate array to processes
	    for(i = 0; i < length_per_process; i++)
            myArray[i] = gArray[i];
		
        for(p = 1; p < nprocs; p++)
		{
            for(i = 0; i < length_per_process; i++)
			{
                j = i + p*length_per_process;
                tmpArray[i]=gArray[j];
            }
			
            ???(tmpArray, length_per_process, MPI_INT, p, tag, MPI_COMM_WORLD);
        }
    }
	else
	{
        ???(???, ???, MPI_INT, ???, tag, MPI_COMM_WORLD, &status);
    }

#if OVERLOAD
	for (j = 0; j < iters; j++)	// generate overload
#endif
	{
        myCount = 0;
		
        for(i = 0; i < length_per_process; i++)
		{
            if(myArray[i] == 4) 
				myCount++;
        }
	}

    if(myid == root)
	{
        gCount = myCount;

		for(p = 1; p < nprocs; p++)
		{
            ???(???, ???, MPI_INT, ???, tag, MPI_COMM_WORLD, &status);
            gCount = gCount + myCount;
        }

    }
    else
	{
        ???(&myCount, 1, MPI_INT, root, tag, MPI_COMM_WORLD);
    }

	if(myid == root)
    {
        t2 = MPI_Wtime();
        printf("nprocs=%d \t # of 4's: %d \t Elapsed Time = %12.8lf (sec) \n ", nprocs, gCount, t2-t1);
    }
		
    MPI_Finalize();
	
    return 0;
}

