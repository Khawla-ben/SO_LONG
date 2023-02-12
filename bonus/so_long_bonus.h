/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:03:46 by kben-ham          #+#    #+#             */
/*   Updated: 2023/02/12 00:21:02 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<mlx.h>
# include <stdarg.h>

typedef struct my_data
{
	int		num;
	int		num1;
	int		count;
	char	*line;
	char	**all;
	char	**copy;
	int		i;
	int		j;
	int		c_p;
	int		c_e;
	int		c_c;
	int		fd;
	int		c_p_indice_x;
	int		c_p_indice_y;
	int		count1;
	int		y;
	void	*mlx;
	void	*mlx_win;
	void	*im_player;
	void	*im_player2;
	void	*im_exit;
	void	*im_exit2;
	void	*im_collectible;
	void	*im_space;
	void	*im_wall;
	void	*im_enemy1;
	void	*im_enemy2;
	void	*im_enemy3;
	int		s;
	int		move;
	int		n_n;
	char	*itoa;
}t_data;

//fold
char	**create_new_map(int count, char *av);
void	my_function(t_data *my_data, int c_p_indice_x, int c_p_indice_y);

//win
void	open_window(t_data *my_data);
void	create_image(t_data *my_data);
int		draw_image_in_window(t_data *my_data);
int		move_player(int key, t_data *my_data);
void	check_collectibles(t_data *my_data, int x, int y);
int		check_direction(char check, t_data *my_data);

//utils
char	*ft_strdup_n(char *s1);
int		search_str(char *bi, char *sm);

//check_maps
void	check_maps(char *av, t_data *my_data);

//check
void	back_tracking(t_data *my_data);
void	check_and_count(t_data *my_data);
void	check_num_wall(t_data *my_data);

//move_player
int		out(void);

//printf
int		ft_printf(const char *s, ...);

//enemy
int		draw_enemy(t_data *my_data);

//itoa
char	*ft_itoa(int n);
#endif