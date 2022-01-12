#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc<1){
		fprintf(stderr, "Insufficient arguments!\n");
		return -1;
	}
	if(unlink(argv[1])==0)
		printf("unlink success!\n");
	else{
		perror("unlink fail!\n");

		if(remove(argv[1])==0)
			printf("remove success!\n");
		else{
			perror("remove fail!\n");
			return -1;
		}
	}

	return 0;
}