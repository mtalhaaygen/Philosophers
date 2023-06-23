/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maygen <maygen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:44:21 by maygen            #+#    #+#             */
/*   Updated: 2023/06/23 17:15:10 by maygen           ###   ########.fr       */
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

// time_t equal_time(time_t t1, time_t t2)