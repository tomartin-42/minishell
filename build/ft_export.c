/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 19:45:05 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/03 18:15:34 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

void	promotion_local_to_global(t_env *m_env, int position)
{
	m_env[position].global = true;
	m_env[position].visible = true;
}

//Cange the value of a env var. j indicate the podition of
//env var
void	change_env_var_value(t_env *m_env, char *var, int position)
{
	free(m_env[position].v_env);
	free(m_env[position].var[0]);
	free(m_env[position].var[1]);
	m_env[position].v_env = ft_strdup(var);
	m_env[position].var = ft_split(var, '=');
	m_env[position].global = true;
	m_env[position].visible = true;
}

//Search if exist de env var and return the locating the var
//in t_env in other case and don't found the var return -1 
int	locate_env_var(t_env *m_env, char *var)
{
	int		i;
	char	**v_search;

	v_search = ft_split(var, '=');
	i = 0;
	while (m_env[i].end == false)
	{
		if (ft_strcmp(m_env[i].var[0], v_search[0]) == 0)
		{
			free(v_search[0]);
			free(v_search[1]);
			free(v_search);
			return (i) ;
		}
		i++;
	}
	free(v_search[0]);
	free(v_search[1]);
	free(v_search);
	return (-1);
}

//Order and print env var list in alphber order
static void	order_env(char **env_lst)
{
	int		i;
	int		j;
	char	*aux;

	i = 0;
	while (env_lst[i])
	{
		j = i + 1;
		while (env_lst[j] != NULL)
		{
			if (ft_strcmp(env_lst[i], env_lst[j]) > 0)
			{
				aux = env_lst[i];
				env_lst[i] = env_lst[j];
				env_lst[j] = aux;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (env_lst[i])
		printf("\"%s\"\n", env_lst[i++]);
	ft_free_dp(env_lst);
}

void	ft_export(t_env *m_env, char **args)
{
	char	**env_lst;
	int	i;
	int	j;

	i = 0;
	if (!args)
	{
		env_lst = copy_env_to_double_point(m_env);
		order_env(env_lst);
	}
	else
	{
		while (args[i] == NULL)
		{
			if (ft_isdigit(args[i][0]))
				printf("ERROR !!!!!!!! No puede empezar por num\n");
			else
			{
				if (ft_strchr(args[i], '='))
				{
					if ((locate_env_var(m_env, args[i])) < 0)
						add_var_to_env_global(m_env, args[i]);
					else
					{
						j = locate_env_var(m_env, args[i]);
						change_env_var_value(m_env, args[i], j);
					}
				}
				else
				{
					if ((locate_env_var(m_env, args[i])) >= 0)
					{
						j = locate_env_var(m_env, args[i]);
						promotion_local_to_global(m_env, j);
					}
				}
			}
			i++;
		}
	}			
}
