/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:53:23 by kben-ham          #+#    #+#             */
/*   Updated: 2023/02/12 14:45:46 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_enemy(int i, int j, t_data *my_data)
{
	if (my_data->all[i][j] == 'N')
	{
		mlx_put_image_to_window(my_data->mlx, my_data->mlx_win,
			my_data->im_space, j * 60, i * 60);
		if (my_data->n_n <= 300)
			mlx_put_image_to_window(my_data->mlx, my_data->mlx_win,
				my_data->im_enemy2, j * 60, i * 60);
		else if (my_data->n_n >= 300 && my_data->n_n <= 600)
			mlx_put_image_to_window(my_data->mlx, my_data->mlx_win,
				my_data->im_enemy3, j * 60, i * 60);
		else if (my_data->n_n >= 600 && my_data->n_n <= 900)
			mlx_put_image_to_window(my_data->mlx, my_data->mlx_win,
				my_data->im_enemy1, j * 60, i * 60);
		else
			my_data->n_n = 0;
		my_data->n_n++;
	}
}

int	draw_enemy(t_data *my_data)
{
	my_data->i = -1;
	while (++my_data->i < my_data->count)
	{
		my_data->j = -1;
		while (++my_data->j < my_data->num)
			check_enemy(my_data->i, my_data->j, my_data);
	}
	return (0);
}
