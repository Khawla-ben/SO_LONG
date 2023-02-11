/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:09:37 by kben-ham          #+#    #+#             */
/*   Updated: 2023/02/11 19:44:20 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "get_next_line.h"

char	**create_new_map(int count, char *av)
{
	int		j;
	char	**all;
	int		fd;

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
		all[j] = ft_strdup_n(get_next_line(fd));
	return (all);
}

int	check_direction(char check, t_data *my_data)
{
	if (check == '1' || (check == 'E' && my_data->c_c))
		return (0);
	else
		return (1);
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
	if (my_data->all[x][y] == 'N')
	{
		write(1, "YOU LOSE !!!", 12);
		exit(1);
	}
}
