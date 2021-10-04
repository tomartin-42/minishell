/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:10:13 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/04 11:36:34 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Table of type char ==================================================
//cambiar env, anadir arg, empezar expandir
 * C = Comand--
 * P = Pipe
 * S = String
 * I = InputFile--
 * O = OutputFile--
 * T = Trunc--
 * H = HereDoc--
 * X = Delete Node
 * G = All line
 * F = File
 * A = Argument
 * E = ADD VAR
 * $ = CALL VAR
 * ======================================================================*/

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"

typedef struct s_env{
	char	*v_env;
	char	**var;	
	bool	global;
	bool	visible;
	bool	end;
	bool	del;
} t_env;

typedef struct s_element{
	char				*str;
	char				**arg;
	char				type;
	int					fd;
	struct s_element	*next;
	struct s_element	*prev;
}	t_element;

typedef struct s_plist{
	t_env		*p_env;
	t_element	*p_element;
}	t_plist;

extern t_plist	*g_plist;

t_element	*ft_lstlast(t_element *lst);
void		ft_lstadd_back(t_element **lst, t_element *new);
void		print_list(t_element *element);
void		ft_lst_del_all_x(t_element *elemnt);
int			ft_access(char *fname);
void		add_var_to_env(t_env *m_env, char *new_var);
void		free_old_env(t_env *m_env);
void		print_env(t_env *m_env);
char		**copy_env_to_double_pointer(t_env *m_env);

void		print_env(t_env *env);
#endif
