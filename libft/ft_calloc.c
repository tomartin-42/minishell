/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 09:39:45 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/29 15:58:34 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	i;
	void	*z;

	i = nmemb * size;
	p = malloc (i);
	if (!p)
		return (NULL);
	z = p;
	while (i > 0)
	{
		*(unsigned char *) z++ = '\0';
		i--;
	}
	return (p);
}
