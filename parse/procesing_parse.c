/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procesing_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tommy <tommy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:07:23 by tomartin          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/09/24 18:41:50 by tommy            ###   ########.fr       */
=======
/*   Updated: 2021/09/24 13:13:05 by tomartin         ###   ########.fr       */
>>>>>>> 5af4bf4f3ccf48ee5cb1c3eacdc4f2c1042c8b3e
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

/*static void	clean_empy_nodes(t_element *element)
{
	t_element *p_aux;
	
	p_aux = element;
	while (p_aux)
	{
		if (ft_strlen(p_aux->str) == 0);

		free(p_elem->str);
		p_elem->str = ft_strdup(aux);
		free(aux);
		p_aux = p_aux->next;
	}
	

}*/

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
	//split_pipes(element);
}

/*void	split_pipes(t_element *element)
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
}*/	
