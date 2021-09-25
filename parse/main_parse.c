/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:12:24 by tommy             #+#    #+#             */
/*   Updated: 2021/09/25 11:18:51 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	copy_to_word(char *str, int *i, int *j, t_element *element)
{
	t_element	*new;
	int			aux_i;

	aux_i = 0;
	new = malloc(sizeof(t_element));
	new->str = malloc(*i - *j + 2);
	while (*j <= *i)
	{
		new->str[aux_i] = str[*j];
		aux_i++;
		*j = *j + 1;
	}
	new->str[aux_i] = '\0';
	new->next = NULL;
	if (new->str[0] != ' ')
	{
		if (ft_strlen(new->str) != 0)
			ft_lstadd_back(&element, new);
		else
		{
			free(new->next);
			free(new);
		}
	}
}

static void	check_open_mark(char *str, bool *mark_s, bool *mark_d, int *i)
{
	if (*mark_d == false && *mark_s == false && str[*i] == '"')
		*mark_d = true;
	if ((*mark_s == false && *mark_d == false) && str[*i] == 39)
		*mark_s = true;
}

static void	check_close_mark(char *str, bool *mark_s, bool *mark_d, int *i)
{
	if (*mark_d == true && *mark_s == false && str[*i] == '"')
	{
		*mark_d = false;
		*i += 1;
	}
	if (*mark_s == true && *mark_d == false && str[*i] == 39)
	{	
		*mark_s = false;
		*i += 1;
	}
}

void	main_parse(char *str, t_element *element)
{
	bool	mark_s;
	bool	mark_d;
	int		i;
	int		j;

	mark_s = false;
	mark_d = false;
	i = 0;
	j = 0;
	while (str[i])
	{
		check_open_mark(str, &mark_s, &mark_d, &i);
		if (ft_strchr("|<> ", str[i]) && mark_d == false && mark_s == false)
		{	
			if (ft_strchr("|<>", str[i]))
			{
				i--;
				copy_to_word(str, &i, &j, element);
				i++;
			}
			copy_to_word(str, &i, &j, element);
		}
		if (str[i] != '\0')
			i++;
		check_close_mark(str, &mark_s, &mark_d, &i);
		if (str[i] == '\0')
			copy_to_word(str, &i, &j, element);
	}
	clean_element(element);
}
