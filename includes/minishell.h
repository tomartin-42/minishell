/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:10:13 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/19 21:05:04 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"
#include "parse.h"

typedef struct s_element{
	char				*str;
	char				*arg;
	char				type;
	struct t_element	*next;
	struct t_element	*prev;
}	t_element;

void main_parse(char *str, t_element *element);
t_element		*ft_lstlast(t_element *lst);
void		ft_lstadd_back(t_element **lst, t_element *new);


#endif
