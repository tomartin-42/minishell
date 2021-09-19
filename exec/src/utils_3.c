/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 07:46:10 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/06 07:53:45 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;

	i = 0;
	while (s[i])
		i++;
	p = (char *)malloc (i + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	ft_strlen(const char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	res;

	res = 0;
	while ((*s1 || *s2) && (n > 0))
	{
		res = (unsigned char)*s1 - (unsigned char)*s2;
		if (res != 0)
			return (res);
		s1++;
		s2++;
		n--;
	}
	return (res);
}

static int	ft_checking(char a, char const *set)
{
	while (*set)
	{
		if (a == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*p;

	i = 0;
	k = 0;
	if (!s1)
		return (NULL);
	j = ft_strlen(s1);
	j--;
	while (ft_checking(s1[i], set) && *s1)
		i++;
	while (ft_checking(s1[j], set) && j >= i)
		j--;
	p = malloc ((j - i) + 2);
	if (!p)
	{
		return (NULL);
	}
	while (i <= j)
		p[k++] = s1[i++];
	p[k] = '\0';
	return (p);
}
