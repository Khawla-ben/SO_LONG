/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:41:21 by kben-ham          #+#    #+#             */
/*   Updated: 2022/10/25 11:45:28 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *bi, const char *sm, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((!bi && !len) || sm[0] == '\0')
		return ((char *)bi);
	while (bi[i] && i < len)
	{
		j = 0;
		while (bi[i + j] && (bi[i + j] == sm[j]) && (i + j) < len)
			j++;
		if (!sm[j])
			return ((char *)bi + i);
		i++;
	}
	return (NULL);
}
