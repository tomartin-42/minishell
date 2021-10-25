/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 20:00:11 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/22 20:03:45 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	ft_count_char(char *str, char	caracter)
{
	int	pos;
	int	count;

	count = 0;
	pos = 0;
	while (str[pos] != '\0')
	{
		if (str[pos] == caracter)
			count++;
		pos++;
	}
	return (count);
}
