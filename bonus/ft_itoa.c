/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:56:45 by kben-ham          #+#    #+#             */
/*   Updated: 2023/02/10 22:03:17 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"
#include"get_next_line.h"

static	int	count_size(long a)
{
	int	size;

	size = 0;
	if (a == 0)
		return (1);
	if (a < 0)
	{
		size++;
		a *= -1;
	}
	while (a)
	{
		size++;
		a /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	long	r;
	char	*p;

	r = (long )n;
	size = count_size(r);
	if (n == 0)
		return (ft_strdup("0"));
	p = (char *)malloc((size * sizeof(char) + 1));
	if (!p)
		return (NULL);
	if (n < 0)
	{
		p[0] = '-';
		r = r * (-1);
	}
	p[size--] = '\0';
	while (r)
	{
		p[size--] = (r % 10) + '0';
		r /= 10;
	}
	return (p);
}
