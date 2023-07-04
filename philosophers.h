/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maygen <maygen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:04:47 by maygen            #+#    #+#             */
/*   Updated: 2023/07/03 14:14:26 by maygen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>

struct time_data;
typedef struct philosopher_data
{
	int number_of_philosophers;
	int philo_id;
	int ate_times;
	time_t last_ate;
	pthread_t philo_thread;
	struct time_data *data;
	pthread_mutex_t *rFork;
	pthread_mutex_t *lFork;
} t_philo;

typedef struct time_data
{
	int all_death;
	int number_of_philosophers;
	time_t start_time;
	time_t time_to_die;
	time_t time_to_eat;
	time_t time_to_sleep;
	int number_of_times_each_philosopher_must_eat;
	t_philo *philos;
	pthread_mutex_t *forks;
	pthread_mutex_t writing;
	pthread_mutex_t death;
} ti_data;

int		ft_isdigit(char a);
int		arg_check(int gc, char **gv);
int		ft_atoi(const char *str);
time_t	get_time();

int		start_init(ti_data *data, char **argv);
int		philo_init(ti_data *data);
int		start_simulation(ti_data *data);
void	ft_sleep(time_t duration, ti_data *data);
void	exit_threads(ti_data *data);
void	print_status(char *msg, t_philo *p);
void	philo_eating(t_philo *p);
void	philo_sleeping(t_philo *p);
void	check_death(ti_data *data);
#endif
