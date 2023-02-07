/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:22:47 by kben-ham          #+#    #+#             */
/*   Updated: 2022/10/24 16:08:31 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	f_start(char const*s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] && set[j])
	{
		while (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		j++;
	}
	return (i);
}

static	int	f_end(char const *s1, char const *set)
{
	int	k;
	int	d;

	k = ft_strlen(s1) - 1;
	d = 0;
	while (set[d] && k >= 0)
	{
		while (((char *)s1)[k] == ((char *)set)[d])
		{
			k--;
			d = 0;
		}
		d++;
	}
	return (k + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		r;
	int		start;
	int		end;
	char	*p;

	r = -1;
	if (!s1 || !set)
		return (0);
	start = f_start(s1, set);
	if ((size_t)start != ft_strlen(s1))
	{
		end = f_end(s1, set);
		p = malloc(end - start + 1);
		if (!p)
			return (NULL);
		while (s1[start] && start < end)
		{
			p[++r] = s1[start];
			start++;
		}
		p[++r] = '\0';
	}
	else
		return (ft_strdup(""));
	return (p);
}
