/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:50:23 by tbraquem          #+#    #+#             */
/*   Updated: 2022/05/21 15:26:52 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

// Different state of Philosophers.
enum	e_type
{
	IDLE,
	EAT,
	THINK,
	SLEEP,
	DEAD
};

// Global variables structure.
typedef struct s_vars
{
	int				max_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_eat;
	int				forks;
	int				continue_sim;
	long long int	start_time;
}				t_vars;

// Philosopher structure.
typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	fork_mutex;
	int				id;
	int				state;
	int				ate;
	int				index;
	long int		last_meal;
}				t_philo;

// Philosopher data structure.
typedef struct s_data
{
	t_vars	vars;
	t_philo	**philo_tab;
	int		index;
}				t_data;

// Init
void			init_vars(t_vars *vars, char **argv);
t_philo			*init_var_philosopher(t_vars vars, t_philo *philo, int id);
t_philo			**init_philosophers(t_vars vars, t_philo **philosophers);
t_philo			**init_mutex(t_philo **philosophers);
t_data			**init_data(t_philo **philo, t_vars vars, t_data **data);

// Free
t_philo			**free_philosophers(t_philo **philo);
t_philo			**destroy_mutex(t_philo **philosophers);
t_data			**free_data(t_data **data);

// Threads
void			start_threads(t_philo **philo, t_data **data);
void			thread_redirect(t_philo *philo, t_data **data, int i);

// Routines
void			*routine(void *arg);
void			*routine2(void *arg);
void			*routine_time(void *arg);
void			*routine_odd(void *arg);

// Actions
int				philo_eat(t_data *data);
int				philo_sleep(t_data *data);
int				philo_think(t_data *data);

// Checker
int				check_everyone_ate(t_philo **philo, int max_eat);

// Time
int				mstou(int ms);
long long int	get_time(void);

// Utils
int				ft_atoi(const char *str);
int				previous_philo(int index, int max_philo);
size_t			ft_strlen(const char *s);
char			*ft_itoa(long long int n);
char			*ft_strjoin(char const *s1, char const *s2);
void			print_message(long int timestamp, int id, const char *message);

#endif
