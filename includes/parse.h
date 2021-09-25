#ifndef PARSE_H
# define PARSE_H

# include "minishell.h"

typedef struct s_mark{
	bool	mark_s;
	bool	mark_d;
	int		i;
	int		j;
}	t_mark;

void	clean_element(t_element *element);

#endif
