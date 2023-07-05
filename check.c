/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maygen <maygen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:59:05 by maygen            #+#    #+#             */
/*   Updated: 2023/07/05 14:21:44 by maygen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(char a)
{
	if (a >= 48 && a <= 57)
		return (1);
	return (0);
}

int	arg_check(int gc, char **gv)
{
	int	i;
	int	j;

	i = 1;
	while (i < gc)
	{
		j = 0;
		while (gv[i][j])
		{
			if (!ft_isdigit(gv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	finish_serving(t_data *data)
{
	int	count;
	int	i;

	count = 0;
	if (data->number_of_times_each_philosopher_must_eat != -1)
	{
		i = 0;
		while (i < data->number_of_philosophers)
		{
			if (data->number_of_times_each_philosopher_must_eat == \
			data->philos[i].ate_times)
				count++;
			i++;
		}
		if (count == data->number_of_philosophers)
		{
			data->all_death = 1;
			return (1);
		}
	}
	return (0);
}

void	check_death(t_data *data)
{
	int		i;
	int		status;
	time_t	time;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		time = get_time() - data->philos[i].last_ate;
		status = time >= data->time_to_die;
		if (status || finish_serving(data))
		{
			if (status)
				print_status("died", &data->philos[i]);
			data->all_death = 1;
			break ;
		}
	}
}
