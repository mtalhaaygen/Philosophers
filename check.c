/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maygen <maygen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:59:05 by maygen            #+#    #+#             */
/*   Updated: 2023/07/04 13:02:11 by maygen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int ft_isdigit(char a)
{
	if (a >= 48 && a <= 57)
		return 1;
	return (0);
}

int arg_check(int gc, char **gv)
{
	int i, j;

	i = 1;
	while (i < gc)
	{
		j = 0;
		while(gv[i][j])
		{
			if (!ft_isdigit(gv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	finish_serving(ti_data *data)
{
	// tüm filozofların ate_times değerleri numsafdsgfhdgjhghgfgdhgjhhgfg 'a eşit olunca return 1 yapacak
	int count;
	int i;

	count = 0;
	if (data->number_of_times_each_philosopher_must_eat != -1)
	{
		i = 0;
		while (i < data->number_of_philosophers)
		{
			if (data->number_of_times_each_philosopher_must_eat == data->philos[i].ate_times)
				count++;
			i++;
		}
		// printf("count:%d",count);
		if (count == data->number_of_philosophers)
		{
			data->all_death = 1;
			return (1);
		}
	}
	return (0);
}

void	check_death(ti_data *data)
{
	// iki koşul var
	// 2 - max eat e ulaştı mı ?
	int i;
	int status;
	time_t time;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		time = get_time() - data->philos[i].last_ate;
		status = time >= data->time_to_die;
		if (status || finish_serving(data))
		{
			if (status)
				printf("%lu %d %s\n", time, data->philos[i].philo_id, "died");
			data->all_death = 1;
			break; 
		}
	}
}