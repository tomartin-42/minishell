/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_tolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:18:55 by davyd11           #+#    #+#             */
/*   Updated: 2021/10/19 13:30:15 by davyd11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*super_tolower(char *str)
{
//	int size_str;
	int	pos;
	//new_str;

//	size_str = ft_strlen(str);
	
	pos = 0;
	while (str[pos] != '\0')
	{
		if (str[pos] >= 65 && str[pos] <= 90)
			str[pos] = str[pos] + 32;
		pos++;
	}
	return (str);
}
