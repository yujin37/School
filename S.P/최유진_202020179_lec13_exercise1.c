#include <stdio.h>
#include <string.h>
#include <mpi.h>
#define DATA_A_SIZE 100
#define DATA_B_SIZE 200
/*
yujin@LAPTOP-RQEQR76J:~$ mpirun -np 4 ./block_comm
process 1 received 100 elements of data_a from process 0
process 1: data_a is the same as data_b
process 2 received 100 elements of data_a from process 0
process 2: data_a is the same as data_b
process 3 received 100 elements of data_a from process 0
process 3: data_a is the same as data_b
*/
int main(int argc, char* argv[])
{
	int nprocs, myrank,i,n,count;
	float data_a[DATA_A_SIZE], data_b[DATA_B_SIZE];
	MPI_Status status;
	
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD,&nprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

	for(i=0;i<DATA_A_SIZE;i++)
		data_a[i]=i*0.5;
	MPI_Barrier(MPI_COMM_WORLD);
	if(myrank==0){
		for(i=1;i<nprocs;i++)
			MPI_Send(data_a,DATA_A_SIZE,MPI_FLOAT,i,55,MPI_COMM_WORLD);
	}
	else{
		MPI_Recv(data_b,DATA_B_SIZE,MPI_FLOAT,0,55,MPI_COMM_WORLD,&status);
		//MPI_Barrier(MPI_COMM_WORLD);
		MPI_Get_count(&status,MPI_FLOAT,&count);
		printf("process %d received %d elements of data_a from process %d\n", myrank,count, status.MPI_SOURCE);

		n=memcmp(data_a,data_b,sizeof(float)*DATA_A_SIZE);

		
		if(n==0)
			printf("process %d: data_a is the same as data_b \n", myrank);
		else
			printf("process %d: data_a is not the same as data_b \n", myrank);
	}
	
	MPI_Finalize();
	return 0;
}
