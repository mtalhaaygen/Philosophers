// Activity 5. Write a program hellomany.c that will create a number N of threads specified in the command line, each of which prints out a hello message and its own thread ID. To see how the execution of the threads interleaves, make the main thread sleep for 1 second for every 4 or 5 threads it creates. The output of your code should be similar to:
//        I am thread 1. Created new thread (4) in iteration 0...
//        Hello from thread 4 - I was created in iteration 0
//        I am thread 1. Created new thread (6) in iteration 1...
//        I am thread 1. Created new thread (7) in iteration 2...
//        I am thread 1. Created new thread (8) in iteration 3...
//        I am thread 1. Created new thread (9) in iteration 4...
//        I am thread 1. Created new thread (10) in iteration 5...
//        Hello from thread 6 - I was created in iteration 1
//        Hello from thread 7 - I was created in iteration 2
//        Hello from thread 8 - I was created in iteration 3
//        Hello from thread 9 - I was created in iteration 4
//        Hello from thread 10 - I was created in iteration 5
//        I am thread 1. Created new thread (11) in iteration 6...
//        I am thread 1. Created new thread (12) in iteration 7...
//        Hello from thread 11 - I was created in iteration 6
//        Hello from thread 12 - I was created in iteration 7

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t mutex;

void *function(void *argv)
{
    pthread_mutex_lock(&mutex);
    int *id = (int *)argv;
    printf("Ben %d. filozofum\n", id[0]);
    pthread_mutex_unlock(&mutex);
    return (argv);
}

int main(int gc, char **gv)
{
    if (gc != 2)
        return (1);
    int n = atoi(gv[1]);
    pthread_t th[n];
    int *philo_id;

    pthread_mutex_init(&mutex, NULL);
    philo_id = malloc(sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        usleep(100);
        philo_id[0] = i + 1;
        if (pthread_create((th + i), NULL, &function, (void *)philo_id))
            printf("error1");
        printf("%d. döndüde oluşturuldum - ",philo_id[0]);
        // if (i % 4 == 0)
        //     sleep(1);
    }
    for (int i = 0; i < n; i++)
    {
        if (pthread_join(th[i], NULL))
            printf("error2");
    }
    pthread_mutex_destroy(&mutex);
}