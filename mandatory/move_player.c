/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:59:42 by kben-ham          #+#    #+#             */
/*   Updated: 2023/02/10 22:27:18 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	write_move(t_data *my_data)
{
	my_data->move++;
	ft_printf("%d moves\n", my_data->move);
}

static void	move_player1(t_data *my_data, int z)
{
	check_collectibles(my_data, my_data->c_p_indice_y, z);
	my_data->all[my_data->c_p_indice_y][my_data->c_p_indice_x] = '0';
	my_data->all[my_data->c_p_indice_y][z] = 'P';
	my_data->c_p_indice_x = z;
	draw_image_in_window(my_data);
	write_move(my_data);
}

static void	move_player2(t_data *my_data, int z)
{
	check_collectibles(my_data, z, my_data->c_p_indice_x);
	my_data->all[my_data->c_p_indice_y][my_data->c_p_indice_x] = '0';
	my_data->all[z][my_data->c_p_indice_x] = 'P';
	my_data->c_p_indice_y = z;
	draw_image_in_window(my_data);
	write_move(my_data);
}

int	move_player(int key, t_data *my_data)
{
	if (key == 53)
		exit(1);
	if ((key == 0 || key == 123) && check_direction(my_data->all
			[my_data->c_p_indice_y][my_data->c_p_indice_x - 1], my_data) == 1)
	{
		my_data->s = 0;
		move_player1(my_data, my_data->c_p_indice_x - 1);
	}
	if ((key == 2 || key == 124) && check_direction(my_data->all
			[my_data->c_p_indice_y][my_data->c_p_indice_x + 1], my_data) == 1)
	{
		my_data->s = 1;
		move_player1(my_data, my_data->c_p_indice_x + 1);
	}
	if ((key == 13 || key == 126) && check_direction(my_data->all
			[my_data->c_p_indice_y - 1][my_data->c_p_indice_x], my_data) == 1)
	{
		move_player2(my_data, my_data->c_p_indice_y - 1);
	}
	if ((key == 1 || key == 125) && check_direction(my_data->all
			[my_data->c_p_indice_y + 1][my_data->c_p_indice_x], my_data) == 1)
		move_player2(my_data, my_data->c_p_indice_y + 1);
	return (0);
}

int	out(void)
{
	exit(1);
}
