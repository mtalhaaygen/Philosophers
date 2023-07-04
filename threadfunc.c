/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maygen <maygen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:43:20 by maygen            #+#    #+#             */
/*   Updated: 2023/07/04 13:02:58 by maygen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void print_status(char *msg, t_philo *p)
{
	time_t timestamp;

	pthread_mutex_lock(&p->data->writing);
	timestamp = get_time() - p->data->start_time;
	if (!p->data->all_death)
		printf("%ld %d %s\n", timestamp, p->philo_id, msg);
	pthread_mutex_unlock(&p->data->writing);
}

void philo_eating(t_philo *p)
{
	pthread_mutex_lock(p->rFork);
	print_status("has taken a fork",p);
	pthread_mutex_lock(p->lFork);
	print_status("has taken a fork",p);
	print_status("is eating", p);
	p->last_ate = get_time();
	p->ate_times++;
	ft_sleep(p->data->time_to_eat, p->data);
	pthread_mutex_unlock(p->rFork);
	pthread_mutex_unlock(p->lFork);
}

void philo_sleeping(t_philo *p)
{
	
	print_status("is sleeping", p);
	ft_sleep(p->data->time_to_sleep, p->data);
}