#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	pid_t pid;
	int status;

	pid=fork();

	if(pid>0){
		wait(&status);
		printf("1에서 10까지 합한 결과는 %d\n", WEXITSTATUS(status));
		return 0;

	}
	else if(pid == 0){
		execlp("./sum", "./sum",NULL);
	}
	else{
		return 0;
	}
}
