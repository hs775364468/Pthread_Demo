#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

//int test=100;
void *create (void *arg){
	//int *num;
	//num = (int *)arg;
	//printf("from main process is :%d\n",*num);
	//printf("test is :%d\n",test);
	char *str =(char *)arg;
	printf("from main process string is :%s\n",str);
	return (void *)0;

}

int main(int argc ,char *argv[])
{
	int ret;
	pthread_t pd1;
	//int test=500;
	//int *attr =&test;
	char *str="transfer string";
	//ret =pthread_create(&pd1, NULL,create, (void *)attr);	
	ret =pthread_create(&pd1, NULL,create, (void *)str);	
	if(ret!=0){
		printf("pthread_create error!\n");
		exit(0);
	}
	sleep(1);
	return 0;
}

