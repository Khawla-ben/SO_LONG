/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:07:02 by kben-ham          #+#    #+#             */
/*   Updated: 2023/02/09 22:46:06 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_window(t_image *image, t_data *my_data)
{
	my_data->mlx = mlx_init();
	create_image(image, my_data);
	my_data->mlx_win = mlx_new_window(my_data->mlx, my_data->num * 60, my_data->count * 60, "so_long!");
	my_data->i = -1;
	while (++my_data->i < my_data->count)
	{
		my_data->j = -1;
		while (++my_data->j < my_data->num)
			mlx_put_image_to_window(my_data->mlx, my_data->mlx_win, image->im_space, my_data->j * 60, my_data->i * 60);
	}
	draw_image_in_window(my_data, image);
	
	mlx_loop(my_data->mlx);
}

void	create_image(t_image *image, t_data *my_data)
{
	int	img_width;
	int	img_height;

	my_data->mlx = mlx_init();
	image->im_player = mlx_xpm_file_to_image(my_data->mlx, "images/p.xpm", &img_width, &img_height);
	image->im_exit = mlx_xpm_file_to_image(my_data->mlx, "images/e.xpm", &img_width, &img_height);
	image->im_collectible = mlx_xpm_file_to_image(my_data->mlx, "images/c.xpm", &img_width, &img_height);
	image->im_space = mlx_xpm_file_to_image(my_data->mlx, "images/s.xpm", &img_width, &img_height);
	image->im_wall = mlx_xpm_file_to_image(my_data->mlx, "images/w.xpm", &img_width, &img_height);
}

void	draw_image_in_window(t_data *my_data, t_image *image)
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
				mlx_put_image_to_window(my_data->mlx, my_data->mlx_win, image->im_space, my_data->j * 60, my_data->i * 60);
			if (my_data->all[my_data->i][my_data->j] == 'C')
				mlx_put_image_to_window(my_data->mlx, my_data->mlx_win, image->im_collectible, my_data->j * 60, my_data->i * 60);
			else if (my_data->all[my_data->i][my_data->j] == 'P')
				mlx_put_image_to_window(my_data->mlx, my_data->mlx_win, image->im_player, my_data->j * 60, my_data->i * 60);
			else if (my_data->all[my_data->i][my_data->j] == 'E')
				mlx_put_image_to_window(my_data->mlx, my_data->mlx_win, image->im_exit, my_data->j * 60, my_data->i * 60);
			else if (my_data->all[my_data->i][my_data->j] == '1')			
				mlx_put_image_to_window(my_data->mlx, my_data->mlx_win, image->im_wall, my_data->j * 60, my_data->i * 60);
		}
	}
}

// int mlx_hook ( void *win_ptr, int (*funct_ptr)(), void *param )
// {
	
// }




// mlx_hook(vars.win, 2, 1L<<0, close, &vars);
// mlx_key_hook ()


// void destroy_window(t_data *my_data)
// {
// 	mlx_destroy_window(my_data->mlx, my_data->win);
// }