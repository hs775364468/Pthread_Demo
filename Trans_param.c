#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
struct demo{
	int s;
	char *str;
};
//int test=100;
void *create (void *arg){
	//int *num;
	//num = (int *)arg;
	//printf("from main process is :%d\n",*num);
	//printf("test is :%d\n",test);
	//char *str =(char *)arg;
	struct demo *d =(struct demo *)arg;
	printf("from main process int is :%d , string is %s\n",d->s,d->str);
	return (void *)0;

}

int main(int argc ,char *argv[])
{
	int ret;
	pthread_t pd1;
	struct demo d1;
	d1.s=100;
	d1.str="string from demo";
	struct demo *p;
	p = &d1;
	//int test=500;
	//int *attr =&test;
	//char *str="transfer string";
	//ret =pthread_create(&pd1, NULL,create, (void *)attr);	
	//ret =pthread_create(&pd1, NULL,create, (void *)str);	
	ret =pthread_create(&pd1, NULL,create, (void *)p);	
	if(ret!=0){
		printf("pthread_create error!\n");
		exit(0);
	}
	sleep(1);
	return 0;
}

