/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_ex2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:41:22 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/11 20:19:52 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

/*void	special_cases(t_element *p_elem)
{
	//char	*name[16];
	int		n;

	n = 0;
	//name = "🔥ShellFromHell🔥\0";
	if (ft_strlen(p_elem->str) == 2)
	{
		if (p_elem->str[0] == '$' && p_elem->str[0] == '0')
		{
			free(p_elem->str);
			p_elem->str = malloc (sizeof(char) * (ft_strlen(name) + 1));
			ft_strlcpy();
			//p_elem->str = ft_strdup("🔥ShellFromHell🔥\0");
			while (name[n] != '\0')
			{
				p_elem->str[n] = name[n];
				n++;
			}
		}
	}
}*/
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
