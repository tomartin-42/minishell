/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procesing_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:07:23 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/24 12:58:40 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

//clean up spaces of element
void	clean_element(t_element *element)
{
	t_element	*p_elem;
	char		*aux;

	p_elem = element;
	while (p_elem)
	{
		aux = ft_strtrim(p_elem->str, " ");
		free(p_elem->str);
		p_elem->str = ft_strdup(aux);
		free(aux);
		p_elem = p_elem->next;
	}
	split_pipes(element);
}

void	split_pipes(t_element *element)
{
	char	mark;
	int		i;
	t_element	*p_elem;

	i = 0;
	mark = 'f';
	p_elem = element;
	while (p_elem)
	{
		//while (p_elem->str[i] != '\0')
		while (i < (int)ft_strlen(p_elem->str))
		{
			if ((mark == 'f') && p_elem->str[i] == '"')
			{
				mark = 'd';
				i++;
			}
			else if ((mark == 'f') && p_elem->str[i] == 39)
			{
				mark = 's';
				i++;
			}
			//if (p_elem->str[i] == '|' && mark == 'f')
			//	printf("pipe %d\n", i);	
			if (p_elem->str[i] !='\0')
			{
				i++;
			//	printf("%d**%c [%c]\n", i, mark, p_elem->str[i]);
			}
			if ((mark == 'd') && p_elem->str[i] == '"')
			{
				mark = 'f';
				i++;
			}
			else if ((mark == 's') && p_elem->str[i] == 39)
			{
				mark = 'f';
				i++;
			}
		//	printf("*  %d**%c\n", i, mark);
		}
		p_elem = p_elem->next;
	}
}	
