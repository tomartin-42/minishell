/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:33:34 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/13 14:27:08 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_get_env(t_env *m_env, char *var_name)
{
	char	*value;
	t_env	*p_env;

	p_env = m_env;
	value = ft_strdup("");
	while (p_env)
	{
		if (ft_strcmp(p_env->var[0], var_name) == 0 && p_env->visible == true)
		{
			free(value);
			value = ft_strdup(p_env->var[1]);
		}
		p_env = p_env->next;
	}
	return (value);
}

//check if the string get some $ form make the change for 
//env var
static int	check_valid_dollar(char *str)
{
	bool	dollar;
	int		i;

	i = 0;
	dollar = false;
	while (str[i] != '\0')
	{
		if ((str[i] == '$') && (str[i + 1] != ' ' && str[i + 1] != '\0'
				&& str[i + 1] != '"' && str[i + 1] != 39))
			dollar = true;
		i++;
	}
	return (dollar);
}

//Get de value of env var or it's dont exits return empy string 
static char	*change_expand(t_env *env, char *str)
{
	int		i;
	int		j;
	char	*varx;
	char	*var_value;

	i = 0;
	var_value = NULL;
	while (str[i] != '$' && str[i] != '\0')
		i++;
	i++;
	j = i;
	while (str[j] != 39 && str[j] != '"' && str[j] != ' ' && str[j] != '\0')
		j++;
	varx = ft_substr(str, i, (j - i));
	if (errno_dollar(str))
	{
		var_value = ft_get_env(env, varx);
	}	
	else if (!errno_dollar(str))
		var_value = ft_itoa(g_state);
	if (var_value == NULL)
		return (ft_strdup(""));
	free(varx);
	return (var_value);
}

//This function remplace in the string the env var
//it's the heart of ft_expand
char	*remplace_str(char *str, char *var_value)
{
	int		i;
	int		j;
	char	*aux;
	char	*aux2;

	i = 0;
	while ((str[i] != '$') && (str[i + 1] != ' ' || str[i + 1] != '\0'
			|| str[i + 1] != '"' || str[i + 1] != 39))
		i++;
	aux = ft_substr(str, 0, i);
	aux = ft_super_strjoin(aux, var_value, 1);
	while (str[i] != ' ' && str[i] != '\0' && str[i] != '"' && str[i] != 39)
		i++;
	j = i;
	while (str[j] != '\0')
		j++;
	aux2 = ft_substr(str, i, (j - i));
	aux = ft_super_strjoin(aux, aux2, 3);
	free (str);
	str = ft_strdup(aux);
	free(aux);
	return (str);
}

//This function get a string and expand it with env var
char	*ft_expand(t_env *m_env, char *str)
{
	char	*str_exp;
	char	*var_value;

	str_exp = ft_strdup(str);
	while (check_valid_dollar(str_exp))
	{
		var_value = change_expand(m_env, str_exp);
		str_exp = remplace_str(str_exp, var_value);
		free(var_value);
	}
	str = ft_strdup(str_exp);
	free(str_exp);
	return (str);
}
