#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* runner(void *param);
int sum=0;

int main(){
	pthread_t tid[4];
	pthread_attr_t attr[4];

	pthread_attr_init(&attr[0]);
	pthread_attr_init(&attr[1]);
	pthread_attr_init(&attr[2]);
	pthread_attr_init(&attr[3]);

	pthread_create(&tid[0], &attr[0], runner, "1");
	pthread_create(&tid[1], &attr[1], runner, "10001");
	pthread_create(&tid[2], &attr[2], runner, "20001");
	pthread_create(&tid[3], &attr[3], runner, "30001");

	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	pthread_join(tid[2],NULL);
	pthread_join(tid[3],NULL);
	
	printf("1에서 40000까지 4개의 스레드가 계산한 총 합은 %d\n",sum);
	

}

void* runner(void *param){
	
	int to=atoi(param);
	int far=to+9999;
	int i;


	for(i=to;i<=far;i++)
		sum+=i;
	
}