/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maygen <maygen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:04:47 by maygen            #+#    #+#             */
/*   Updated: 2023/07/04 13:39:16 by maygen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>

struct	s_time_data;

typedef struct philosopher_data
{
	int					number_of_philosophers;
	int					philo_id;
	int					ate_times;
	time_t				last_ate;
	pthread_t			philo_thread;
	struct s_time_data	*data;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
}	t_philo;

typedef struct s_time_data
{
	int				all_death;
	int				number_of_philosophers;
	time_t			start_time;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	writing;
	pthread_mutex_t	death;
}	t_data;

int		ft_isdigit(char a);
int		arg_check(int gc, char **gv);
int		ft_atoi(const char *str);
time_t	get_time(void);
int		start_init(t_data *data, char **argv);
int		philo_init(t_data *data);
int		start_simulation(t_data *data);
void	ft_sleep(time_t duration, t_data *data);
void	exit_threads(t_data *data);
void	print_status(char *msg, t_philo *p);
void	philo_eating(t_philo *p);
void	philo_sleeping(t_philo *p);
void	check_death(t_data *data);
#endif
