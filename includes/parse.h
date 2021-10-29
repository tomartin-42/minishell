/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 20:50:17 by davyd11           #+#    #+#             */
/*   Updated: 2021/10/29 15:48:45 by dpuente-         ###   ########.fr       */
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
void	check_env(t_element *p_elem);
void	arg_token(t_element *p_elem);
void	sec_procesing(t_element *p_elem);
void	is_direct(t_element *element);
////////////////////
//in_args.c//
void	add_args(t_element *element);
int		count_args(t_element *p_elem);
void	arg_input(t_element *p_elem, int size_arg);
////////////////////
//env_ex.c//
void	env_ex(t_element *element, t_env *m_env);
int		search_marks(t_element *p_elem);
int		search_env(t_element *p_elem);
////////////////////
//env_ex2.c//
//void	special_cases(t_element *p_elem);
void	dollar_mark(t_element *p_elem);
//int		errno_dollar(char *str);
//void	insert_middle_str(t_element *p_elem, char	*str_in);
//void	find_env(t_env *p_env);
////////////////////
//str_ex.c//
void	remove_marks(t_element *p_elem);
void	str_ex(t_element *element);
////////////////////
//expansion.c//
void	expand_all(t_element *element, t_env *m_env, int option);
void	insert_list_str(t_element *p_elem, char *ret_expan);
////////////////////
//in_args_add_cmd.c//
void	yes_C_B(int size_arg, t_element	*p_elem);
////////////////////
void	clean_element(t_element *element);
void	pre_procesing(t_element *element);
void	post_procesing(t_element *element);
void	ini_var(t_mark *mark);
void	check_close_mark(char *str, bool *mark_s, bool *mark_d, int *i);
void	check_open_mark(char *str, bool *mark_s, bool *mark_d, int *i);
int		check_fault_marks(char *str);
void	rutine_parse(char *str, t_element *element, t_env *m_env);
//void	rutine_parse(char *str, t_element *elemnet);
void	main_parse(char *str, t_element *elemen);
void	copy_to_word(char *str, int *i, int *j, t_element *element);

#endif
