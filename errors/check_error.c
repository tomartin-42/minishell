/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:22:59 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/11 19:28:42 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "errorlib.h"

int	check_fault_marks(char *str)
{
	t_mark	chk;
	int		err;

	err = 0;
	ini_var(&chk);
	while (str[chk.i])
	{
		check_open_mark(str, &chk.mark_s, &chk.mark_d, &chk.i);
		chk.i++;
		check_close_mark(str, &chk.mark_s, &chk.mark_d, &chk.i);
	}
	if (chk.mark_s == true || chk.mark_d == true)
	{
		g_state = error_open_marks();
		err = 1;
	}
	return (err);
}

int	check_undefined_redir(char *str)
{
	bool	s_mark;
	bool	d_mark;
	bool	redir;
	int		i;

	s_mark = false;
	d_mark = false;
	redir = false;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"')
			d_mark = !d_mark;
		if (str[i] == 39)
			s_mark = !s_mark;
		if ((str[i] == '<' || str[i] == '>')
			&& (d_mark == false && s_mark == false))
			redir = true;
		if (!ft_strchr(" /t/><|", str[i]))
			redir = false;
		i++;
	}
	return (redir);
}

int	check_forbidden_chars(char *str)
{
	bool	s_mark;
	bool	d_mark;
	bool	answ;
	int		i;

	answ = true;
	s_mark = false;
	d_mark = false;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"')
			d_mark = !d_mark;
		if (str[i] == 39)
			s_mark = !s_mark;
		if (ft_strchr("#\\*();:,&!%", str[i])
			&& (s_mark == false && d_mark == false))
			answ = false;
		i++;
	}
	return (answ);
}
