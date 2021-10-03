/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 21:35:19 by davyd11           #+#    #+#             */
/*   Updated: 2021/10/03 18:59:18 by davyd11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	id_expand(t_element *element)
{
	t_element *p_elem;
	int n;

	p_elem = element;
	n = 0;
	while (p_elem)
	{
		while (p_elem->str[n] != '\0')
		{
			if(p_elem->str[n] == '"')
			n++;
		}
		p_elem = p_elem->next;
	}
}
