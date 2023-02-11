/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:07:02 by kben-ham          #+#    #+#             */
/*   Updated: 2023/02/11 20:19:47 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_window(t_data *my_data)
{
	my_data->mlx = mlx_init();
	create_image(my_data);
	my_data->mlx_win = mlx_new_window(my_data->mlx,
			my_data->num * 60, my_data->count * 60, "so_long!");
	my_data->i = -1;
	while (++my_data->i < my_data->count)
	{
		my_data->j = -1;
		while (++my_data->j < my_data->num)
			mlx_put_image_to_window(my_data->mlx, my_data->mlx_win,
				my_data->im_space, my_data->j * 60, my_data->i * 60);
	}
	draw_image_in_window(my_data);
	mlx_hook(my_data->mlx_win, 02, 0, move_player, my_data);
	mlx_hook(my_data->mlx_win, 17, 0, out, my_data);
	mlx_loop(my_data->mlx);
}

void	create_image(t_data *my_data)
{
	int	img_width;
	int	img_height;

	my_data->im_player = mlx_xpm_file_to_image(my_data->mlx,
			"images/p.xpm", &img_width, &img_height);
	my_data->im_exit = mlx_xpm_file_to_image(my_data->mlx,
			"images/e.xpm", &img_width, &img_height);
	my_data->im_exit2 = mlx_xpm_file_to_image(my_data->mlx,
			"images/e2.xpm", &img_width, &img_height);
	my_data->im_collectible = mlx_xpm_file_to_image(my_data->mlx,
			"images/c.xpm", &img_width, &img_height);
	my_data->im_space = mlx_xpm_file_to_image(my_data->mlx,
			"images/s.xpm", &img_width, &img_height);
	my_data->im_wall = mlx_xpm_file_to_image(my_data->mlx,
			"images/w.xpm", &img_width, &img_height);
	my_data->im_player2 = mlx_xpm_file_to_image(my_data->mlx,
			"images/p2.xpm", &img_width, &img_height);
}

static void	if_function(t_data *my_data)
{
	if (my_data->all[my_data->i][my_data->j] == 'E')
	{
		if (my_data->c_c == 0)
		{
			mlx_put_image_to_window(my_data->mlx, my_data->mlx_win,
				my_data->im_space, my_data->j * 60, my_data->i * 60);
			mlx_put_image_to_window(my_data->mlx, my_data->mlx_win,
				my_data->im_exit2, my_data->j * 60, my_data->i * 60);
		}
		else
			mlx_put_image_to_window(my_data->mlx, my_data->mlx_win,
				my_data->im_exit, my_data->j * 60, my_data->i * 60);
	}
	else if (my_data->all[my_data->i][my_data->j] == 'P')
	{
		if (my_data->s == 1)
			mlx_put_image_to_window(my_data->mlx, my_data->mlx_win,
				my_data->im_player2, my_data->j * 60, my_data->i * 60);
		else
			mlx_put_image_to_window(my_data->mlx, my_data->mlx_win,
				my_data->im_player, my_data->j * 60, my_data->i * 60);
	}
}

int	draw_image_in_window(t_data *my_data)
{
	int	x;
	int	y;

	my_data->i = -1;
	while (++my_data->i < my_data->count)
	{
		my_data->j = -1;
		while (++my_data->j < my_data->num)
		{
			if (my_data->all[my_data->i][my_data->j] == '0')
				mlx_put_image_to_window(my_data->mlx, my_data->mlx_win,
					my_data->im_space, my_data->j * 60, my_data->i * 60);
			else if (my_data->all[my_data->i][my_data->j] == 'C')
				mlx_put_image_to_window(my_data->mlx, my_data->mlx_win,
					my_data->im_collectible, my_data->j * 60, my_data->i * 60);
			else if (my_data->all[my_data->i][my_data->j] == '1')
				mlx_put_image_to_window(my_data->mlx, my_data->mlx_win,
					my_data->im_wall, my_data->j * 60, my_data->i * 60);
		}
	}
	return (0);
}

void	check_collectibles(t_data *my_data, int x, int y)
{
	if (my_data->all[x][y] == 'C')
	{
		my_data->c_c -= 1;
		my_data->all[x][y] = '0';
		draw_image_in_window(my_data);
	}
	if (my_data->all[x][y] == 'E' && my_data->c_c == 0)
	{
		write(1, "YOU WIN !!!", 11);
		exit(1);
	}
}
