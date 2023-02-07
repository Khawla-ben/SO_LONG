/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:19:19 by kben-ham          #+#    #+#             */
/*   Updated: 2022/10/25 21:35:42 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*p;

	if (size == SIZE_MAX && num == SIZE_MAX)
		return (NULL);
	p = malloc (num * size);
	if (!p)
		return (NULL);
	ft_bzero(p, num * size);
	return (p);
}
