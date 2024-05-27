/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:19:19 by moamzil           #+#    #+#             */
/*   Updated: 2023/10/05 20:25:43 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define DEAD_S 404

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

/* Data */

typedef struct data {
	int				acs;
	int				n_o_p;
	int				n_o_f;
	int				t_t_d;
	int				t_t_e;
	int				t_t_s;
	int				n_m_e;
	int				eat_c;
	int				mtx_sta;
	int				forks_sta;
	int				state;
	int				should_break;
	time_t			run_time;
	pthread_mutex_t	global_m;
	pthread_mutex_t	*mutex;
}	t_phi;

typedef struct philo {
	int			id;
	int			eat_c;
	int			t_t_d;
	time_t		last_time_eat;
	time_t		run_time;
	pthread_t	thread;
	t_phi		*global;
}	t_per;

/* Arguments parsing Functions */

int		arg_parsing(t_phi *p, char **av);
int		ft_atoi(const char *str);
int		ft_nopf(t_phi *p, char *str);
int		ft_ttd(t_phi *p, char *str);
int		ft_tte(t_phi *p, char *str);
int		ft_tts(t_phi *p, char *str);
int		ft_nme(t_phi *p, char *str);
int		check_str(char *str);

/* Program Functions */

int		ft_philo(t_phi *p);
int		start_philosophie(t_per *philo, t_phi *p);
int		init_philos(t_per *philo);
int		init_mutexes(t_phi *p, t_per *philo);
int		check_philo_state(t_per *philo);
void	free_resources(t_per *philo, t_phi *p);
void	*philo_actions(void *arg);
void	*check_threads(void *arg);
void	printf_message(t_per *philo, time_t t, char *str);
time_t	get_timestamp_ms(void);
t_per	*init_philo_data(t_phi *p);
void	my_usleep(int sleep_time);
int		check_for_nme(t_per *philo);
int		check_nme(t_per *philo);

/* Philosophers routine */

void	take_fork(t_per *philo);
void	start_eating(t_per *philo);
void	start_thinking(t_per *philo);
void	start_sleeping(t_per *philo);

#endif
