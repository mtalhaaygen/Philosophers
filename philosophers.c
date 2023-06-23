/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maygen <maygen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:44:27 by maygen            #+#    #+#             */
/*   Updated: 2023/06/23 18:27:18 by maygen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *worker_thread(void *arg)
{
    int *id = (int*)arg;
    printf("philo %d Eating....\n",id[0]);
    return (arg);
}

ti_data s_init(char **argv)
{
    ti_data data;
    t_philo *philosophers;
    pthread_mutex_t *forkerrrs;
    
    data.number_of_philosophers = ft_atoi(argv[1]);
    data.start_time = get_time();
    data.time_to_die = ft_atoi(argv[2]);
    data.time_to_eat = ft_atoi(argv[3]);
    data.time_to_sleep = ft_atoi(argv[4]);
    if (argv[5])
        data.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
    else
        data.number_of_times_each_philosopher_must_eat = -1;
    philosophers = malloc(sizeof(t_philo)* data.number_of_philosophers);
    forkerrrs = malloc(sizeof(pthread_mutex_t)* data.number_of_philosophers);
    if (!philosophers || !forkerrrs)
        exit(1);
    data.philos = philosophers;
    data.forks = forkerrrs;
    data.all_death = 0;
    return (data);
}

void start(ti_data data)
{
	int i;
	int *t;

	i = 0;
	while (i < data.number_of_philosophers)
	{
		pthread_mutex_init(&data.forks[i] , NULL);
		i++;
	}
	i = 0;
	while (i < data.number_of_philosophers)
	{
		data.philos[i].number_of_philosophers = data.number_of_philosophers;
		data.philos[i].philo_id = i + 1;
		data.philos[i].rFork = data.forks[i];
		data.philos[i].lFork =data.forks[(i+1) % data.number_of_philosophers];
		t = malloc(sizeof(int *));
		t[0] = data.philos->philo_id;
		pthread_create(&data.philos[i].philo_thread, NULL, &worker_thread, (void *)t);
		i++;
		free(t);
	}
}