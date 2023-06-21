#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

int data = 0;
pthread_mutex_t my_mutex;

void* funck(void *arg)
{
	for (size_t i = 0; i < 100000; i++)
	{
		pthread_mutex_lock(&my_mutex);
		data++;
		pthread_mutex_unlock(&my_mutex);
	}
}
void* funck2(void *arg)
{
	sleep(3);
	for (size_t i = 0; i < 100000; i++)
	{
		pthread_mutex_lock(&my_mutex);
		data++;
		pthread_mutex_unlock(&my_mutex);
	}
}

int main()
{
	pthread_t *th;
	int e, i;

	i = 0;
	pthread_mutex_init(&my_mutex, NULL);
	while (i < 2)
	{
		e = pthread_create(th + i, NULL, &funck2, NULL);
		if (e != 0)
			printf("error");
		printf("thread %d. created\n", i);
		i++;
	}  
	pthread_join(th[1],NULL);
	printf("thread 1 join\n");
	// pthread_join(th[0],NULL);
	// printf("thread 0 join\n");
	printf("data = %d\n",data);
	pthread_mutex_destroy(&my_mutex);
	return (0);
}
