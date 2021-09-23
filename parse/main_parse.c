#include "minishell.h"

static void	copy_to_word_d(char *str, int *i, int *j, t_element *element)
{
	t_element	*new;
	int			aux_i;

	aux_i = 0;
	new = malloc(sizeof(t_element));
	*i = *i + 1;
	while(str[*i] != '"' && str[*i] != '\0')
		*i += 1;
	new->str = malloc(*i - *j + 2);
	while(*j <= *i) 
	{
		new->str[aux_i] = str[*j];
		aux_i++;
		*j = *j + 1;
	}
	new->str[aux_i] = '\0';
	new->next = NULL;
	ft_lstadd_back(&element, new);

	}	

static void	copy_to_word_s(char *str, int *i, int *j, t_element *element)
{
	t_element	*new;
	int			aux_i;

	aux_i = 0;
	new = malloc(sizeof(t_element));
	*i = *i + 1;
	while(str[*i] != 39 && str[*i] != '\0')
		*i += 1;
	new->str = malloc(*i - *j + 2);
	while(*j <= *i) 
	{
		new->str[aux_i] = str[*j];
		aux_i++;
		*j = *j + 1;
	}
	new->str[aux_i] = '\0';
	new->next = NULL;
	ft_lstadd_back(&element, new);
}	

//copy the word in new node in the list
static void	copy_to_word(char *str, int *i, int *j, t_element *element)
{
	t_element	*new;
	int			aux_i;
	char		mark;

	mark = 'f';
	aux_i = 0;
	new = malloc(sizeof(t_element));
	*i = *i + 1;
	while((str[*i] != ' ' && str[*i] != '\0') && mark == 'f')
	{
		if (str[*i] == '"')
			mark = 'd';
		if (str[*i] == 39)
			mark = 's';
		*i += 1;
	}
	while  (mark != 'f')
	{
		if (mark == 'd' && str[*i] == '"')
			mark = 'f';
		if (mark == 's' && str[*i] == 39)
			mark = 'f';
		*i = *i + 1;
	}
	new->str = malloc(*i - *j + 2);
	while(*j <= *i) 
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

	i = 0;
	j = 0;
	while (i <= (int)ft_strlen(str) && str[i] != 0)
	{
		if (str[i] == '"')
		{
			//recoger hasta proxima "
			copy_to_word_d(str, &i, &j, element);
			i++;
		}
		if (str[i] == 39)
		{
			//recoger hasta proxima ' 
			copy_to_word_s(str, &i, &j, element);
			i++;
		}
		if (str[i] != ' ')  
			copy_to_word(str, &i, &j, element);
		i++;
	}
}

