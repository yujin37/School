#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* runner(void *param);
int total=0;
int sumtotal=0;
int sum[4]={0,};

int main(){
	pthread_t tid;
	pthread_attr_t attr;

	pthread_attr_init(&attr);
	pthread_create(&tid, &attr, runner, "1");
	pthread_join(tid,NULL);
	sum[0]=total;
	pthread_create(&tid, &attr, runner, "10001");
	pthread_join(tid,NULL);
	sum[1]=total;
	pthread_create(&tid, &attr, runner, "20001");
	pthread_join(tid,NULL);
	sum[2]=total;
	pthread_create(&tid, &attr, runner, "30001");
	pthread_join(tid,NULL);
	sum[3]=total;
	
	//printf("runner 스레드가 종료하였습니다.\n");
	for(int i=0;i<4;i++){
		sumtotal+=sum[i];
	}
	printf("1에서 40000까지 4개의 스레드가 계산한 총 합은 %d\n",sumtotal);

}

void* runner(void *param){
	total=0;
	//printf("runner 스레드가 실행을 시작합니다. \n");
	int to=atoi(param);
	int far=to+9999;
	int i;


	for(i=to;i<=far;i++)
		total+=i;
	
}