/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 20:50:17 by davyd11           #+#    #+#             */
/*   Updated: 2021/10/05 19:49:20 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
//in_args.c//
void	add_args(t_element *element);
////////////////////
//env_ex.c//
void	env_ex(t_element *element);
int		search_marks(t_element *p_elem);
int		search_env(t_element *p_elem);
////////////////////
//env_ex2.c//
void	find_env(t_env *p_env);
////////////////////
//str_ex.c//
void	remove_marks(t_element *p_elem);
void	str_ex(t_element *element);
////////////////////
//expansion.c//
void	expand_all(t_element *element);
////////////////////
void	clean_element(t_element *element);
void	pre_procesing(t_element *element);
void	post_procesing(t_element *element);
void	ini_var(t_mark *mark);
void	check_close_mark(char *str, bool *mark_s, bool *mark_d, int *i);
void	check_open_mark(char *str, bool *mark_s, bool *mark_d, int *i);
int		check_fault_marks(char *str);
void	rutine_parse(char *str, t_element *elemnet);
void	main_parse(char *str, t_element *elemen);
void	copy_to_word(char *str, int *i, int *j, t_element *element);

#endif
