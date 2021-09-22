#include "minishell.h"

//copy the word in new node in the list
static void	copy_to_word(char *str, int *i, int *j, t_element *element)
{
	t_element	*new;
	int			aux_i;

	aux_i = 0;
	new = malloc(sizeof(t_element));
	new->str = malloc(*i - *j + 1);
	while(*j < *i)
	{
		new->str[aux_i] = str[*j];
		aux_i++;
		*j = *j + 1;
	}
	new->str[aux_i] = '\0';
	new->next = NULL;
	ft_lstadd_back(&element, new);
}

void	main_parse(char *str, t_element *element)
{
	int		i;
	int		j;
	bool	marks;

	marks = false;
	i = 0;
	j = 0;
	while (i <= (int)ft_strlen(str))
	{
		if (str[i] == '\0' || ((str[i] == ' ') && 
			(str[i + 1] != ' ')) || str[i] == 39 || str[i] == '"')
		{
			if (marks == false)
				copy_to_word(str, &i, &j, element);
		}
		i++;
	}
}

