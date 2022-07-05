#include <stdio.h>
#include <math.h>
#include <mpi.h>

int main(int argc, char* argv[]){
		long i,n;
		double sum, tsum, step,pi,x;
		int cont;
		int nprocs,myrank,ierr;
		double start, end;
		MPI_Status status;

		cont=1;
		
		ierr=MPI_Init(&argc,&argv);
		ierr=MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
		ierr=MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

		while(cont){
			if(myrank==0){
				printf("Enter the number of intervals (n>=1): ");
				fflush(stdout);
				scanf("%ld", &n);

				for(i=1;i<nprocs;i++)
					//ierr=???;
					ierr=MPI_Send(&n,1,MPI_DOUBLE,i,1,MPI_COMM_WORLD);
			}
			else{
				//ierr=???;
				ierr=MPI_Recv(&n,1,MPI_DOUBLE,0,1,MPI_COMM_WORLD,&status);
			}
			if(n<1){
				cont=0;
				break;
			}
			start=MPI_Wtime();

			step=1.0/(double)n;
			sum=0.0;

			for(i=myrank;i<n;i+=nprocs){
				x=((double)i+0.5)*step;
				sum+=((4.0/(1.0+(x*x)))*step);
			}

			if(myrank==0){
				tsum=sum;

				for(i=1;i<nprocs;i++){
					//ierr=???;
					ierr=MPI_Send(&n,1,MPI_DOUBLE,i,1,MPI_COMM_WORLD);
					tsum=tsum+sum;
				}

				pi=tsum;

				end=MPI_Wtime();

				printf("==========================\n");
				printf("PI=%.15f(error=%E)\n",pi,fabs(acos(-1.0)-pi));
				printf("Elapsed time: %f s\n", end-start);
				printf("==========================\n\n");
			}
			else{
				//ierr=???;
				ierr=MPI_Recv(&n,1,MPI_DOUBLE,0,1,MPI_COMM_WORLD,&status);

			}
		}

		ierr=MPI_Finalize();
		return 0;
}
