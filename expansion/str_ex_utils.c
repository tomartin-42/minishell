/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_ex_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:41:39 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/11 19:47:59 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	remove_marks_loop(t_element *p_elem, int string_len, char mark)
{
	t_element	*copy_point;
	int			n;
	int			x;

	n = 0;
	x = 0;
	copy_point = p_elem;
	while (p_elem->str[x] != '\0' && string_len > 2)
	{
		if (copy_point->str[n] == mark)
			n++;
		p_elem->str[x] = copy_point->str[n];
		x++;
		if (copy_point->str[n] != '\0')
			n++;
	}
	if (string_len == 2)
	{
		p_elem->str[x] = '\0';
		p_elem->str[x + 1] = '\0';
	}
}
