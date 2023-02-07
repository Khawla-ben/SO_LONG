/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:03:45 by kben-ham          #+#    #+#             */
/*   Updated: 2023/02/06 15:01:37 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	nbr_words(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			j++;
		if ((s[i] == c && s[i + 1] == c))
			i++;
		if ((s[i] == c && s[i + 1] != c && s[i + 1] != '\0'))
			j++;
		i++;
	}
	return (j);
}

static	int	nbr_char(const char *s, char c)
{
	int	j;

	j = 0;
	while (s[j] != c && s[j])
		j++;
	return (j);
}

static	void	*free_table(char **tab, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free (tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		nbr_w;
	int		nbr_c;
	char	**p;

	i = 0;
	j = -1;
	if (!s)
		return (NULL);
	nbr_w = nbr_words(s, c);
	p = malloc(sizeof(char *) * (nbr_w + 1));
	if (!p)
		return (NULL);
	while (++j < nbr_w)
	{
		while (s[i] == c)
			i++;
		nbr_c = nbr_char(s + i, c);
		p[j] = ft_substr(s, i, nbr_c);
		if (!p[j])
			return (free_table(p, j));
		i += nbr_c;
	}
	return (p[j] = NULL, p);
}
