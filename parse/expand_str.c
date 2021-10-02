/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 21:35:19 by davyd11           #+#    #+#             */
/*   Updated: 2021/10/01 20:49:07 by davyd11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	id_expand(t_element *element)
{
	t_element *p_elem;

	p_elem = element;
	while (p_elem)
	{
		if (p_elem->type == "")
		p_elem = p_elem->next;
	}
}
