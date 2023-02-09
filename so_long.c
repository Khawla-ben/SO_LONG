/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:11:50 by kben-ham          #+#    #+#             */
/*   Updated: 2023/02/08 18:24:23 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

static	int	check_line(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	if (line == NULL)
	{
		write (2, "Error\nfillmap!!", 16);
		exit(1);
	}
	while (line != NULL)
	{
		line = get_next_line(fd);
		i++;
	}
	return (i);
}

static void	do_it(char **av)
{
	int		fd;
	char	*sm;
	t_data	*my_data;
	t_image	*image;

	my_data = malloc(sizeof(t_data));
	sm = ".ber";
	if (search_str(av[1], sm) == 0)
	{
		write(2, "Error\ni need maps.ber", 22);
		exit (1);
	}
	my_data->fd = open(av[1], O_RDONLY);
	if (my_data->fd == -1)
	{
		write(2, "Error\n", 7);
		exit (1);
	}
	my_data->count = check_line(my_data->fd);
	check_maps(av[1], my_data);
	open_window(image, my_data);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		do_it(av);
	else
	{	
		write(2, "Error\ncheck parameters.", 24);
		exit (1);
	}
}
