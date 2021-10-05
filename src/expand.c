
#include "minishell.h"

//check if the string get some $ form make the change for 
//env var
static int	check_valid_dollar(char *str)
{
	bool	dollar;
	int		i;

	i = 0;
	dollar = false;
	while (str[i + 1] != '\0')
	{
		if ((str[i] == '$') && (str[i + 1] != ' ' && str[i + 1] != '\0')) 
			dollar = true;
		i++;
	}
	return (dollar);
}

//Get de valuo of env var or it's dont exits return empy string 
static char *change_expand(t_env *env, char *str)
{
	int		i;
	int		j;
	char	*varx;
	char	*var_value;

	i = 0;
	while ((str[i] != '$') && (str[i + 1] != ' ' || str[i + 1] != '\0')) 
		i++;
	i++;
	j = i;
	while (str[j] != ' ' && str[j] != '\0')
		j++;
	varx = ft_substr(str, i, (j - i));
	var_value = getenv(varx);
	if (var_value == NULL)
		return (ft_strdup(""));
	env = env;
	free(varx);
	return (var_value);
}

//This function remplace in the string the env var
//it's the heart of ft_expand
static char	*remplace_str(char *str, char *var_value)
{
	int		i;
	int		j;
	char	*aux;
	char	*aux2;

	i = 0;
	while ((str[i] != '$') && (str[i + 1] != ' ' || str[i + 1] != '\0')) 
		i++;
	aux = ft_substr(str, 0, i);
	aux = ft_super_strjoin(aux, var_value, 1);
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	j = i;
	while (str[j] != '\0')
		j++;
	aux2 = ft_substr(str, i, (j - i));
	aux = ft_super_strjoin(aux, aux2, 3);
	//free(str);
	str = ft_strdup(aux);
	free(aux);
	return (str);
}

//This function get a string and expand it with env var
char *ft_expand(t_env *m_env, char *str)
{
	char	*str_exp;
	char	*var_value;

	str_exp = ft_strdup(str);
//	free(str);
	while (check_valid_dollar(str_exp))
	{
		var_value = change_expand(m_env, str_exp);
		str_exp = remplace_str(str_exp, var_value);
	}
	str = ft_strdup(str_exp);
	free(str_exp);
	printf("[[%s]]\n", str);
	return (str);
}
