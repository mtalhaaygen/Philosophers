#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

// void* funck()
// {
// 	void* x;

// 	x = 0;
// 	printf("selamınaleyküm");
// 	return (x);
// }

// int main()
// {
// 	pthread_t t1; //pthread_t abstract type is implemented as an integer (4 byte) thread ID. long unsigned int e eşdeğer
// 	pthread_t t2;
// 	pthread_create(&t1, NULL, &funck, NULL);
// 	pthread_create(&t2, NULL, &funck, NULL);

//     printf("%lu",t1);
// 	return (0);
// }

int i = 0;

void *worker_thread(void *arg)
{
        printf("This is worker_thread\n");
        sleep(2);
        i++;
        return NULL;
}

void *worker_thread2(void *arg)
{
        sleep(4);
        printf("Eating...\n");
        printf("%s\n",(char *)arg);
        return NULL;
}

int main()
{
        pthread_t my_thread; // thread in idsi olacak
        pthread_t my_thread2;
        pthread_attr_t attr; // thread in attribute larının olduğu değişken
        int e;

		// pthread fonksiyonları 0 yada bir hata numarasını temsil eden baska bir sey return eder
        e = pthread_attr_init(&attr); // attributler initialize ediliyor
        printf("**%d**\n",e);
        e = pthread_create(&my_thread2, &attr, &worker_thread2, "talha"); // oluşturduğumuz threadin işaretçisi, ikinci parametre NULL olursa otomatik kendisi ayarlama yapıyor, diğer parametre thread oluşturulduğunda yürütülecek fonksiyonun işaretçisi, son parametre fonksiyona göndereceğimiz parametre
		if (e != 0)
			printf("erorr");
        e = pthread_create(&my_thread, NULL, &worker_thread, NULL);
		if (e != 0)
			printf("erorr");
        printf("%d\n",i);
        e = pthread_join(my_thread, NULL); // ??? diğer threadin beklemesini sağlıyor,
		if (e != 0)
			printf("erorr");
        printf("%d\n",i);
        e = pthread_join(my_thread2, NULL);
		if (e != 0)
			printf("erorr");
        printf("%d\n",i);

        // pthread_detach();
        // pthreaad_mutex_t my_mutex;
		// pthread_mutex_init(&my_mutex, NULL);
        // pthread_mutex_lock();
        // pthread_mutex_unlock();
        // pthread_mutex_destroy(&my_mutex);

		//*******************************
		// pthread_join(); iş parçacığını sonlandırmak için belirtilen iş parçacığını bekler
		//On success, pthread_join() returns 0; on error, it returns an error number.


        return 0;
}
