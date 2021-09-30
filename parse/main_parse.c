/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:12:24 by tommy             #+#    #+#             */
/*   Updated: 2021/09/27 20:05:47 by davyd11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	rutine_parse(char *str, t_element *element)
{
	main_parse(str, element);
	clean_element(element);
	pre_procesing(element);
	ft_lst_del_all_x(element);
}

void	main_parse(char *str, t_element *element)
{
	t_mark	mk;

	ini_var(&mk);
	while (str[mk.i])
	{
		check_open_mark(str, &mk.mark_s, &mk.mark_d, &mk.i);
		if (ft_strchr("|<> ", str[mk.i]) && mk.mark_d == false
			&& mk.mark_s == false)
		{	
			if (ft_strchr("|<>", str[mk.i]))
			{
				mk.i--;
				copy_to_word(str, &mk.i, &mk.j, element);
				mk.i++;
			}
			copy_to_word(str, &mk.i, &mk.j, element);
		}
		if (str[mk.i] != '\0')
			mk.i++;
		check_close_mark(str, &mk.mark_s, &mk.mark_d, &mk.i);
		if (str[mk.i] == '\0')
			copy_to_word(str, &mk.i, &mk.j, element);
	}
}
