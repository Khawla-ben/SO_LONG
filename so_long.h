/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:03:46 by kben-ham          #+#    #+#             */
/*   Updated: 2023/02/09 22:45:14 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<mlx.h>

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

}t_data;

typedef struct image
{
	void	*im_player;
	void	*im_exit;
	void	*im_collectible;
	void	*im_space;
	void	*im_wall;
}t_image;

//fold
char	**create_new_map(int count, char *av);
void	my_function(t_data *my_data, int c_p_indice_x, int c_p_indice_y);

//win
void	open_window(t_image *image, t_data *my_data);
void	create_image(t_image *image, t_data *my_data);
void	draw_image_in_window(t_data *my_data, t_image *image);

//utils
char	*ft_strdup_n(char *s1);
int		search_str(char *bi, char *sm);

//check_maps
void	check_maps(char *av, t_data *my_data);

//check
void	back_tracking(t_data *my_data);
void	check_count(t_data *my_data);
void	check_num_wall(t_data *my_data);

#endif