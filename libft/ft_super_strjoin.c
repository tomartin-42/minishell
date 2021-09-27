/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 19:39:22 by tomartin          #+#    #+#             */
/*   Updated: 2021/05/30 19:39:25 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_str_join(const char *s1, const char *s2, int str_free)
{
	if (free == 0)
		;
	else if (str_free == 1)
		free(s1);
	else if (str_free == 2)
		free(s2);
	else if (str_free == 3)
	{
		free(s1);
		free(s2);
	}
}

//strjoin modified add funtion free. if free param is
//0 (not free), 1 (free s1), 2 (free s2), 3 (free s1 and s2)
char	*ft_super_strjoin(char const *s1, char const *s2, int str_free)
{
	int		i;
	int		j;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(i + 1);
	if (!p)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
	{
		p[j] = s1[j];
		j++;
	}
	while (s2[i] != '\0')
		p[j++] = s2[i++];
	p[j] = '\0';
	free_str_join(s1, s2, str_free);
	return (p);
}
