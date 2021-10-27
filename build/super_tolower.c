/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_tolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:18:55 by davyd11           #+#    #+#             */
/*   Updated: 2021/10/27 15:45:24 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*super_tolower(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		if (str[pos] >= 65 && str[pos] <= 90)
			str[pos] = str[pos] + 32;
		pos++;
	}
	return (str);
}
