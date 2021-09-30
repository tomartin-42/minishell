/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tommy <tommy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:10:13 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/30 08:56:28 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Table of type char ==================================================
 * C = Comand
 * P = Pipe
 * S = String
 * I = InputFile
 * O = OutputFile
 * T = Trunc
 * H = HereDoc
 * X = Delete Node
 * G = All line
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
	bool			global;
	struct s_env	*next;
	struct s_env	*prev;
} t_env;

typedef struct s_element{
	char				*str;
	char				**arg;
	char				type;
	int					fd;
	struct s_element	*next;
	struct s_element	*prev;
}	t_element;

typedef struct	s_plist{
	t_env		*p_env;
	t_element	*p_element;
}	t_plist;

t_element	*ft_lstlast(t_element *lst);
void		ft_lstadd_back(t_element **lst, t_element *new);
void		print_list(t_element *element);
void		ft_lst_del_all_x(t_element *elemnt);
int			ft_access(char *fname);
//void		init_env_list(t_env *m_env);
t_env		*ft_lstlast_env(t_env *lst);
void		ft_lstadd_back_env(t_env **env, t_env *new);
void		copy_env_to_list(t_env *m_env, char **env);
void		free_first_node_env(t_env *m_env);

void print_env(t_env *env);
#endif
