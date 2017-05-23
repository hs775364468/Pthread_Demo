#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *my_thread1 (void)
{
	int i;
	for(i =0;i<5;i++)
	{
		printf("this is my_thread1!\n");
		sleep(1);
	}
}
void *my_thread2 (void)
{
	int i;
	for(i =0;i<5;i++)
	{
		printf("this is my_thread2!\n");
		sleep(1);
	}

}
     
int main(int argc ,char *argv[]){

	pthread_t pd1;
	pthread_t pd2;
	int ret;
	
	ret=pthread_create(&pd1, NULL,(void *)my_thread1,NULL);
	if(ret!=0){
		printf("my_thread1 create failed!\n");
		exit(0);
	}
	ret = pthread_create(&pd2, NULL,(void *)my_thread2,NULL);
	if(ret!=0){
		printf("my_thread1 create failed!\n");
		exit(0);
	}
    pthread_join(pd1, NULL);
	pthread_join(pd2, NULL);
	return 0;
}

