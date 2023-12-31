/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maygen <maygen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:43:20 by maygen            #+#    #+#             */
/*   Updated: 2023/07/07 17:06:24 by maygen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(char *msg, t_philo *p)
{
	time_t	timestamp;

	pthread_mutex_lock(&p->data->writing);
	if (!is_alldeath(p->data))
	{
		timestamp = get_time() - p->data->start_time;
		printf("%ld %d %s\n", timestamp, p->philo_id, msg);
	}
	pthread_mutex_unlock(&p->data->writing);
}

void	philo_eating(t_philo *p)
{
	pthread_mutex_lock(p->r_fork);
	print_status("has taken a fork", p);
	pthread_mutex_lock(p->l_fork);
	print_status("has taken a fork", p);
	print_status("is eating", p);
	pthread_mutex_lock(&p->data->meal);
	p->last_ate = get_time();
	p->ate_times++;
	pthread_mutex_unlock(&p->data->meal);
	ft_sleep(p->data->time_to_eat, p->data);
	pthread_mutex_unlock(p->r_fork);
	pthread_mutex_unlock(p->l_fork);
}

void	philo_sleeping(t_philo *p)
{
	print_status("is sleeping", p);
	ft_sleep(p->data->time_to_sleep, p->data);
}

int	is_alldeath(t_data *data)
{
	pthread_mutex_lock(&data->death);
	if (data->all_death)
	{
		pthread_mutex_unlock(&data->death);
		return (1);
	}
	pthread_mutex_unlock(&data->death);
	return (0);
}