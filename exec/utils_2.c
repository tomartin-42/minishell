/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 07:43:11 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/19 21:20:39 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_tableword(const char *s, char c)
{
	int	i;

	i = 0;
	if (!*s)
		return (0);
	if (*s != c && *(s + 1))
		i = 1;
	while (*(s + 1))
	{
		if (*s == c && *(s + 1) != c && *(s + 1) != '\0')
			i++;
		s++;
	}
	return (i);
}

static void	ft_insert_table(char **table, char const *s, char c, int words)
{
	int	i;
	int	j;
	int	k;
	int	w;

	w = 0;
	i = 0;
	while (words-- > 0)
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		table[w] = (char *)malloc(sizeof(char) * (i - j + 1));
		k = 0;
		while (j < i)
			table[w][k++] = s[j++];
		table[w][k] = '\0';
		w++;
	}
	table[w] = NULL;
}
