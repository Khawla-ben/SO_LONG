/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:43:25 by kben-ham          #+#    #+#             */
/*   Updated: 2023/02/12 14:22:10 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "get_next_line.h"

void	back_tracking(t_data *my_data)
{
	my_function(my_data, my_data->c_p_indice_x, my_data->c_p_indice_y);
	my_data->i = -1;
	while (++my_data->i < my_data->count1)
	{
		my_data->j = -1;
		while (++my_data->j < my_data->num)
		{
			if (my_data->copy[my_data->i][my_data->j] == 'C')
			{
				write (2, "Error\ninvalid path!!", 21);
				exit(1);
			}
			if (my_data->copy[my_data->i][my_data->j] == 'E')
			{
				if ((my_data->copy[my_data->i][my_data->j + 1] != 'K')
				&& (my_data->copy[my_data->i][my_data->j - 1] != 'K')
				&& (my_data->copy[my_data->i - 1][my_data->j] != 'K' )
				&& (my_data->copy[my_data->i + 1][my_data->j] != 'K' ))
				{
					write(2, "Error\ninvalid path!!", 21);
					exit(1);
				}
			}
		}
	}
}

void	check_and_count(t_data *my_data)
{	
	if (my_data->line[my_data->i] == '1'
		|| my_data->line[my_data->i] == '0'
		|| my_data->line[my_data->i] == 'E'
		|| my_data->line[my_data->i] == 'P'
		|| my_data->line[my_data->i] == 'C'
		|| my_data->line[my_data->i] == 'N')
	{
		if (my_data->line[my_data->i] == 'E')
			my_data->c_e++;
		else if (my_data->line[my_data->i] == 'P')
		{
			my_data->c_p_indice_x = my_data->i;
			my_data->c_p_indice_y = my_data->count - my_data->y;
			my_data->c_p++;
		}
		else if (my_data->line[my_data->i] == 'C')
			my_data->c_c++;
		my_data->i++;
	}
	else
	{
		write(2, "Error\noops!!intruder has detected", 34);
		exit (1);
	}
}

void	check_num_wall(t_data *my_data)
{
	my_data->line = get_next_line(my_data->fd);
	if (my_data->line == NULL)
		return ;
	my_data->num1 = (ft_strlen(my_data->line) - 1);
	if (my_data->num != my_data->num1)
	{
		write(2, "Error\nThe map must be rectangular.", 35);
		exit (1);
	}
	if ((my_data->line[my_data->num1 - 1] != '1')
		|| (my_data->line[0] != '1'))
	{
		write(2, "Error\nThe map must be closed by walls.", 39);
		exit (1);
	}
}

void	my_function(t_data *my_data, int c_p_indice_x, int c_p_indice_y)
{
	if (my_data->copy[c_p_indice_y][c_p_indice_x] == '1'
		|| my_data->copy[c_p_indice_y][c_p_indice_x] == 'E'
		|| my_data->copy[c_p_indice_y][c_p_indice_x] == 'K')
		return ;
	my_data->copy[c_p_indice_y][c_p_indice_x] = 'K';
	my_function(my_data, c_p_indice_x - 1, c_p_indice_y);
	my_function(my_data, c_p_indice_x + 1, c_p_indice_y);
	my_function(my_data, c_p_indice_x, c_p_indice_y - 1);
	my_function(my_data, c_p_indice_x, c_p_indice_y + 1);
}
