/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:53:23 by kben-ham          #+#    #+#             */
/*   Updated: 2023/02/14 15:52:01 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_it(int i, int j, t_data *my_data)
{
	if (my_data->n_n <= 100)
		mlx_put_image_to_window(my_data->mlx, my_data->mlx_win,
			my_data->im_enemy3, j * 60, i * 60);
	else if (my_data->n_n > 100 && my_data->n_n <= 200)
		mlx_put_image_to_window(my_data->mlx, my_data->mlx_win,
			my_data->im_enemy1, j * 60, i * 60);
	else if (my_data->n_n > 200 && my_data->n_n <= 300)
		mlx_put_image_to_window(my_data->mlx, my_data->mlx_win,
			my_data->im_enemy2, j * 60, i * 60);
	else
		my_data->n_n = 0;
	my_data->n_n++;
}

static void	move_it(int i, int j, t_data *my_data)
{
	if (my_data->m_n == 0)
	{
		if (my_data->all[i][j - 1] == '0')
		{
			my_data->all[i][j] = '0';
			my_data->all[i][j - 1] = 'N';
		}
		else if (my_data->all[i][j - 1] == 'P')
		{
			write(1, "YOU LOSE !!!", 12);
			exit(1);
		}
		else
			my_data->m_n = 1;
	}
}

void	check_enemy(int i, int j, t_data *my_data)
{
	put_it(i, j, my_data);
	if (my_data->n_n_n == 20)
	{
		move_it(i, j, my_data);
		if (my_data->m_n == 1)
		{
			if (my_data->all[i][j + 1] == '0')
			{
				my_data->all[i][j] = '0';
				my_data->all[i][j + 1] = 'N';
			}
			else if (my_data->all[i][j + 1] == 'P')
			{
				write(1, "YOU LOSE !!!", 12);
				exit(1);
			}
			else
				my_data->m_n = 0;
		}
	}
	else if (my_data->n_n_n > 40)
		my_data->n_n_n = 0;
	my_data->n_n_n++;
}
