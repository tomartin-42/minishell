#include "minishell.h"

static void	get_tokens(char **str_split, t_param *param)
{
	int i;
	int j;

	i = 0;
	while (str_split[i])
	{
		j = 0;
		while(str_split[i][j])
		{
			if(str_split[i][j] == '|')
				param->n_comand++;
			if(str_split[i][j] == '<')
				param->n_inputf++;
			if(str_split[i][j] == '>')
				param->n_outputf++;
			j++;
		}
		i++;
	}
}

void	fast_parse(char *str, t_param *param)
{
	char **str_split;

	str_split = ft_split(str, ' ');
	get_tokens(str_split, param);
}

