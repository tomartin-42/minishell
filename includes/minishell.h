/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:10:13 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/06 10:57:25 by dpuente-         ###   ########.fr       */
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
	char			*v_env;
	char			**var;	
	bool			global;
	bool			visible;
	struct s_env	*next;
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

t_element	*ft_lstlast(t_element *lst);
void		ft_lstadd_back(t_element **lst, t_element *new);
void		print_list(t_element *element);
void		ft_lst_del_all_x(t_element *elemnt);

int			ft_access(char *fname);
char		*expand_var(t_env *m_env, char *str);

void		init_env_list(t_env **m_env, char *var);
void		ft_lstadd_back_env(t_env **lst, t_env *new);
t_env		*new_env_node_global(t_env *new, char *var);
t_env		*new_env_node_local(t_env *new, char *var);
t_env		*ft_lstlast_env(t_env *lst);

char		*ft_expand(t_env *m_env, char *str);
#endif
