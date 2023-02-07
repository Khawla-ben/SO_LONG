/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:28:56 by kben-ham          #+#    #+#             */
/*   Updated: 2022/10/27 00:13:12 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src == dst)
		return (dst);
	if (dst > src)
	{
		while (len > 0)
		{
			len--;
			(((unsigned char *)dst)[len] = ((unsigned char *)src)[len]);
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
