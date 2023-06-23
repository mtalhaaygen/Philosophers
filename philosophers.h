/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maygen <maygen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:04:47 by maygen            #+#    #+#             */
/*   Updated: 2023/06/23 17:54:38 by maygen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct philosopher_data
{
	int number_of_philosophers;
	int philo_id;
	pthread_t philo_thread;
	pthread_mutex_t rFork;
	pthread_mutex_t lFork;
} t_philo;

typedef struct time_data
{
	int number_of_philosophers;
	time_t start_time;
	time_t time_to_die;
	time_t time_to_eat;
	time_t time_to_sleep;
	int number_of_times_each_philosopher_must_eat;
	t_philo *philos;
	pthread_mutex_t *forks;
	int all_death;
} ti_data;

int ft_isdigit(char a);
int arg_check(int gc, char **gv);
int	ft_atoi(const char *str);
ti_data s_init(char **srgv);
void start(ti_data data);
time_t get_time();
#endif

