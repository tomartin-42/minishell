/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:19:48 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/31 20:21:11 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"
#include "errorlib.h"

char	**extract_all_env_list(t_env *env)
{
	t_env	*p_env;
	int		i;
	char	**list;

	i = 0;
	p_env = env;
	while (p_env)
	{
		i++;
		p_env = p_env->next;
	}
	list = malloc (sizeof(char *) * (i + 1));
	i = 0;
	p_env = env;
	while (p_env)
	{
		list[i] = ft_strdup(p_env->v_env);
		i++;
		p_env = p_env->next;
	}
	list[i] = NULL;
	return (list);
}

char	**extract_env_list(t_env *env)
{
	t_env	*p_env;
	int		i;
	char	**list;

	i = 0;
	p_env = env;
	while (p_env)
	{
		if (p_env->visible == true)
			i++;
		p_env = p_env->next;
	}
	list = malloc (sizeof(char *) * (i + 1));
	list[i] = NULL;
	i = 0;
	p_env = env;
	while (p_env)
	{
		if (p_env->visible == true)
			list[i++] = ft_strdup(p_env->v_env);
		p_env = p_env->next;
	}
	return (list);
}

static void	order_alphabet(char **list)
{
	char	*aux;
	int		i;
	int		j;

	i = 0;
	while (list[i] != NULL)
	{
		j = 1 + i;
		while (list[j] != NULL)
		{
			if (ft_strcmp(list[i], list[j]) > 0)
			{
				aux = list[i];
				list[i] = list[j];
				list[j] = aux;
			}
			j++;
		}
		i++;
	}
}

static void	print_env_alphabet_order(t_env *m_env)
{
	char	**list;
	int		i;

	i = 0;
	list = extract_env_list(m_env);
	order_alphabet(list);
	while (list[i] != NULL)
		printf("%s\n", list[i++]);
	ft_free_dp(list);
}

int	ft_export(t_env *m_env, char **args)
{
	int	i;

	i = 1;
	if (!args[1])
	{
		print_env_alphabet_order(m_env);
		return (0);
	}
	while (args[i] != NULL)
	{
		if (ft_isdigit(args[i][0]))
			return (error_export_number(args[i]));
		if (ft_strchr(args[i], '='))
			with_equal_export(m_env, args[i]);
		else
			without_equal_export(m_env, args[i]);
		i++;
	}
	return (0);
}
