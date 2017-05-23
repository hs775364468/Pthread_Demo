#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void *create (void *arg){

	printf("new threading.....");
	printf("the thread id is :%d\n",(unsigned int)pthread_self());
	printf("the getpid() is :%d\n",getpid());
	return (void *)0;
}

int main(int argc ,char *argv[])
{
	int ret;
	pthread_t pd1;
	
	ret =pthread_create(&pd1, NULL,create,NULL);	
	
	if(ret!=0){
		printf("pthread_create error!\n");
		exit(0);
	}
	printf("the main process pid is %d\n",getpid());
	sleep(1);
	return 0;
}

