#include "minishell.h"

static void	copy_to_marks(char *str, int *i, int *j, t_element *element)
{
	t_element	new;

	new.str = malloc(j - i + 1);
	while((str[*i] != '"' || str[*i] != ''') && str[*i])
	{
		new.str = str[*i];
		*i++;
	}
	new.str[*i] = '\0';
	*j = *i;
	ft_lstadd_back(elmeent, &new);
}

//copy the word in new node in the list
static void	copy_to_word(char *str, int *i, int *j, t_element *element)
{
	t_element	new;

	new.str = malloc(i - j + 1);
	while(str[*i] != ' ' && str[*i])
	{
		new.str = str[*i];
		*i++;
	}
	new.str[*i] = '\0';
	*j = *i;
	ft_lstadd_back(elmeent, &new);
}

//init the list
static void	init_element(t_element *element)
{
	element->next = NULL;
	element->pref = NULL;
}

void	main_parse(char *str, t_element *element)
{
	int		i;
	int		j;
	bool	marks;

	init_element(element);
	marks = false;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == ''')
		{
			marks = true;
			copy_to_maks(str, &i, &j, element);
			marks = false;
		}
		if(marks == false && str[i] == ' ' && str[i + 1] != ' ')
			copy_to_word(str, &i, &j, element);
		
		i++;
}

