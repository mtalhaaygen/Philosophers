/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maygen <maygen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:45:09 by maygen            #+#    #+#             */
/*   Updated: 2023/06/22 12:53:01 by maygen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 5 && argc != 6)
		return (1);
	if (arg_check(argc, argv))
		return (2);
	str_init();
	// mutex start
	// thread start
	return (0);
}