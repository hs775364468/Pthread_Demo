#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *thread_func(void *arg)
{
	printf("a new thread runing....\n");
	return (void *)10;
}
int main(int argc ,char *argv[])
{ 
	int ret;
	pthread_t pt_d;
	void *num;
	ret =pthread_create(&pt_d,NULL,thread_func,NULL);
	if(ret!=0){
		printf("pthread_create failed!\n");
		exit(0);
	}
	ret =pthread_join(pt_d ,&num);
	if(ret!=0){
		printf("pthread_join failed\n");
		exit(0);
	}
	printf("return from thread_func is :%d\n",(int)num);
	return 0;
}

