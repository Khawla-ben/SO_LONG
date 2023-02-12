/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fold.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:09:37 by kben-ham          #+#    #+#             */
/*   Updated: 2023/02/12 14:14:48 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

char	**create_new_map(int count, char *av)
{
	int		j;
	char	**all;
	int		fd;
	char	*line;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\n", 7);
		exit (1);
	}
	j = -1;
	all = malloc (sizeof(char *) * count);
	if (!all)
		return (NULL);
	while (++j < count)
	{
		line = get_next_line(fd);
		all[j] = ft_strdup_n(line);
		free(line);
	}
	return (all);
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
