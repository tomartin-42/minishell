/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hered_expand_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:01:11 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/11 19:23:16 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	hered_no_expand_loop_else(int *h_fd, char *h_str)
{
	write (h_fd[1], h_str, ft_strlen(h_str));
	write (h_fd[1], "\n", 1);
	free(h_str);
}

void	hered_expand_loop_else(int *h_fd, char *h_str, t_env *env)
{
	h_str = expand_str(h_str, env);
	write (h_fd[1], h_str, ft_strlen(h_str));
	write (h_fd[1], "\n", 1);
	free(h_str);
}
