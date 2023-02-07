/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:13:05 by kben-ham          #+#    #+#             */
/*   Updated: 2023/02/07 21:47:17 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

char	*ft_strdup_n(char *s1)
{
	int		i;
	char	*p;

	i = 0;
	p = malloc((ft_strlen(s1)));
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	return (p);
}

int	search_str(char *bi, char *sm)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((!bi) || sm[0] == '\0')
		return (0);
	while (bi[i])
	{
		j = 0;
		while (bi[i + j] && (bi[i + j] == sm[j]))
			j++;
		if (!sm[j])
			return (1);
		i++;
	}
	return (0);
}
