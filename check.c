/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:43:25 by kben-ham          #+#    #+#             */
/*   Updated: 2023/02/07 23:02:33 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
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

void	check_count(t_data *my_data)
{	
	if (my_data->line[my_data->i] == '1'
		|| my_data->line[my_data->i] == '0'
		|| my_data->line[my_data->i] == 'E'
		|| my_data->line[my_data->i] == 'P'
		|| my_data->line[my_data->i] == 'C')
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
	if (my_data->line == NULL) //laho2a3lam
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
