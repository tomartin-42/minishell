/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_ex2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:41:22 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/07 12:29:26 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	dollar_mark(t_element *p_elem)
{
	t_element	*pp_elem;
	int			n;
	int			x;

	pp_elem = p_elem;
	n = 0;
	x = 0;
	while (pp_elem->str[n] != '$' && pp_elem->str[n] != '\0')
		n++;
	if (pp_elem->str[n] == '$')
	{
		n++;
		if (pp_elem->str[n] == '"' || pp_elem->str[n] == 39)
		{
			n = 0;
			while (pp_elem->str[n] != '\0')
			{
				if (pp_elem->str[n] == '$')
					n++;
				p_elem->str[x] = pp_elem->str[n];
				x++;
				if (pp_elem->str[n] != '\0')
					n++;
			}
			p_elem->str[x] = '\0';
		}
	}
}
