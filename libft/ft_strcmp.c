/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 09:05:17 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/29 15:52:31 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	res;

	res = 0;
	while ((*s1 || *s2))
	{
		res = (unsigned char)*s1 - (unsigned char)*s2;
		if (res != 0)
			return (res);
		s1++;
		s2++;
	}
	return (res);
}
