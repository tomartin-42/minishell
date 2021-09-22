#include "minishell.h"

//copy the string (mask) in new node in the list
static void	copy_to_marks(char *str, int *i, int *j, t_element *element)
{
	t_element	*new;

	new = malloc(sizeof(t_element));
	new->str = malloc(*i - *j + 2);
	while((str[*i] != '"' || str[*i] != 39) && str[*i] != '\0')
	{
		new->str[*i] = str[*i];
		*i = *i + 1;
	}
	new->str[*i] = '\0';
	*j = *i;
	ft_lstadd_back(&element, new);
}

//copy the word in new node in the list
static void	copy_to_word(char *str, int *i, int *j, t_element *element)
{
	t_element	*new;
	int			aux_i;

	aux_i = *j;
	new = malloc(sizeof(t_element));
	new->str = malloc(*i - *j + 2);
	while(str[aux_i] != ' ' && str[aux_i] != '\0')
	{
		new->str[aux_i] = str[aux_i];
		aux_i++;
	}
	new->str[aux_i] = '\0';
	*i = aux_i;
	*j = *i;
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
	while (str[i] != '\0')
	{
		if (str[i] == '"' || str[i] == 39)
		{
			marks = true;
			copy_to_marks(str, &i, &j, element);
			marks = false;
		}
		if(marks == false && (str[i] == '\0' || (str[i] == ' ' && str[i + 1] != ' ')))
		{
			printf("DDDDDDDDDDD\n");
			copy_to_word(str, &i, &j, element);
		}
		i++;
	}
}

