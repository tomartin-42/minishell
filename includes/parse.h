#ifndef PARSE_H
# define PARSE_H

# include "minishell.h"

typedef struct s_mark{
	bool	mark_s;
	bool	mark_d;
	int		i;
	int		j;
}	t_mark;
//sec_parse_proc.c//
void	check_env(t_element *element);
void	arg_token(t_element *element);
void	sec_procesing(t_element *element);
////////////////////
void	clean_element(t_element *element);
void	pre_procesing(t_element *element);
void	post_procesing(t_element *element);
void	ini_var(t_mark *mark);
void	check_close_mark(char *str, bool *mark_s, bool *mark_d, int *i);
void	check_open_mark(char *str, bool *mark_s, bool *mark_d, int *i);
//int		check_fault_marks(char *str);
//void	rutine_parse(char *str, t_element *elemnet);
void	main_parse(char *str, t_element *elemen);
void	copy_to_word(char *str, int *i, int *j, t_element *element);

#endif
