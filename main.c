/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maygen <maygen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:45:09 by maygen            #+#    #+#             */
/*   Updated: 2023/07/03 14:12:45 by maygen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
	ti_data data;

	if (argc != 5 && argc != 6)
		return (1);
	if (arg_check(argc, argv))
		return (1);
	if (start_init(&data ,argv))
		return (1);
	if (philo_init(&data))
		return (1);
	start_simulation(&data);
	return (0);
}