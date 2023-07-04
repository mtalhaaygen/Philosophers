/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maygen <maygen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:44:21 by maygen            #+#    #+#             */
/*   Updated: 2023/07/03 14:50:07 by maygen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48) * neg;
		if (res > 2147483647)
			return (-1);
		if (res < -2147483648)
			return (-1);
		i++;
	}
	return (res);
}

time_t get_time()
{
	struct timeval tv;
	time_t start_time;

	gettimeofday(&tv, NULL);
	start_time = ((long int)tv.tv_sec * 1000) + (tv.tv_usec / 1000); 
	return (start_time);
}

void	ft_sleep(time_t duration, ti_data *data)
{
	time_t	start; 

	start = get_time(); // fonksiyonun başladığı zamanı alıyor
	while (!data->all_death) // eğer bir filozof olursa condition değişkeni 1 olur ve döngü sonlanır
	{
		if (get_time() - start >= duration) // şuanki zamandan fonksiyonun başladığı zamanı çıkartarak geçen zaman duration a eşit olunca döngüyü sonlandıracak
			break ;
		usleep(data->number_of_philosophers * 2); // buna neden ihtiyaç oldu anlamadım
	}
}

void	exit_threads(ti_data *data)
{
	int	i;

	if (data->number_of_philosophers == 1)
		pthread_detach(data->philos[0].philo_thread);
	else
	{
		i = -1;
		while (++i < data->number_of_philosophers)
			pthread_join(data->philos[i].philo_thread, NULL);
	}
	i = -1;
	while (++i < data->number_of_philosophers)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->writing);
	pthread_mutex_destroy(&data->death);
	free(data->philos);
	free(data->forks);
}
