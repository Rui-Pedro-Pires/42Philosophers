/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:10:03 by ruiolive          #+#    #+#             */
/*   Updated: 2024/01/15 14:25:28 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	monitoring(t_philo *philos)
{
	int			n;
	int			count;
	long long	diff_time;

	n = 0;
	count = 0;
	while (n < philos->data->numbers_of_philosophers)
	{
		diff_time = gettime() - get_info_long(&philos->data->info, \
			&philos[n].last_meal);
		if (philos->data->time_to_die <= diff_time && \
		get_info_int(&philos[n].philo, &philos[n].status) != EATING)
			return (dead_print(&philos[n]));
		if (philos->data->number_of_times_to_eat == \
			get_info_long(&philos[n].philo, &philos[n].number_of_meal))
			count++;
		n++;
	}
	if (philos->data->numbers_of_philosophers == count)
		set_bool(&philos->data->info, &philos->data->finish, true);
	return (1);
}

int	dead_print(t_philo *philo)
{
	long long	current_time;

	current_time = gettime();
	printf("%lld %d died\n", current_time - \
	get_info_long(&philo->data->info, &philo->start_time), philo->id);
	set_bool(&philo->data->info, &philo->data->finish, true);
	set_info_int(&philo->philo, &philo->status, DEAD);
	return (1);
}
