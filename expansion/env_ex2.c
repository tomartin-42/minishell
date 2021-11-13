/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_ex2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:41:22 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/13 16:41:53 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	dollar_mark_if(t_element *p_elem, t_element *pp_elem, int x)
{
	int	n;

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
			dollar_mark_if(p_elem, pp_elem, x);
		}
	}
}
