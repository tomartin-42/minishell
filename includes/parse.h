/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 20:50:17 by davyd11           #+#    #+#             */
/*   Updated: 2021/11/11 19:47:14 by dpuente-         ###   ########.fr       */
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
void		check_env(t_element *p_elem);
void		arg_token(t_element *p_elem);
void		sec_procesing(t_element *p_elem);
void		is_direct(t_element *element);
////////////////////
//in_args1.c//
void		add_args(t_element *element);
void		search_cmd_to_add_end(t_element *element, t_element *p_elem, int i);
void		search_cmd_to_add(t_element *element, t_element *p_elem, int i);
////////////////////
//copy_dell_args.c//
void		copy_arg_int_cmd(t_element *element);
void		dell_all_arg(t_element *element);
void		copy_arg_redir(t_element *element);
////////////////////
//in_args_memory.c//
void		init_memory_cmd(int *memory);
void		count_memory_need(int *mem_cmd, t_element *element);
void		reservate_memory(int *mem_cmd, t_element *element);
////////////////////
//env_ex.c//
void		env_ex(t_element *element, t_env *m_env);
int			search_marks(t_element *p_elem);
int			search_env(t_element *p_elem);
////////////////////
//env_ex2.c//
//void	special_cases(t_element *p_elem);
void		dollar_mark(t_element *p_elem);
//int		errno_dollar(char *str);
//void	insert_middle_str(t_element *p_elem, char	*str_in);
//void	find_env(t_env *p_env);
////////////////////
//str_ex.c//
void		remove_marks(t_element *p_elem);
void		str_ex(t_element *element);
////////////////////
//str_ex_utils.c//
void		remove_marks_loop(t_element *p_elem, int string_len, char mark);
////////////////////
//expansion.c//
void		expand_all(t_element *element, t_env *m_env, int option);
void		insert_list_str(t_element *p_elem, char *ret_expan);
////////////////////
//parse_utils.c//
void		clean_element(t_element *element);
void		change_heredoc(t_element *p_elem);
void		change_truck(t_element *p_elem);
void		get_string(t_element *element);
void		get_pipes_and_cmd_num(t_element *element);
////////////////////
//add_no_cmds.c//
void		add_no_cmds(t_element *p_elem, int size_arg);
////////////////////
//add_cmds.c//
void		add_cmds(t_element *p_elem, int size_arg);
////////////////////
//hered_expand_loop.c//
void		hered_no_expand_loop_else(int *h_fd, char *h_str);
void		hered_expand_loop_else(int *h_fd, char *h_str, t_env *env);
////////////////////
//main_hered.c//
char		*expand_str(char *str, t_env *env);
////////////////////
//parse_utils_2.c//
t_element	*add_do_nothing_node(void);
void		clean_spaces_in_str(t_element *element);
void		get_cmd_and_args(t_element *element);
void		get_hered_file(t_element *element);
void		get_trunk_file(t_element *element);
////////////////////
void		clean_element(t_element *element);
void		pre_procesing(t_element *element);
void		post_procesing(t_element *element);
void		ini_var(t_mark *mark);
void		check_close_mark(char *str, bool *mark_s, bool *mark_d, int *i);
void		check_open_mark(char *str, bool *mark_s, bool *mark_d, int *i);
int			check_fault_marks(char *str);
void		rutine_parse(char *str, t_element *element, t_env *m_env);
//void	rutine_parse(char *str, t_element *elemnet);
void		main_parse(char *str, t_element *elemen);
void		copy_to_word(char *str, int *i, int *j, t_element *element);

void		check_if_add_do_nothing(t_element *element);

#endif
