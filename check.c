/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maygen <maygen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:59:05 by maygen            #+#    #+#             */
/*   Updated: 2023/06/19 20:08:00 by maygen           ###   ########.fr       */
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