/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:07:59 by kben-ham          #+#    #+#             */
/*   Updated: 2023/02/14 13:57:28 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "get_next_line.h"

static void	check_line1(int fd, t_data *my_data)
{
	my_data->line = get_next_line(fd);
	my_data->num = ft_strlen(my_data->line) - 1;
	if (my_data->count > my_data->num || my_data->count == my_data->num)
	{
		write(2, "Error\ncheck the size of (longest && length).", 45);
		exit (1);
	}
	while (my_data->line[my_data->i] != '\n')
	{
		if (my_data->line[my_data->i] != '1')
		{
			write(2, "Error\nThe map must be closed by walls.", 39);
			exit (1);
		}
		else
			my_data->i++;
	}
	free(my_data->line);
}

static void	check_last_line(int fd, t_data *my_data)
{
	my_data->i = 0;
	my_data->line = get_next_line(fd);
	my_data->num1 = ft_strlen(my_data->line);
	if (my_data->num != my_data->num1)
	{
		write(2, "Error\nThe map must be rectangular.", 35);
		exit (1);
	}
	while ((my_data->line[my_data->i] != '\0'))
	{
		if (my_data->line[my_data->i] != '1')
		{
			write(2, "Error\nThe map must be closed by walls.", 39);
			exit (1);
		}
		else
			my_data->i++;
	}
	free(my_data->line);
}

static void	check_c_p_e(t_data *my_data)
{
	if (my_data->c_e != 1)
	{
		write(2, "Error\nThe map must contain 1 exit", 34);
		exit (1);
	}
	if (my_data->c_p != 1)
	{
		write(2, "Error\nThe map must contain 1 position", 38);
		exit (1);
	}
	if (my_data->c_c < 1)
	{
		write(2, "Error\nThe map must contain at least 1 collectible.", 51);
		exit (1);
	}
}

static void	initialize(t_data *my_data)
{
	my_data->y = -1;
	my_data->c_e = 0;
	my_data->c_c = 0;
	my_data->c_p = 0;
	my_data->i = 0;
	my_data->s = 0;
	my_data->count1 = my_data->count;
	my_data->y = my_data->count - 1;
	my_data->n_n = 0;
	my_data->n_n_n = 0;
	my_data->m_n = 0;
}

void	check_maps(char *av, t_data *my_data)
{
	initialize(my_data);
	my_data->fd = open(av, O_RDONLY);
	check_line1(my_data->fd, my_data);
	while (my_data->y > 1)
	{
		check_num_wall(my_data);
		my_data->i = 0;
		while (my_data->line[my_data->i] != '\n')
			check_and_count(my_data);
		free(my_data->line);
		my_data->y--;
	}
	check_c_p_e(my_data);
	check_last_line(my_data->fd, my_data);
	my_data->all = create_new_map(my_data->count1, av);
	my_data->copy = create_new_map(my_data->count1, av);
	back_tracking(my_data);
}
