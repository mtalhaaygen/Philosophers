/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maygen <maygen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:45:09 by maygen            #+#    #+#             */
/*   Updated: 2023/06/23 17:55:59 by maygen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
	ti_data data;
	(void)argv;
	
	if (argc != 5 && argc != 6)
		return (1);
	if (arg_check(argc, argv))
		return (1);
	data = s_init(argv);
	start(data);
	return (0);
}