/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tommy <tommy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:51:06 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/02 20:00:38 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Free all env 
void	free_old_env(t_env *m_env)
{
	int	i;

	i = 0;
	while (m_env[i].end != true)
	{
		free(m_env[i].v_env);
		free(m_env[i].var[0]);
		free(m_env[i].var[1]);
		i++;
	}
	free(m_env);
}
//Add new var to env var list. The new var status is NOT VISIBLE
void	add_var_to_env(t_env *m_env, char *new_var)
{
	int	i;
	t_env	*aux_env;

	i = 0;
	while(m_env[i].end == false)
		i++;
	aux_env = malloc(sizeof(t_env) * (i + 2));
	aux_env[i].v_env = ft_strdup(new_var);
	aux_env[i].var = ft_split(aux_env[i].v_env, '=');
	aux_env[i].global = false;
	aux_env[i].visible = false;
	aux_env[i].del = false;
	aux_env[i].end = false;
	aux_env[i + 1].end = true;
	ft_memcpy(aux_env, m_env, sizeof(t_env) * i);
	free_old_env(m_env);
}

// Print enviroment var (only visible values);
void	print_env(t_env *m_env)
{
	int	i;

	i = 0;
	while (m_env[i].end == false)
	{
		printf("%s\n", m_env[i].v_env);
		i++;
	}
}
//Copy t_env struc to a double pointer only visible env_var, Them can use
//to past to exectve or ft_expor...
char	**copy_env_to_double_point(t_env *m_env)
{
	int		i;
	char	**dp_env;

	i = 0;
	while (m_env[i].end == false)
	{
		if (m_env[i].visible == true)
			i++;
	}
	dp_env = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (m_env[i].end == false)
	{
		if (m_env[i].visible == true)
			dp_env[i] = ft_strdup(m_env[i].v_env);
		i++;
	}
	dp_env[i] = NULL; 
	return (dp_env);
}
