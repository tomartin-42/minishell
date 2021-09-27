/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:10:13 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/27 10:08:15 by tomartin         ###   ########.fr       */
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
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include "parse.h"

char	**g_env;

typedef struct s_element{
	char				*str;
	char				*arg;
	char				type;
	struct s_element	*next;
	struct s_element	*prev;
}	t_element;

void		rutine_parse(char *str, t_element *element);
t_element	*ft_lstlast(t_element *lst);
void		ft_lstadd_back(t_element **lst, t_element *new);
void		print_list(t_element *element);
void		ft_lst_del_all_x(t_element *elemnt);

typedef struct s_string
{
	char			*arg;
	struct s_string	*next;
	struct s_string	*prev;
}		t_string;

typedef struct s_input
{
	int			argc;
	char		*str;
	t_string	string;
}		t_input;
#endif
