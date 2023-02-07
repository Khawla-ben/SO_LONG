/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:14:19 by kben-ham          #+#    #+#             */
/*   Updated: 2022/10/27 01:38:43 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	len2;
	char			*p;

	i = 0;
	if (!s)
		return (NULL);
	len2 = ft_strlen(s + start);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start > ft_strlen(s))
		len2 = 0;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (s[start + i] && i < len && start < ft_strlen(s))
	{
		p[i] = s [i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}
