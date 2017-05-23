#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *create (void *arg){
	int *num;
	num = (int *)arg;
	printf("from main process is :%d\n",*num);
	return (void *)0;

}

int main(int argc ,char *argv[])
{
	int ret;
	pthread_t pd1;
	int test=100;
	int *attr =&test;
	
	ret =pthread_create(&pd1, NULL,create, (void *)attr);	
	
	if(ret!=0){
		printf("pthread_create error!\n");
		exit(0);
	}
	sleep(1);
	return 0;
}

