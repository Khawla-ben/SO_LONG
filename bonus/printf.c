/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:28:02 by kben-ham          #+#    #+#             */
/*   Updated: 2023/02/10 19:39:19 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static void	ft_printd(int c, int *count)
{
	long		nb ;

	nb = c;
	if (nb < 0)
	{
		ft_putchar('-');
		*count = *count + 1;
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_printd((nb / 10), count);
		ft_printd((nb % 10), count);
	}
	else
	{
		ft_putchar("0123456789"[nb]);
		*count = *count + 1;
	}
}

static int	ft_check(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		ft_printd(va_arg(args, int), &count);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(ptr, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			i++;
			count += ft_check(ptr, s[i]);
		}
		else if (s[i] != '\0')
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(ptr);
	return (count);
}
