#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	pid_t pid;
	int i, sum=0;
	int n=10, m=100;

	pid=fork();
	if(pid>0){
		
		wait(NULL);
		if(pid=2) printf("부모 프로세스: 1000보다 크다\n");
		else if(pid=1) printf("부모 프로세스: 1000과 같다\n");
		else printf("부모 프로세스: 1000보다 작다\n");
		
		
		return 0;
		
	}
	else if(pid==0){
		int result=0;
		for(i=n;i<=m;i++)
			sum+=i;
		if (sum>1000) result=2;
		else if (sum==1000) result=1;
		else result=0;
		printf("자식 프로세스: %d에서 %d까지의 합은 %d\n", n,m,sum);
		return result;
	}
	else{
		printf("fork error");
		return 0;
	}
}