/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maygen <maygen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:44:27 by maygen            #+#    #+#             */
/*   Updated: 2023/07/02 23:54:43 by maygen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *worker_thread(void *arg)
{
	t_philo *philo;

	philo = (t_philo*)arg;
	if (philo->philo_id % 2 == 1 && philo->data->number_of_philosophers > 1)
		ft_sleep(philo->data->time_to_eat / 50, philo->data); // bu neden 50 ???
	while (!philo->data->all_death)
	{
		philo_eating(philo);
		philo_sleeping(philo);
		print_status("thinking", philo);
	}
	return (NULL);
}

int start_init(ti_data *data, char **argv)
{
	t_philo *philosophers;
	pthread_mutex_t *forkerrrs;

	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		data->number_of_times_each_philosopher_must_eat = -1;
	philosophers = malloc(sizeof(t_philo)* data->number_of_philosophers);
	forkerrrs = malloc(sizeof(pthread_mutex_t)* data->number_of_philosophers);
	if (!philosophers || !forkerrrs)
		return (1);
	data->philos = philosophers;
	data->forks = forkerrrs;
	return (0);
}

int philo_init(ti_data *data)
{
	int i;

	i = 0;
	data->all_death = 0;
	if (pthread_mutex_init(&data->writing, NULL))
	{
		return (1);
	}
	if (pthread_mutex_init(&data->death, NULL))
	{
		return (1);
	}
	while (i < data->number_of_philosophers)
	{
		if (pthread_mutex_init(&data->forks[i] , NULL))
		{
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < data->number_of_philosophers)
	{
		data->philos[i].ate_times = 0;
		data->philos[i].number_of_philosophers = data->number_of_philosophers;
		data->philos[i].philo_id = i + 1;
		data->philos[i].rFork = &data->forks[i];
		data->philos[i].lFork = &(data->forks[(i+1) % data->number_of_philosophers]);
		data->philos[i].data = data;
		i++;
	}
	return (0);
}

int	start_simulation(ti_data *data)
{
	int i;

	i = 0;
	data->start_time = get_time();
	while (i < data->number_of_philosophers)
	{
		data->philos[i].last_ate = data->start_time;
		
		if (pthread_create(&data->philos[i].philo_thread, NULL, &worker_thread, &(data->philos[i])))
		{
			return (1);
		}
		i++;
	}
	while (!data->all_death)
		check_death(data->philos);
	exit_threads(data);
	return (0);
}